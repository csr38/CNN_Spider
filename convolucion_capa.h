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
    int tam_matiz;

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
}conv_op;

void convIniciar(conv_op *conv, int stride, int cant_kernel, int altura_imagen, int tam_lado_kernel);
void iniciarMatrizConv(conv_op *conv, infoImagen *imagen);
void vuelco_matriz_temporal(infoImagen *imagen, conv_op *conv);
void pasada_kernel(conv_op *conv, infoImagen *imagen);

#include "convolucion_capa.c"
#endif