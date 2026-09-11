static inline u32 read_cr0(void)
{
    u32 value;
    asm volatile ("mov %%cr0, %0" : "=r"(value));
    return value;
}

static inline void write_cr0(u32 value)
{
    asm volatile ("mov %0, %%cr0" :: "r"(value));
}

void fpu_init(void)
{
    u32 cr0 = read_cr0();

    cr0 &= ~(1 << 2); // CR0.EM = 0
    cr0 &= ~(1 << 3); // CR0.TS = 0
    cr0 |=  (1 << 1); // CR0.MP = 1

    write_cr0(cr0);

    asm volatile ("fninit");
}