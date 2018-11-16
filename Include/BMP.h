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
#ifndef BMP_H
#define BMP_H

#include "utils.h"

/////////////////////////////////////////////////////////
//  Structure to headers bmp file                      //
//  __attribute__((__packed__)) to take data in block  //
/////////////////////////////////////////////////////////
typedef struct __attribute__((__packed__)){
	unsigned char signature1;
	unsigned char signature2;
	unsigned int size;
	unsigned short R1, R2;
	unsigned int  offset_header;
} BMP_FILE_HEADER;

typedef struct __attribute__((__packed__)){
	unsigned int header_Size;
	unsigned int width;
	unsigned int height;
	unsigned short plane, bitPerPixel;
	unsigned int compression;
	unsigned int imageSize;
	unsigned int Xresolution;
	unsigned int Yresolution;
	unsigned int colorTable;
	unsigned int importantColor;
	unsigned int redBitmark;
	unsigned int greenBitmark;
	unsigned int blueBitmark;
	unsigned int alphaBitmark;
	unsigned int colorSpaceType;
	unsigned int colorSpaceEndpoint;
	unsigned int gammaRed;
	unsigned int gammaGreen;
	unsigned int gammaBlue;
	unsigned int gammaAlpha;
} BMP_V5_HEADER;

//////////////////////
//  Pixel Struture  //
//////////////////////
typedef struct pixelRGB{
	unsigned char data[3];
} Pixel_RGB;

typedef struct pixelRGBA{
	unsigned char data[4];
} Pixel_RGBA;


void initFileHeader(BMP_FILE_HEADER* b);

void initHeader(BMP_V5_HEADER* b);

void initPixelRGB(Pixel_RGB* rgb);

void initPixelRGBA(Pixel_RGBA* rgba);

#endif