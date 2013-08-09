
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "gdt.h"

struct gdt gdts[3];
extern struct gdtptr gdt_ptr;

void gdt_set(int index, uint16_t base, uint16_t limit, uint8_t access)	{
	
	gdts[index].limit = limit;
	gdts[index].base = base;
	gdts[index].base_low = base & 0x00FF;
	gdts[index].base_high = (base >> 8) & 0xFF;
	gdts[index].access = access;
	gdts[index].limit_flags = (limit >> 12) & 0xF;
	gdts[index].limit_flags |= 0x00;
	gdts[index].base_high = (base >> 8) & 0xFF;
}

void gdt_install()	{
	
	terminal_writestring("--------Init GDT--------\n");
	gdt_set(0,0,0,0);
	terminal_writestring("GDT Initialized with Null Pointer\n");
	gdt_set(1,0,0xFFFF,0x9A);
	terminal_writestring("GDT Appended with Code Segment\n");
	gdt_set(2,0,0xFFFF,0x92);
	terminal_writestring("GDT Appended with Data Segment\n");
	terminal_writestring("--------GDT Init GDT_SUCCESS--------\n");
}
