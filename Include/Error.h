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
#ifndef ERROR_H
#define ERROR_H

#include "utils.h"

/*
+------------------------------------------------------+
|  Function description :                              |
|		- Screen if the number of parameters is wrong  |
+------------------------------------------------------+
*/
void InstructionNumberofParameters();

/*
+------------------------------------------------+
|  Function description :                        |
|		- Screen if the extention file is wrong  |
+------------------------------------------------+
*/
void InstructionTypeofParameters();

/*
+----------------------------------------------------------------------------+
|  Function description :                                                    |
|		- Verify parameters                                                  |
|		Inputs :                                                             |
|			- number(int) : number of parameters (name of program included)  |
|			- argv1(char*) : pointer to char table                           |
+----------------------------------------------------------------------------+
*/
void parameters(int number, char* argv1);

#endif