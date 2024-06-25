#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    printf("1. The memory address of argc is: %p\n", (void*)&argc);
    printf("2. The memory address of argv is: %p\n", (void*)&argv);
    int num1, num2 = 55;
    printf("3. The memory address of num1 is: %p\n", (void*)&num1);
    printf("4. The memory address of num2 is: %p\n", (void*)&num2);
    char c = 'A';
    printf("5. The memory address of c is: %p\n", (void*)&c);
    float score1 = 25.5;
    printf("6. The memory address of score1 is: %p\n", (void*)&score1);
    char ca[3] = "Hi";
    printf("7. The memory address of ca 0 is: %p\n", (void*)&ca[0]);
    printf("8. The memory address of ca 1 is: %p\n", (void*)&ca[1]);
    printf("9. The memory address of ca 2 is: %p\n", (void*)&ca[2]);;

    dummy(num2, c, ca, score1);

    /* pause here */

    return 0;
}

void dummy(int x, char y, char * z, float w)
{
    x++;
    printf("10. The memory address of x is: %p\n",(void*)&x);
    y++;
    printf("11. The memory address of y is: %p\n",(void*)&y);
    printf("12. The memory address of z is: %p\n",(void*)&z);
    w = w + 5.1;

    printf("13. The memory address of w is: %p\n",(void*)&w);
}
