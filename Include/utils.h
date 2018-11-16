/*
+---------------------------------------------+
|  Autor :                       Nebout Yann  |
|  Name of project :        Reading BMP File  |
|  Starting date :        12th november 2018  |
|  Date of last release : 18th november 2018  |
|                                             |
|  File description :                         |
|		- Include all library that we need    |
|		- Definition of fixed variable        |
+---------------------------------------------+
*/
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>		// To fread, fopen, fclose, fseek function
#include <stdlib.h>
#include <string.h>		// To strcmp function
#include <math.h>
#include <stdbool.h> 	// To bool type 
#include <stdint.h>		// TO uint/uchar types
#include <stdarg.h> 	// For .. parameters in function, va_list, va_arg(). This program don't use that in this release

#define BMPHEADER_MIN_SIZE 40
#define BMPHEADER_SIZE 14

#endif