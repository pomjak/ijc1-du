#include "ppm.h"


struct ppm * ppm_read(const char * filename)
{
    unsigned int xsizetxt,ysizetxt;

    FILE *ppm_file = fopen(filename, "rb");
    if (!ppm_file){error_exit("ppm_read:Soubor nebyl nalezen\n");return NULL;}


    if(2 != fscanf(ppm_file,"P6 %u %u 255",&xsizetxt,&ysizetxt))
    {
        warning_msg("ppm_read:Chyba formatu\n");
        fclose(ppm_file);
        return NULL;
    }
        
    unsigned int size_of_image = xsizetxt * ysizetxt * RGB;
    
    if(size_of_image > MAX_SIZE)
    {
        fclose(ppm_file);
        error_exit("ppm_read:Soubor prilis velky\n");
        return NULL;
    } 

    struct ppm *image = malloc(sizeof(struct ppm) + size_of_image * (sizeof(char))); 

    if(image == NULL)
    {
        warning_msg("ppm_read:Alokace selhala\n");
        free(image);
        fclose(ppm_file);
        return NULL;
    }

    image->xsize = xsizetxt;
    image->ysize = ysizetxt;

    if(fread(image->data,(size_t)sizeof(char),(size_t)size_of_image,ppm_file) != size_of_image)
    {
        warning_msg("ppm_read:Chyba cteni dat\n");
        free(image);
        fclose(ppm_file);
        return NULL;
    }
    
    
    fclose(ppm_file);
    return image;   
}

void ppm_free(struct ppm *p)
{
    free(p);
}