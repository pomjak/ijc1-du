/*
*       IJC-1 
*       Author : Pomsar Jakub
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<assert.h>

#ifndef BITSET_H
#define BITSET_H
#define N 300000000

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
#ifdef USE_INLINE
#define 
static inline bitset_create(bitset_t jmeno_pole, bitset_index_t velikost)
{
    bitset_t jmeno_pole[((velikost/(sizeof(bitset_t) * CHAR_BIT)) + ((velikost % (sizeof(bitset_t) * CHAR_BIT)) > 0 ? 1 : 0) + 1)]={(unsigned long)velikost,0,};
    static_assert(velikost < N, "Spatne zadana velikost statickeho pole!!!\n");
}

#else
#define bitset_create(jmeno_pole,velikost)\
bitset_t jmeno_pole\
[((velikost/(sizeof(bitset_t) * CHAR_BIT))\
+\
((velikost % (sizeof(bitset_t) * CHAR_BIT)) > 0 ? 1 : 0) + 1)]={(unsigned long)velikost,0,};\
static_assert(velikost < N, "Spatne zadana velikost statickeho pole!!!\n");
#endif

/*
*    bitset_alloc(jmeno_pole,velikost)
*       definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem
*       vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
*       Př: bitset_alloc(q,100000L); // q = pole 100000 bitů, nulováno
*       Použijte  assert  pro kontrolu maximální možné velikosti pole.
*       Pokud alokace selže, ukončete program s chybovým hlášením:
*       "bitset_alloc: Chyba alokace paměti"
*/
#ifdef USE_INLINE
#define 
static inline bitset_alloc(bitset_t jmeno_pole, bitset_index_t velikost)
{
    bitset_t *jmeno_pole = (bitset_t*) calloc(((velikost / (sizeof(bitset_t) * CHAR_BIT))\
    +\
    ((velikost % (sizeof(bitset_t) * CHAR_BIT)) > 0 ? 1 : 0) + 1),sizeof(bitset_t));
    if(jmeno_pole == NULL)
    {   
        fprintf(stderr,"bitset_alloc: Chyba alokace pameti"); 
        exit(EXIT_FAILURE);
    }
    jmeno_pole[0] = velikost;
    static_assert(velikost < N, "Spatne zadana velikost statickeho pole!!!\n");
}

#else
#define bitset_alloc(jmeno_pole, velikost)\
bitset_t *jmeno_pole = (bitset_t*) calloc(\
((velikost / (sizeof(bitset_t) * CHAR_BIT))\
+\
((velikost % (sizeof(bitset_t) * CHAR_BIT)) > 0 ? 1 : 0) + 1),sizeof(bitset_t));\
if(jmeno_pole == NULL){fprintf(stderr,"bitset_alloc: Chyba alokace pameti"); exit(EXIT_FAILURE);}\
jmeno_pole[0] = velikost;\
static_assert(velikost < N, "Spatne zadana velikost statickeho pole!!!\n");
#endif

/*
*   bitset_free(jmeno_pole)
*       uvolní paměť dynamicky (bitset_alloc) alokovaného pole
*/
#ifdef USE_INLINE
#define
static inline bitset_free(bitset_t jmeno pole){free(jmeno_pole)}
#else
#define bitset_free(jmeno_pole) free(jmeno_pole)
#endif

/*
*    bitset_size(jmeno_pole)
*       vrátí deklarovanou velikost pole v bitech (uloženou v poli)
*/
#ifdef USE_INLINE
#define
static inline bitset_size(bitset_t jmeno_pole){return jmeno_pole[0];}
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
#define
static inline bitset_setbit (bitset_t jmeno_pole, int vyraz)
{
    if((unsigned long)index > bitset_size(jmeno_pole) - 1){exit(EXIT_FAILURE);}
    else if(vyraz) { jmeno_pole[1 + (index / sizeof(bitset_t))] |= (1UL << (index % sizeof(bitset_t))); }
    else { jmeno_pole[1 + (index / sizeof(bitset_t))] &= ~(1UL << (index % sizeof(bitset_t))); }
}
#else
#define bitset_setbit(jmeno_pole,index,vyraz)\
if((unsigned long)index > bitset_size(jmeno_pole) - 1){exit(EXIT_FAILURE);}\
else if(vyraz) { jmeno_pole[1 + (index / sizeof(bitset_t))] |= (1UL << (index % sizeof(bitset_t))); }\
else { jmeno_pole[1 + (index / sizeof(bitset_t))] &= ~(1UL << (index % sizeof(bitset_t))); }
#endif

/*
*    bitset_getbit(jmeno_pole,index)
*       získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
*       Př: if(bitset_getbit(p,i)==1) printf("1");
*           if(!bitset_getbit(p,i))   printf("0");
*/
#ifdef USE_INLINE
#define
static inline  bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
{
    (((unsigned long)index > (bitset_size(jmeno_pole) - 1))\
    ?\
    exit(EXIT_FAILURE), 0UL\
    :\
    ((jmeno_pole[1 + (index / (sizeof(bitset_t)*CHAR_BIT))]\
    &\
    (1UL << (index % (sizeof(bitset_t)*CHAR_BIT)))) > 0) ? 1UL : 0UL)
}
#else
#define bitset_getbit(jmeno_pole,index)\
(((unsigned long)index > (bitset_size(jmeno_pole) - 1))\
?\
exit(EXIT_FAILURE), 0UL\
:\
((jmeno_pole[1 + (index / (sizeof(bitset_t)*CHAR_BIT))]\
&\
(1UL << (index % (sizeof(bitset_t)*CHAR_BIT)))) > 0) ? 1UL : 0UL)
#endif
#endif