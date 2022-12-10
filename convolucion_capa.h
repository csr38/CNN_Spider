#ifndef _CONVOLUCION_CAPA
#define _CONVOLUCION_CAPA

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "matriz.h"
typedef struct kernel
{

    float **matriz;
}kernel;

typedef struct bias
{

    float **matriz;
}bias;


typedef struct conv_out
{
    float **matriz;

}conv_out;

typedef struct conv_op
{
    //zero-padding es la cantida de cero en las horrilas
    //para evitar modificar el mataño de la matriz
    int padding;
    //Cuantos espacio va corriendo la matriz
    int stride;
    //Cantidad de convoluciones (dimesiones convoluciones)
    int cant_kernel;
    //Kernel de convoluciones

    int tam_lado_kernel;

    float **matriz_temp_padding;
    int tam_matriz_temp;

    kernel *kernel_matriz;
    
    bias *bias_matriz;
    conv_out *result_conv;
    int tam_matriz_result;
}conv_op;

void convIniciar(conv_op *conv, int stride, int cant_kernel, int altura_imagen, int tam_lado_kernel);
void iniciarMatrizConv(conv_op *conv);
void vuelco_matriz_temporal(infoImagen *imagen, conv_op *conv);
void pasada_kernel(conv_op *conv);

#include "convolucion_capa.c"
#endif