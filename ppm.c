#include "ppm.h"

struct ppm * ppm_read(const char * filename)
{
    FILE *ppm_file = fopen(filename, "rb");
    if (!ppm_file){error_exit("");}
}


void ppm_free(struct ppm *p)
{

}