#include "bmp_imagen.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



unsigned char *LoadBMP(char *filename, bmpInfoHeader *bInfoHeader, bmpFileHeader *header){
    FILE *f;

    unsigned char *imgdata;
    uint16_t type;
    f=fopen (filename, "rb");
    /* handle open error */
    fread(&type, sizeof(uint16_t), 1, f);
    if (type !=0x4D42)
        {
        fclose(f);
        return NULL;
        }
    fread(header, sizeof(bmpFileHeader), 1, f);
    
    fread(bInfoHeader, sizeof(bmpInfoHeader), 1, f);


    //printf ("size: %d\n", header->size);
    //printf ("offs: %d\n", header->offset);
    /*bInfoHeader->imgsize=2339720;*/

    /*
    printf ("header size:      %d\n", bInfoHeader->headersize);
    printf ("image width:      %d\n", bInfoHeader->width);
    printf ("image height:     %d\n", bInfoHeader->height);
    printf ("colour planes:    %d\n", bInfoHeader->planes);
    printf ("bpp:              %d\n", bInfoHeader->bpp);
    printf ("compress:         %d\n", bInfoHeader->compress);
    printf ("imgage size:      %d\n", bInfoHeader->imgsize);
    printf ("bpmx:             %d\n", bInfoHeader->bpmx);
    printf ("bpmy:             %d\n", bInfoHeader->bpmy);
    printf ("colors:           %d\n", bInfoHeader->colors);
    printf ("important colors: %d\n", bInfoHeader->imxtcolors);
    */
    imgdata=(unsigned char*)malloc(header->size - header->offset);

    fseek(f, header->offset, SEEK_SET);
    //fseek(f, 54, SEEK_SET);
   
    printf("leido: %ld\n", fread(imgdata, header->size-header->offset,1, f));
    
    fclose(f);
    return imgdata;
}

void SaveBMP(char *filename, bmpInfoHeader *info, bmpFileHeader *file, unsigned char *imgdata){
    /*bmpFileHeader header;*/
    FILE *f;
    uint16_t type;


    f = fopen(filename, "wb+");
    type=0x4D42;
    fwrite(&type, sizeof(type), 1, f);

    fwrite(file, sizeof(bmpFileHeader), 1, f);

    fwrite(info, sizeof(bmpInfoHeader), 1, f);

    fwrite(imgdata, file->size-file->offset, 1, f);

    fclose(f);
}

void *scala_gris(unsigned char *imagen, bmpFileHeader *bFileHeader){
  int promedio;
  //PASAMOS LA IMAGEN A SCALA DE GRIS
  for(int i = 0; i <= (bFileHeader->size-bFileHeader->offset)/3; i++){
    promedio = imagen[i*3] + imagen[(i*3)+1] + imagen[(i*3)+2];
    promedio = promedio/3;

    for(int j = 0 ; j<3;j++){
      imagen[(i*3)+j] = promedio;
    }     
  }
  
}