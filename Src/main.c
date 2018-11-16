/*
+---------------------------------------------+
|  Autor :                       Nebout Yann  |
|  Name of project :        Reading BMP File  |
|  Starting date :        12th november 2018  |
|  Date of last release : 18th november 2018  |
|                                             |
|  File description :                         |
|		- Main program                        |
+---------------------------------------------+
*/
#include "Reading.h"
#include "Error.h"

int main(int argc, char* argv[]){
	parameters(argc, argv[1]);
	printf("parameters is OK!!\n");

	BMP_FILE_HEADER BMPfh;
	BMP_V5_HEADER BMPv5h;
	printf("Headers are created!!\n");

	initFileHeader(&BMPfh);
	initHeader(&BMPv5h);
	printf("Initialisation is OK!!\n");	

	int size = headerSize(argv[1], &BMPfh);
	printf("Offset is %d!!\n", BMPfh.offset_header);
	printf("Header Size is %d!!\n", size);
	headerBMP(argv[1], &BMPv5h, size);
	printf("height is %d!!\n", BMPv5h.height);
	printf("width is %d!!\n", BMPv5h.width);

	Pixel_RGB imageData[BMPv5h.height][BMPv5h.width];
	for(unsigned int i=0; i<BMPv5h.height ; i++){
		for (unsigned int j=0; j<BMPv5h.width ; j++){
			initPixelRGB(&imageData[i][j]);
		}
	}

	getDataRGB(argv[1], BMPfh.offset_header, BMPv5h.height, BMPv5h.width, imageData);

	for(unsigned int i=0; i<BMPv5h.height ; i++){
		for (unsigned int j=0; j<BMPv5h.width ; j++){
			printf("color of pixel[%d][%d] : %d %d %d\n",i,j,imageData[i][j].data[0],imageData[i][j].data[1],imageData[i][j].data[2]);
		}
	}
}