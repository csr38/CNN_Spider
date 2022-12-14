#ifndef _MAX_POOLING
#define _MAX_POOLING

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "matriz.h"
#include "convolucion_capa.h"

typedef struct matriz_pool
{
    float **matriz;
}matriz_pool;


typedef struct pool_op
{
    int dim_result;
    int cant_pool;
    int tam_matriz_pool;
    matriz_pool *result_pool;
}pool_op;


void poolIniciar(pool_op *maxPooling, conv_op *conv, int tam_pool);
void creacionMatrizPooling(pool_op *maxPooling, conv_op *conv);
void operacionesMaxPooling(pool_op *maxPooling, conv_op *conv);

#include "max_pooling.c"
#endif