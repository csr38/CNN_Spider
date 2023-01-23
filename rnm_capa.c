#include "rnm_capa.h"
#include "flatten_capa.h"
#include "matriz.h"

int mult = 1;

void iniciarRnm(flatten_op *flat, rnm_op *rnm){

    rnm->tam_bias =flat->dim_flatten *mult;
    rnm->bias = (float *)calloc(rnm->tam_bias , sizeof(float));

    
    rnm->col_rnm= flat->dim_flatten*mult;

    rnm->fila_rnm = 3;

    rnm->matriz_w = (float **)calloc(rnm->fila_rnm, sizeof(float));

    for(i=0; i<rnm->fila_rnm; i++){
        rnm->matriz_w[i] = (float *)calloc(rnm->col_rnm, sizeof(float));
    }


    rnm->matriz_result = (float*)calloc(rnm->fila_rnm,sizeof(float));
 
    for(i=0; i<rnm->fila_rnm ; i++){
        for(j=0; j<rnm->col_rnm; j++){
            rnm->matriz_w[i][j] = 1.0;


        }
    }

}


void capaEntrada(flatten_op *flat, rnm_op *rnm){
    unsigned int filas1 = 0;
    unsigned int filas2 = 0;
    unsigned int columnas1 = 0;
    unsigned int columnas2 = 0;
    float suma = 0.0;

    filas1 = rnm->fila_rnm;//3
    columnas1 = rnm->col_rnm;//99
    columnas2 = 1;//1

    for (i = 0; i < filas1; i++) {//se itera através de cada fila de matriz1
            for (j = 0; j < columnas2; j++) {//se itera através de cada columna de matriz2
                suma = 0;//es donde se almacenará el valor final 
                for (x = 0; x < columnas1; x++) {
                    suma += rnm->matriz_w[i][x] * flat->matriz_flatten[x]+rnm->bias[x];//se acumula en suma
                }
       
                //ReLu
                if(suma < 0){
                    suma = 0;
                }
                rnm->matriz_result[i] = suma;

                

                

                

            }
        }

   
    
}



