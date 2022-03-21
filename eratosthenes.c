/*
*       erastothenes.c
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 13, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/

#include "eratosthenes.h"


void Eratosthenes(bitset_t *pole)
{   
    bitset_setbit(pole,0,1);
    bitset_setbit(pole,1,1);
    double limit = sqrt(bitset_size(pole));
    for(bitset_index_t i = 2; i <= limit;++i)
    {
        if(bitset_getbit(pole,i)==0)
        {
            for(bitset_index_t j = 2; i*j < bitset_size(pole); ++j)
                bitset_setbit(pole,i*j,1);
        }
    }
}

