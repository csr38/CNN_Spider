#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

typedef struct bmpFileHeader
{
  uint32_t size;
  uint16_t resv1;
  uint16_t resv2;
  uint32_t offset;
} bmpFileHeader;

typedef struct bmpInfoHeader
{
  uint32_t headersize;      /* DIB header size */
  uint32_t width;
  uint32_t height;
  uint16_t planes;         /* color planes */
  uint16_t bpp;            /* bits per pixel */
  uint32_t compress;
  uint32_t imgsize;    
  uint32_t bpmx;        /* X bits per meter */
  uint32_t bpmy;        /* Y bits per meter */
  uint32_t colors;      /* colors used */
  uint32_t imxtcolors;      /* important colors */
} bmpInfoHeader;

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
    printf ("size: %d\n", header->size);
    printf ("offs: %d\n", header->offset);
    fread(bInfoHeader, sizeof(bmpInfoHeader), 1, f);
    /*bInfoHeader->imgsize=2339720;*/
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
    imgdata=(unsigned char*)malloc(bInfoHeader->imgsize);
    fseek(f, 54, SEEK_SET);
   
    printf("leido: %ld\n", fread(imgdata, bInfoHeader->imgsize+84,1, f));
    printf("\n%s\n", f);
    
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

    fwrite(imgdata, info->imgsize+84, 1, f);

    fclose(f);
}

unsigned char *scala_gris(unsigned char *imagen,bmpInfoHeader *bInfoHeader, bmpFileHeader *header){

  
  
  return imagen;

}

int main(){
    bmpInfoHeader info; 
    bmpFileHeader file;
    unsigned char *img;
    unsigned char media;
    img=LoadBMP("test.bmp", &info, &file);
    

    SaveBMP("res3.bmp", &info, &file, img);
    return 0;
}