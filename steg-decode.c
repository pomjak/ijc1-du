#include <stdio.h>
#include <stdlib.h>
#include "bitset.h"
#include "ppm.h"
#include "error.h"
#include "eratosthenes.h"

 int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        struct ppm *image = ppm_read(argv[1]);


        if(image == NULL)
        {
            error_exit("steg-decode: Chyba\n");
        }

        int size_of_image = (image->xsize * image->ysize * RGB);

        bitset_alloc(arr_eras,size_of_image); 

        Eratosthenes(arr_eras);
 
        char buffer = 0,offset = 0;
        int null_char_found = 0;
        for(int i = 29; i < size_of_image; i++)
        {
            
            if(!bitset_getbit(arr_eras,i))
            {

                if((image->data[i+1] & 1)) buffer |= (1 << offset);
        
                offset++;

                if(offset == CHAR_BIT) 
                {   
                    if(buffer == 0)
                    {
                        null_char_found = 1;
                        break;
                    }
                    else
                    {
                        offset = 0;
                        printf("%c",buffer);
                        buffer = 0;

                    }
                    
                }
            }
        }
        printf("\n");
        if(!null_char_found) error_exit("Nenalezen koncici znak\n");

        
        bitset_free(arr_eras);
        ppm_free(image);

    }
    else error_exit("steg-decode:Spatny pocet zadanych argumentu!\n");
    
    return 0;
}