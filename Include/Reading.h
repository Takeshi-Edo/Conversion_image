/*
+---------------------------------------------+
|  Autor :                       Nebout Yann  |
|  Name of project :        Reading BMP File  |
|  Starting date :        12th november 2018  |
|  Date of last release : 18th november 2018  |
|                                             |
|  File description :                         |
|		- reading information of file         |
|		- save the data of image              |
+---------------------------------------------+
*/
#ifndef READING_H
#define READING_H

#include "BMP.h"

/*
+--------------------------------------------------------------------+
|  Function description :                                            |
|		- Read the header file and return the size of V5 header      |
|		Inputs :                                                     |
|			- bmpFile(char*) : file name                             |
|			- b(BMP_FILE_HEADER* ) : Structure to stock header file  |
|		Output :                                                     |
|			- size of V5 header                                      |
+--------------------------------------------------------------------+
*/
int headerSize(char* bmpFile, BMP_FILE_HEADER* b);

/*
+---------------------------------------------------------------------+
|  Function description :                                             |
|		- Read the V5 header file                                     |
|		Inputs :                                                      |
|			- bmpFile(char*) : file name                              |
|			- b(BMP_V5_HEADER* ) : Structure to stock V5 header file  |
|			- size(int) : size of V5 header                           |
+---------------------------------------------------------------------+
*/
void headerBMP(char* bmpFile, BMP_V5_HEADER* b, int size);

/*
+--------------------------------------------------------------------------+
|  Function description :                                                  |
|		- Reinitialize data of V5 header if its size is equal of 40 bytes  |
|		Inputs :                                                           |
|			- b(BMP_V5_HEADER* ) : Structure to stock V5 header file       |
+--------------------------------------------------------------------------+
*/
void headerBMPmin(BMP_V5_HEADER* b);

/*
+--------------------------------------------------------------------+
|  Function description :                                            |
|		- Read and save RGB pixel data in array                      |
|		Inputs :                                                     |
|			- bmpFile(char*) : file name                             |
|			- offset(int) : number of bytes before first data array  |
|			- rows(int) : number of rows of data arrays              |
|			- clos(int) : number of columns of data arrays           |
|			- rgb(PixelRGB) : array of pixels                        |
+--------------------------------------------------------------------+
*/
void getDataRGB(char* bmpFile, int offset, int rows, int cols, Pixel_RGB rgb[rows][cols]);

/*
+--------------------------------------------------------------------+
|  Function description :                                            |
|		- Read and save RGBA pixel data in array                     |
|		Inputs :                                                     |
|			- bmpFile(char*) : file name                             |
|			- offset(int) : number of bytes before first data array  |
|			- rows(int) : number of rows of data arrays              |
|			- clos(int) : number of columns of data arrays           |
|			- rgba(PixelRGBA) : array of pixels                      |
+--------------------------------------------------------------------+
*/
void getDataRGBA(char* bmpFile, int offset, int rows, int cols, Pixel_RGBA rgba[rows][cols]);

#endif