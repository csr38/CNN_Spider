#ifndef _FLATTEN_CAPA
#define _FLATTEN_CAPA

#include "max_pooling.h"



typedef struct flatten_op
{

    unsigned int dim_flatten;
    float *matriz_flatten;
    
}flatten_op;

void iniciarFlatten(pool_op *pool, flatten_op *flat);

#include "flatten_capa.c"
#endif