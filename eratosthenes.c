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
    memset(pole+1,0x55,(bitset_size(pole)/CHAR_BIT));//prepsani vsech nasobku 2 (vcetne 0) pomoci memset
    bitset_setbit(pole,1,1);

    unsigned int limit = sqrt(bitset_size(pole));
    
    for(bitset_index_t i = 3; i <= limit;i+=2)
    {
        if(!bitset_getbit(pole,i))
        {
            for(bitset_index_t j = (i*i); j < bitset_size(pole); j+=(2*i))
                bitset_setbit(pole,j,1);
        }
    }
}

