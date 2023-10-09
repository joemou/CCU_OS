#include <stdio.h>

int main(int argc, char** argv) {
    unsigned long msr;
    asm volatile ( 
        "rdtsc\n\t"
        "shl $32, %%rdx\n\t"
        "or %%rdx, %0"
        : "=a" (msr)
        :
        : "rdx");

    printf("msr: %lx\n", msr);

    return 0;
}
