#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 0; i < 256; i++)
    {
        printf("%d / 64 = %d\n",i,(int)(i/64));
        printf("%d >> 6 = %d\n\n",i,i >> 6);
    }
    return 0;
}