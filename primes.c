#include "bitset.h"

int main(void)
{
    bitset_create(p,-5);
    //bitset_create(p,999);

    for(int i = 0 ; (unsigned long)i < bitset_size(p) ; i++)
    {
        printf("%ld",bitset_getbit(p,i));
    }
    for(int i = 0; (unsigned long)i < (bitset_size(p)/(sizeof(bitset_t)*CHAR_BIT)) +1;i++)
    {
        printf("number :%lu\n",p[i]);
    }
    printf("%lu",(bitset_size(p)/(sizeof(bitset_t)*CHAR_BIT)) +1);
    //bitset_free(p);
    return 0;
}
