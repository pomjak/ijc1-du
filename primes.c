/*
*       primes.c
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 11, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/

#include "error.h"
#include "eratosthenes.h"
#include "bitset.h"


int main(void)
{
    clock_t start = clock();
    bitset_alloc(p,N);

    int saved = 0;
    bitset_t pole[10] = {0,};

    Eratosthenes(p);

    for(bitset_index_t i = N - OFFSET;i > 2;--i)
    {
        if(!bitset_getbit(p,i))
        {
            pole[saved] = i;
            ++saved;
        }
        if(saved == 10)break;
    }

    for (int idx = 9; idx > -1; --idx)
        printf("%lu\n",pole[idx]);

    bitset_free(p);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
