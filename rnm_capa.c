#include "rnm_capa.h"
#include "flatten_capa.h"

int i = 0;
int j = 0;

void iniciar_rnm(flatten_op *flat, rnm_op *rnm){
    rnm->bias = (float *)(flat->dim_flatten * size_t(float));
    rnm->tam_bias = flat->dim_flatten;

    rnm->columna_rnm = flat->dim_flatten;
    rnm->fila_rnm = flat->cant_flatten;

    rnm->matriz_w = (float **)(rnm->fila_rnm * size_t(float*));

    rnm->matriz_result = (float **)(rnm->fila_rnm * size_t(float*));
    for(i=0;i<flat->dim_flatten;i++){
        rnm->bias[i]=0;
    }

    for(i=0; i<rnm->fila_rnm ; i++){
        rnm->matriz_w[i]=(float*)(rnm->columna_rnm * size_t(float));
        rnm->matriz_result[i]=(float*)(rnm->columna_rnm * size_t(float));
        for(j=0; j<rnm->columna_rnm; j++){
            rnm->matriz_result[i][j]=0;
            rnm->matriz_w[i][j]=0;
            if(i==j){
                rnm->matriz_w[i][j]=1;
            }
        }
    }
}