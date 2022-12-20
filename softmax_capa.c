#include "softmax_capa.h"
#include "rnm_capa.h"
#include <math.h>
float e = 2.718;

void iniciarSoftmax(rnm_op *rnm, softmax_op *softmax){
    
    softmax->matriz_result = (float*)calloc(rnm->fila_rnm , sizeof(float));
    softmax->matriz_entrada = (float*)calloc(rnm->fila_rnm, sizeof(float));
    float suma = 0.0;
    for(i = 0; i<rnm->fila_rnm; i++){
        softmax->matriz_entrada[i] = (float)pow(e ,rnm->matriz_result[i]);
        suma += softmax->matriz_entrada[i];

        printf("  %f  ", rnm->matriz_result[i]);
    }

    for(i = 0; i<rnm->fila_rnm; i++){
        softmax->matriz_result[i] = softmax->matriz_entrada[i] / suma;
    }

    for(i = 0; i<rnm->fila_rnm; i++){
   

        printf("  %f  ", softmax->matriz_result[i]);}
}