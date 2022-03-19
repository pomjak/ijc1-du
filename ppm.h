#include <stdio.h>
#include <stdlib.h>
#include "bitset.h"
#include "error.h"
#include <limits.h>

#ifndef PPM_H
#define PPM_H

#define RGB 3
#define MAX_SIZE (8000*8000*RGB)
#define SIZE_OF_IMAGE (image->xsize * image->ysize * RGB)

struct ppm 
{
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
/*
* načte obsah PPM souboru do touto funkcí dynamicky
*        alokované struktury. Při chybě formátu použije funkci warning_msg
*        a vrátí NULL.  Pozor na "memory leaks".
*/
void ppm_free(struct ppm *p);
/*
*   uvolní paměť dynamicky alokovanou v ppm_read
*/
#endif