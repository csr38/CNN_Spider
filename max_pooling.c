#include "max_pooling.h"

void poolIniciar(pool_op *maxPooling, conv_op *conv, int tam_pool){

    maxPooling->cant_pool = conv->cant_kernel;
    maxPooling->tam_matriz_pool = tam_pool;
    maxPooling->dim_result = (int)(conv->tam_matriz_result/tam_pool);

    
    maxPooling->result_pool = (matriz_pool*)calloc(conv->cant_kernel ,sizeof(matriz_pool));
}

void creacionMatrizPooling(pool_op *maxPooling, conv_op *conv){
    for(int x=0; x < conv->cant_kernel; x++){
        maxPooling->result_pool[x].matriz = (float**)calloc(maxPooling->dim_result ,sizeof(float*));
        for(int i =0;i<maxPooling->dim_result;i++){
            maxPooling->result_pool[x].matriz[i] = (float*)calloc(maxPooling->dim_result ,sizeof(float));
        }
    }
}

void operacionesMaxPooling(pool_op *maxPooling, conv_op *conv){
    printf("%d\n",maxPooling->tam_matriz_pool);
    float valor_mayor = 0;
    for(int x=0; x < conv->cant_kernel; x++){
        for(int i =0;i<maxPooling->dim_result;i++){
            for(int j =0;j<maxPooling->dim_result;j++){
                valor_mayor=0;
                for(int h =0;h<maxPooling->tam_matriz_pool;h++){
                    for(int l =0;l<maxPooling->tam_matriz_pool;l++){
                        if((i+h)<= conv->tam_matriz_result &&(j+l)<=conv->tam_matriz_result){
                          
                            if(valor_mayor < conv->result_conv[x].matriz[(i*maxPooling->tam_matriz_pool)+h][(j*maxPooling->tam_matriz_pool)+l]){
                                valor_mayor = conv->result_conv[x].matriz[(i*maxPooling->tam_matriz_pool)+h][(j*maxPooling->tam_matriz_pool)+l];
                             
                            }
                        }
                    }
                }
                maxPooling->result_pool[x].matriz[i][j]=valor_mayor;
             
            }
        }
    }
}