#include "flatten_capa.h"
#include "max_pooling.h"
#include "convolucion_capa.h"
unsigned int x = 0;
unsigned int posicion = 0;

void iniciarFlatten(pool_op *pool, flatten_op *flat){

    flat->dim_flatten = pool->dim_result*pool->dim_result*pool->cant_pool;

    
    flat->matriz_flatten = (float*)calloc(flat->dim_flatten, sizeof(float));
    
    for(i=0; i<pool->cant_pool; i++){
        for(j=0; j<pool->dim_result; j++){
            for(x=0; x<pool->dim_result; x++){
                flat->matriz_flatten[posicion] = pool->result_pool[i].matriz[j][x];
                posicion++;

            }
        }
    }
}