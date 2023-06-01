#ifndef VOLI_IDT_H
#define VOLI_IDT_H

// IDT-related code goes here
typedef struct idt_entry_t {
    // your structure members here
} __attribute__((packed)) idt_entry_t;

typedef struct idtr_t {
    uint16_t size;
    uint64_t base;
} __attribute__((packed)) idtr_t;

void init_idt();  // add this line

#endif //VOLI_IDT_H
