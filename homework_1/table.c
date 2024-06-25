#include <stdio.h>

int main()
{
    printf("Name, Address, Data type, Scope, Value \n");
    printf("argc, 0x7ffd20e6f0cc, int, main, ??? \n");
    printf("argv, 0x7ffd20e6f0c0, char, main, ??? \n");
    printf("num1, 0x7ffd20e6f0ec, int, main, ??? \n");
    printf("num2, 0x7ffd20e6f0e8, int main, 5 \n");
    printf("c, 0x7ffd20e6f0e7, char, main, 'A' \n");
    printf("score1, 0x7ffd20e6f0e0, float, main, 25.5 \n");
    printf("ca[0], 0x7ffd20e6f0d0, char, main, 'H' \n");
    printf("ca[1], 0x7ffd20e6f0d1, char, main, 'i' \n");
    printf("ca[2], 0x7ffd20e6f0d2, char, main, '' \n");
    printf("x, 0x7ffd20e6f0ac, int, dummy, 0x7ffd20e6f0e8 \n");
    printf("y, 0x7ffd20e6f0a8, char, dummy, 0x7ffd20e6f0e7 \n");
    printf("z, 0x7ffd20e6f0a0, char, dummy, &ca \n");
    printf("w, 0x7ffd20e6f09c, float, dummy, 0x7ffd20e6f0e0 \n");
}
