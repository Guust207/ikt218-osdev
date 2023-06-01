
#include "idt.h"  // remember to include the header file

static idt_entry_t idt[256];  // The IDT itself
static idtr_t idtr;  // IDT register


void idt_set_entry(uint16_t n, uint64_t handler) {
    idt[n].isr_low = (uint16_t)handler;
    idt[n].isr_mid = (uint16_t)(handler >> 16);
    idt[n].isr_hig = (uint32_t)(handler >> 32);
    idt[n].kernel_cs = 0x08;  // Kernel code segment
    idt[n].attributes = (1 << 7) | (1 << 5) | 0xE;  // Flags
}

void init_idt() {
    idtr.base = (uint64_t)&idt;
    idtr.size = 256 * sizeof(idt_entry_t) - 1;
    asm("lidt %0"
        :
        : "m"(idtr)
    );
}

