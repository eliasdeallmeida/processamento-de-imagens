/*
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Avaliação 04: Trabalho Final

EQUIPE:                      | MATRÍCULAS:
Chrislan Machado da Costa    | 20221045050079
Elias de Almeida Sombra Neto | 20221045050095
João Pedro Lopes de Carvalho | 20221045050192
Rai Ferreira Lima de Araujo  | 20221045050540

04.505.23 - 2022.2 - Prof. Daniel Ferreira
DISCIPLINA: Laboratório de Programação
COMPILADOR: Replit - gcc version 10.3.0 (GCC)
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <stdio.h>

#define PATH_IMAGES "./images"
#define PATH_ADD_IMAGES "images/"
#define PATH_ADD_QUANTIZED_IMAGES "quantized-images/"
#define IMAGES_READ_FILE_NAME "images-read.txt"
#define SIZE_PATH_NAME 50
#define SIZE_FILE_NAME 30
#define SIZE_LEVEL 4
#define MIN_LEVEL 8
#define MAX_LEVEL 256

void showMenu();
void getLevel(int *);

#endif
