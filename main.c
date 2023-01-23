#include <stdio.h>
#include <stdlib.h>

#include "bmp_imagen.h"
#include "matriz.h"

#include "convolucion_capa.h"

#include "max_pooling.h"

#include "flatten_capa.h"

#include "rnm_capa.h"

#include "softmax_capa.h"

unsigned int i;
unsigned int j;

unsigned char *matrizImagen(infoImagen *imagen){
    unsigned char *img2 = (unsigned char*)calloc(600*600*3, sizeof(unsigned char));
    int suma=0;
    for(i=0; i<600;i++){
        for(j=0; j<600;j++){

            
            img2[suma] = (imagen->matriz[i][j] * 255) / 100;
            suma++;
            img2[suma] = (imagen->matriz[i][j] * 255) / 100;
            suma++;
            img2[suma] = (imagen->matriz[i][j] * 255) / 100;
            suma++;

        }
       
    }


    return img2;
}

void testConvoluciones(infoImagen *imagen, conv_op *conv){
    FILE *marrt = fopen("matriz2.bmp", "wb+");
    for(i=0;i<600;i++){
      for(j=0;j<600;j++){
        fputc((float)conv->result_conv[1].matriz[i][j], marrt);
        
      }
    }
}

int main(){
    bmpInfoHeader info; 
    bmpFileHeader file;
    infoImagen imagen;

    bmpInfoHeader info2; 
    bmpFileHeader file2;

    conv_op conv_1;

    pool_op pool_1;

    flatten_op flat_1;

    rnm_op rnm_1;

    softmax_op softmax_1;

    unsigned char *img;
    unsigned char *img2;

    

    img=LoadBMP("test.bmp", &info, &file);

    scala_gris(img, &file);

    matriz(&imagen, img, &info, &file, &info2, &file2);

    convIniciar(&conv_1, 1, 5, imagen.tam_lado, 3);
    iniciarMatrizConv(&conv_1);
    vuelco_matriz_temporal(&imagen, &conv_1);

    pasada_kernel(&conv_1);

    testConvoluciones(&imagen, &conv_1);

    poolIniciar(&pool_1, &conv_1, 2);
    creacionMatrizPooling(&pool_1, &conv_1);
    operacionesMaxPooling(&pool_1, &conv_1);

    iniciarFlatten(&pool_1, &flat_1);

    iniciarRnm(&flat_1, &rnm_1);

    

    
    capaEntrada(&flat_1, &rnm_1);
    
    iniciarSoftmax(&rnm_1, &softmax_1);

    //img2 = matrizImagen(&imagen);
    //SaveBMP("res3.bmp", &info2, &file2, img2);
    //SaveBMP("res4.bmp", &info, &file, img);
    //printf("listo final\n");

    printf("\n");
    return 0;
}