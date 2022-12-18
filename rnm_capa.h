#ifndef _RNM_CAPA
#define _RNM_CAPA





typedef struct rnm_op
{
    int tam_bias;

    float *bias;
    int columna_rnm;
    int fila_rnm;
    float **matriz_w;

    float **matriz_result;
    
}rnm_op;


#include "rnm_capa.c"
#endif