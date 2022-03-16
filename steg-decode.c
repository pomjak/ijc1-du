#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "error.h"
#include "eratosthenes.h"

 int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        FILE *ppm_file = fopen(argv[1], "rb");
        if (!ppm_file){error_exit("steg-decode:Soubor nebyl nalezen\n");}
        struct ppm *image = ppm_read(ppm_file); 
    }
    else error_exit("steg-decode:Malo zadanych argumentu!\n");
    return 0;
}