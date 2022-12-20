#ifndef _SOFTMAX_CAPA
#define _SOFTMAX_CAPA

typedef struct softmax_op
{
    int tam_softmax;
    float *matriz_entrada;
    float *matriz_result;
    
}softmax_op;


#include "softmax_capa.c"
#endif