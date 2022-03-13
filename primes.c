/*
*       primes.c
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/
#include "bitset.h"
#include "error.h"
#include "error.c"

int main(void)
{
    //bitset_create(p,5);
    //bitset_create(p,999);

    /*for(int i = 0 ; (unsigned long)i < bitset_size(p) ; i++)
    {
        printf("%ld",bitset_getbit(p,i));
    }
    for(int i = 0; (unsigned long)i < (bitset_size(p)/(sizeof(bitset_t)*CHAR_BIT)) +1;i++)
    {
        printf("number :%lu\n",p[i]);
    }
    printf("%lu",(bitset_size(p)/(sizeof(bitset_t)*CHAR_BIT)) +1);*/
    warning_msg("ahoj");
    //error_exit("Bye");
    //bitset_free(p);
    return 0;
}
