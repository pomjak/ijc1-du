 /*
*       bitset.c
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/

#include<stdio.h>
#include"bitset.h"

#ifdef USE_INLINE

    extern inline void bitset_free(bitset_t *jmeno_pole);
    extern inline bitset_t bitset_size(bitset_t *jmeno_pole);
    extern inline void bitset_setbit (bitset_t *jmeno_pole,bitset_index_t index, int vyraz);
    extern inline bitset_t bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index);

#endif