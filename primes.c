#include "bitset.h"

int main()
{
    bitset_create(p,100);
    bitset_alloc(q,100);
    printf("%ld\n",bitset_size(p));
    bitset_setbit(p,65,1);
    bitset_free(q);
    return EXIT_SUCCESS;
}