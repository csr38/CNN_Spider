#include "flatten_capa.h"
#include "max_pooling.h"

unsigned int i = 0;
unsigned int j = 0;
unsigned int x = 0;
unsigned int posicion = 0;

void iniciar_flatten(pool_op *pool, flatten_op *flat){
    flat->cant_flatten = pool->cant_pool;
    flat->dim_flatten = pool->dim_result*pool->dim_result;

    
    flat->matriz_flatten = (float**)malloc(flat->cant_flatten * sizeof(float*));
    
    for(x = 0; x< flat->cant_flatten ;x++){
        posicion = 0;
        flat->matriz_flatten[x] = (float *)malloc( flat->dim_flatten * sizeof(float));
        
        for(i=0; i< pool->dim_result; i++){
            for(j =0; j<pool->dim_result; j++){
                flat->matriz_flatten[x][posicion] = pool->result_pool[x].matriz[i][j];
                posicion++;
            }
        }
    }
}