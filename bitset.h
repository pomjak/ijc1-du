/*
*       bitset.h
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<assert.h>
#include<time.h>
#include "error.h"


#ifndef BITSET_H
#define BITSET_H
#define N 300000000
#define OFFSET 1 //vyhledem k 1. prvku kde je ulozena velikost
#define BITSET_BIT (sizeof(bitset_t) * CHAR_BIT)


typedef unsigned long bitset_t;
// Typ bitového pole (pro předávání parametru do funkce odkazem).
typedef unsigned long bitset_index_t;
//Typ indexu do bitového pole.


/*  
*   bitset_create(jmeno_pole,velikost)
*    definuje a _nuluje_ proměnnou jmeno_pole
*       (POZOR: opravdu musí _INICIALIZOVAT_ pole bez ohledu na
*       to, zda je pole statické nebo automatické/lokální!
*       Vyzkoušejte obě varianty, v programu použijte lokální pole.)
*       Použijte  static_assert  pro kontrolu velikosti pole.
*       Př: static bitset_create(p,100); // p = pole 100 bitů, nulováno
*           bitset_create(q,100000L);    // q = pole 100000 bitů, nulováno
*           bitset_create(q,-100);       // chyba při překladu
*/

#define bitset_create(jmeno_pole,velikost)\
bitset_t jmeno_pole\
[((velikost/BITSET_BIT)\
+\
((velikost % BITSET_BIT) > 0 ? 1 : 0) + OFFSET)]={velikost,0,};\
static_assert(velikost <= N, "Spatne zadana velikost statickeho pole!!!\n");


/*
*    bitset_alloc(jmeno_pole,velikost)
*       definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem
*       vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
*       Př: bitset_alloc(q,100000L); // q = pole 100000 bitů, nulováno
*       Použijte  assert  pro kontrolu maximální možné velikosti pole.
*       Pokud alokace selže, ukončete program s chybovým hlášením:
*       "bitset_alloc: Chyba alokace paměti"
*/

#define bitset_alloc(jmeno_pole, velikost)\
bitset_t *jmeno_pole = (bitset_t*) calloc(\
((velikost/BITSET_BIT)\
+\
((velikost % BITSET_BIT) > 0 ? 1 : 0) + OFFSET),sizeof(bitset_t));\
if(jmeno_pole == NULL){error_exit("bitset_alloc: Chyba alokace paměti");}\
jmeno_pole[0] = velikost;\
assert(velikost <= N);


/*
*   bitset_free(jmeno_pole)
*       uvolní paměť dynamicky (bitset_alloc) alokovaného pole
*/
#ifdef USE_INLINE
 inline void bitset_free(bitset_t *jmeno_pole){free(jmeno_pole);}
#else
#define bitset_free(jmeno_pole) free(jmeno_pole)
#endif

/*
*    bitset_size(jmeno_pole)
*       vrátí deklarovanou velikost pole v bitech (uloženou v poli)
*/
#ifdef USE_INLINE
 inline bitset_t bitset_size(bitset_t *jmeno_pole){return jmeno_pole[0];}
#else
#define bitset_size(jmeno_pole) jmeno_pole[0]
#endif

/*
*bitset_setbit(jmeno_pole,index,výraz)
*       nastaví zadaný bit v poli na hodnotu zadanou výrazem
*       (nulový výraz == bit 0, nenulový výraz == bit 1)
*       Př: bitset_setbit(p,20,1);
*/
#ifdef USE_INLINE
 inline void bitset_setbit (bitset_t *jmeno_pole,bitset_index_t index, int vyraz)
{
    if(index > bitset_size(jmeno_pole) - OFFSET)
    {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",\
        (bitset_t)index, bitset_size(jmeno_pole)-OFFSET);
    }
    else if(vyraz) 
    {
        jmeno_pole[(OFFSET + (index/BITSET_BIT))] |= (1UL << (index % BITSET_BIT));
        
    }
    else 
    {
        
        jmeno_pole[OFFSET + (index/BITSET_BIT)] &= ~(1UL << (index % BITSET_BIT));
    }
}
#else
#define bitset_setbit(jmeno_pole,index,vyraz)\
if((bitset_t)index > bitset_size(jmeno_pole) - OFFSET){error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",\
(bitset_t)index, bitset_size(jmeno_pole)-OFFSET);}\
else if(vyraz) { jmeno_pole[OFFSET + (index/BITSET_BIT)] |= (1UL << (index % BITSET_BIT)); }\
else { jmeno_pole[OFFSET + (index/BITSET_BIT)] &= ~(1UL << (index % BITSET_BIT)); }
#endif

/*
*    bitset_getbit(jmeno_pole,index)
*       získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
*       Př: if(bitset_getbit(p,i)==1) printf("1");
*           if(!bitset_getbit(p,i))   printf("0");
*/
#ifdef USE_INLINE
 inline bitset_t bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index)
{
    return (((bitset_t)index > (bitset_size(jmeno_pole) - OFFSET))\
    ?\
    error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",\
    (bitset_t)index, bitset_size(jmeno_pole)),0UL\
    :\
    ((jmeno_pole[OFFSET + (index/BITSET_BIT)]\
    &\
    (1UL << (index % BITSET_BIT))) > 0) ? 1UL : 0UL);
}
#else
#define bitset_getbit(jmeno_pole,index)\
(((bitset_t)index > (bitset_size(jmeno_pole) - 1))\
?\
error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",\
(bitset_t)index, bitset_size(jmeno_pole)), 0UL\
:\
((jmeno_pole[1 + ((bitset_t)index/BITSET_BIT)]\
&\
(1UL << (index % BITSET_BIT))) > 0) ? 1UL : 0UL)
#endif
#endif