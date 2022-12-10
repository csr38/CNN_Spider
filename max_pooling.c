#include "max_pooling.h"

void poolIniciar(pool_op *maxPooling, conv_op *conv, int tam_pool){
    maxPooling->cant_pool = conv->cant_kernel;
    maxPooling->tam_matriz_pool = tam_pool;
    maxPooling->dim_result = (int)(conv->tam_matriz_result/tam_pool);
    

}