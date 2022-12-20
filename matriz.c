#include "matriz.h"
#include "bmp_imagen.h"

unsigned int i;
unsigned int j;

void **matriz(infoImagen *imagen, unsigned char *img, bmpInfoHeader *bInfoHeader, bmpFileHeader *bFileHeader, bmpInfoHeader *info2, bmpFileHeader *file2){

  if(bInfoHeader->height > bInfoHeader->width){
    imagen->tam_lado=(int)bInfoHeader->height;
  }else{
    imagen->tam_lado = (int)bInfoHeader->width;
  }


    imagen->matriz = (unsigned int**)calloc(imagen->tam_lado,sizeof(int *));
    
    for(i = 0; i < imagen->tam_lado; i++){
      imagen->matriz[i]=(unsigned int *)calloc((imagen->tam_lado),sizeof(int));
    }

  file2->size=imagen->tam_lado*imagen->tam_lado*3+bFileHeader->offset;
  file2->resv1 = bFileHeader->resv1;
  file2->resv2 = bFileHeader->resv2;
  file2->offset=bFileHeader->offset;

  info2->bpmx = bInfoHeader->bpmx;
  info2->bpmy = bInfoHeader->bpmy;
  info2->bpp = bInfoHeader->bpp;
  info2->colors = bInfoHeader->colors;
  info2->compress = bInfoHeader->compress;
  info2->imxtcolors = bInfoHeader->imxtcolors;
  
  
  info2->headersize = bInfoHeader->headersize;
  
  info2->width= imagen->tam_lado;
  info2->height=imagen->tam_lado;
  info2->planes=bInfoHeader->planes;
  info2->bpp = bInfoHeader->bpp;
    
  
    int suma = 0;

    FILE *marrt = fopen("matriz.bmp", "wb+");

    unsigned int inicio_1= (imagen->tam_lado-bInfoHeader->height)/2;
    unsigned int inicio_2= (imagen->tam_lado-bInfoHeader->width)/2;


    for(i=0; i<bInfoHeader->height;i++){
      for(j=0; j< bInfoHeader->width;j++){
        imagen->matriz[i+inicio_1][j+inicio_2] = ((int)img[suma*3]*100)/255;
        suma++;
      }
    }
    

    for(i=0;i<600;i++){
      for(j=0;j<600;j++){
        fputc((int)imagen->matriz[i][j], marrt);
        
      }
    }
    fclose(marrt);
}

