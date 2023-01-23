#ifndef _MATRIZ
#define _MATRIZ

#include "bmp_imagen.h"

typedef struct infoImagen{
  unsigned char *header; //Contiene la informacion de la imagen, para cuando lo quiera reconstituir
  double **matriz;//Contiene la imgen en forma de matriz
  unsigned short int tam_lado; //al importar una imagen cuadrada solo tomo uno de los valores
  unsigned short int dimensiones; //Contiene la multiplicacion de las matrices con las filas
}infoImagen;



void **matriz(infoImagen *imagen, unsigned char *img, bmpInfoHeader *bInfoHeader, bmpFileHeader *bFileHeader, bmpInfoHeader *info2, bmpFileHeader *file2);

#include "matriz.c"
#endif