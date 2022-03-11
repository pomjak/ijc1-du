#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<assert.h>

int main()
{
    printf("ul %ldB = %ldb\nbit %d\n",sizeof(unsigned long), sizeof(unsigned long) * CHAR_BIT, CHAR_BIT);
    static_assert(CHAR_BIT >= 8,"dobre");
    //static_assert(CHAR_BIT < 8,"CHAR neni z 8b");
    return EXIT_SUCCESS;
}