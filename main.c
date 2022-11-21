#include <stdio.h>
#include <stdlib.h>

#include "bmp_imagen.h"
#include "matriz.h"

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

int main(){
    bmpInfoHeader info; 
    bmpFileHeader file;
    infoImagen imagen;

    bmpInfoHeader info2; 
    bmpFileHeader file2;

    unsigned char *img;
    unsigned char *img2;

    

    img=LoadBMP("test.bmp", &info, &file);

    scala_gris(img, &file);

    matriz(&imagen, img, &info, &file, &info2, &file2);
    printf("pase\n");
    img2 = matrizImagen(&imagen);
    

    printf("%x", info2.height);

    //arreglar error en info y file 2
    SaveBMP("res3.bmp", &info2, &file2, img2);
    SaveBMP("res4.bmp", &info, &file, img);
    printf("listo\n");
    return 0;
}