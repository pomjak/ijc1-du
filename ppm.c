#include "ppm.h"

struct ppm 
{
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};


struct ppm * ppm_read(const char * filename)
{
    char buffer[99];
    //fscanf(filename,buffer)
    return 0;   
}


void ppm_free(struct ppm *p)
{

}