#ifndef _RNM_CAPA
#define _RNM_CAPA





typedef struct rnm_op
{
    int tam_bias;

    float *bias;
    unsigned int fila_rnm;
    unsigned int col_rnm;
    float **matriz_w;
    float *matriz_result;
    
}rnm_op;

void iniciarRnm(flatten_op *flat, rnm_op *rnm);
void capaEntrada(flatten_op *flat, rnm_op *rnm);


#include "rnm_capa.c"
#endif