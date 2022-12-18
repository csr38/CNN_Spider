#include <stdio.h>
#include <stdlib.h>

#include "bmp_imagen.h"
#include "matriz.h"

#include "convolucion_capa.h"

#include "max_pooling.h"

unsigned int i;
unsigned int j;

unsigned char *matrizImagen(infoImagen *imagen){
    unsigned char *img2 = (unsigned char*)malloc(600*600*3);
    for(i=0; i<600*600*3;i++){
        img2[i]=0;
    }
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

    unsigned char *img;
    unsigned char *img2;

    

    img=LoadBMP("test.bmp", &info, &file);

    scala_gris(img, &file);

    matriz(&imagen, img, &info, &file, &info2, &file2);
    printf("pase\n");
    
    
    convIniciar(&conv_1, 1, 5, imagen.tam_lado, 3);
    iniciarMatrizConv(&conv_1);
    vuelco_matriz_temporal(&imagen, &conv_1);

    pasada_kernel(&conv_1);

    testConvoluciones(&imagen, &conv_1);

    poolIniciar(&pool_1, &conv_1, 2);
    creacionMatrizPooling(&pool_1, &conv_1);
    operacionesMaxPooling(&pool_1, &conv_1);

    for(i=0;i<600;i++){
      for(j=0;j<600;j++){
        imagen.matriz[i][j] = (int)conv_1.result_conv[1].matriz[i][j];
        
      }
    }
    
    img2 = matrizImagen(&imagen);
    SaveBMP("res3.bmp", &info2, &file2, img2);
    SaveBMP("res4.bmp", &info, &file, img);
    printf("listo final\n");


    return 0;
}