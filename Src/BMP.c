/*
+-------------------------------------------------------+
|  Autor :                       Nebout Yann            |
|  Name of project :        Reading BMP File            |
|  Starting date :        12th november 2018            |
|  Date of last release : 18th november 2018            |
|                                                       |
|  File description :                                   |
|		- all functions to initialization of structure  |
+-------------------------------------------------------+
*/
#include "BMP.h"

void initFileHeader(BMP_FILE_HEADER* b){
	b->signature1 = "\0";
	b->signature2 = "\0";
	b->size = 0;
	b->R1 = 0;
	b->R2 = 0;
	b->offset_header = 0;
}

void initHeader(BMP_V5_HEADER* b){
	b->header_Size = 0;
	b->width = 0;
	b->height = 0;
	b->plane = 0;
	b->bitPerPixel = 0;
	b->compression = 0;
	b->imageSize = 0;
	b->Xresolution = 0;
	b->Yresolution = 0;
	b->colorTable = 0;
	b->importantColor = 0;
	b->redBitmark = 0;
	b->greenBitmark = 0;
	b->blueBitmark = 0;
	b->alphaBitmark = 0;
	b->colorSpaceType = 0;
	b->colorSpaceEndpoint = 0;
	b->gammaRed = 0;
	b->gammaGreen = 0;
	b->gammaBlue = 0;
	b->gammaAlpha = 0;
}


void initPixelRGB(Pixel_RGB* rgb){
	for (int i=0 ; i<3 ; i++)
		rgb->data[i] = '\0';
}

void initPixelRGBA(Pixel_RGBA* rgba){
	for (int i=0 ; i<4 ; i++)
		rgba->data[i] = '\0';
}