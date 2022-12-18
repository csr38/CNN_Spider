#include "flatten_capa.h"
#include "max_pooling.h"

unsigned int i = 0;
unsigned int j = 0;
unsigned int x = 0;
unsigned int posicion = 0;

void iniciar_flatten(pool_op *pool, flatten_op *flat){
    flat->tam_flatten = pool->cant_pool*pool->dim_result;

    flat->arreglo_flatten = (float*)malloc(flat->tam_flatten *sizeof(float));
    posicion = 0;

    for(x = 0; x< pool->cant_pool ;x++){
        for(i=0; i< pool->dim_result; i++){
            for(j =0; j<pool->dim_result; j++){
                flat->arreglo_flatten[posicion] = pool->result_pool[x].matriz[i][j];
                posicion++;
            }
        }
    }
}