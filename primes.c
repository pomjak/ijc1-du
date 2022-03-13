/*
*       primes.c
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/
#include "error.h"
#include "error.c"
#include "bitset.h"

int main(void)
{
    bitset_create(p,2048);
    //bitset_create(p,999);
            
    for(int i = 0 ; (unsigned long)i < bitset_size(p) ; i++)
        bitset_setbit(p,i,1);
    for(int i = 0 ; (unsigned long)i < bitset_size(p) ; i++)
    {
        printf("%ld",bitset_getbit(p,i)); 
    }


    //bitset_free(p);

    return 0;
}
