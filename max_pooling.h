#ifndef _MAX_POOLING
#define _MAX_POOLING

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "matriz.h"
#include "convolucion_capa.h"

typedef struct pool_op
{
    int dim_result;
    int cant_pool;
    int tam_matriz_interior;
    float *result_pool;
}pool_op;



#include "max_pooling.c"
#endif