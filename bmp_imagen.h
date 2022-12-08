#ifndef _BMP_IMAGEN
#define _BMP_IMAGEN

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



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

unsigned char *LoadBMP(char *filename, bmpInfoHeader *bInfoHeader, bmpFileHeader *header);
void SaveBMP(char *filename, bmpInfoHeader *info, bmpFileHeader *file, unsigned char *imgdata);
void *scala_gris(unsigned char *imagen, bmpFileHeader *bFileHeader);

#include "bmp_imagen.c"
#endif