/*
+---------------------------------------------+
|  Autor :                       Nebout Yann  |
|  Name of project :        Reading BMP File  |
|  Starting date :        12th november 2018  |
|  Date of last release : 18th november 2018  |
|                                             |
|  File description :                         |
|		- Error information                   |
|		- Instruction to correct error        |
+---------------------------------------------+
*/
#include "Error.h"

void InstructionNumberofParameters(){
	printf("You must put one argument and execute the program like : nameofprogram myfile.bmp .\n");
}

void InstructionTypeofParameters(){
	printf("You must put a bmp file in argument !!!\n");
}

void parameters(int number, char* argv1){
	if (number-1!=1){
		printf("You don't put one argument !!!\nPlease follow the next instruction : ");
		InstructionNumberofParameters();
	}
	int size = strlen(argv1);
	char extention[4];

	// We pick up the extention file to verify if it is correct.
	extention[0] = argv1[size-4];
	extention[1] = argv1[size-3];
	extention[2] = argv1[size-2];
	extention[3] = argv1[size-1];
	if (strcmp(extention,".bmp")!=0){
		printf("You don't put the good extention file !!!\nPlease follow the next instruction : ");
		InstructionTypeofParameters();
	}
}