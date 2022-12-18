#ifndef _FLATTEN_CAPA
#define _FLATTEN_CAPA





typedef struct flatten_op
{
    int cant_flatten;
    int dim_flatten;
    float **matriz_flatten;
    
}flatten_op;

void iniciar_flatten(pool_op *pool, flatten_op *flat);

#include "flaten_capa.c"
#endif