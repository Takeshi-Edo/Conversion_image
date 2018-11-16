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
#include "Reading.h"

int headerSize(char* bmpFile, BMP_FILE_HEADER* b){
	FILE* bmp = NULL;
	bmp = fopen(bmpFile,"r");
	if (bmp!=NULL){
		fread(b, sizeof(char), sizeof(*b), bmp);
		fclose(bmp);
	}

	// Calculation of V5 Header size.
	int size = 0;
	size = b->size-b->offset_header;
	return b->size - (size+14);
}

void headerBMP(char* bmpFile, BMP_V5_HEADER* b, int size){
	FILE* bmp = NULL;
	bmp = fopen(bmpFile,"r");
	if (bmp!=NULL){
		fseek(bmp,BMPHEADER_SIZE,SEEK_SET);		//  We place cursor in the characters number BMPHEADER_SIZE 
		fread(b, sizeof(char), sizeof(*b) , bmp);
		fclose(bmp);
	}

	if (size==BMPHEADER_MIN_SIZE){	//	If the data are stored in 3 bytes
		headerBMPmin(b);
	}
}

void headerBMPmin(BMP_V5_HEADER* b){
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

void getDataRGB(char* bmpFile, int offset, int rows, int cols, Pixel_RGB rgb[rows][cols]){
	unsigned short padding;
	Pixel_RGB rgb_data;
	initPixelRGB(&rgb_data);

	FILE* bmp = NULL;
	bmp = fopen(bmpFile,"r");
	if (bmp!=NULL){
		fseek(bmp,offset,SEEK_SET);
		for (int i=rows-1 ; i>-1 ; i--){
			for (int j=0 ; j<cols ; j++){
				fread(&rgb_data, sizeof(char), sizeof(rgb_data) , bmp);
				rgb[i][j] = rgb_data;	// We copy data in array
			}
			fread(&padding, sizeof(char), sizeof(padding), bmp); //	 We read padding because you don't want this value
		}
		fclose(bmp);
	}
}

//	This function is same that previous but padding size is 4 bytes and pixel size is 4 bytes
void getDataRGBA(char* bmpFile, int offset, int rows, int cols, Pixel_RGBA rgba[rows][cols]){
	unsigned int padding;
	Pixel_RGBA rgba_data;
	initPixelRGBA(&rgba_data);

	FILE* bmp = NULL;
	bmp = fopen(bmpFile,"r");
	if (bmp!=NULL){
		fseek(bmp,offset,SEEK_SET);
		for (int i=rows-1 ; i>-1 ; i--){
			for (int j=0 ; j<cols ; j++){
				fread(&rgba_data, sizeof(char), sizeof(rgba_data) , bmp);
				rgba[i][j] = rgba_data;
			}
			fread(&padding, sizeof(char), sizeof(padding), bmp);
		}
		fclose(bmp);
	}
}