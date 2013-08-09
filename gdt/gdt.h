
#ifndef _GDT_H
#define _GDT_H

struct gdt {
	uint16_t limit;
	uint16_t base;	
	uint8_t base_low;
	uint8_t access;
	uint8_t limit_flags;	
	uint8_t base_high;
};

struct gdtptr {
	uint16_t limit;
	uint16_t base;
};

void gdt_set(int index, uint16_t base, uint16_t limit, uint8_t access); //access 0x9A for Code 0x92 for Data
void gdt_install();

#endif /* _GDT_H */
