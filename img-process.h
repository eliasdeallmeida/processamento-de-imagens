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

#ifndef IMG_PROCESS_HEADER
#define IMG_PROCESS_HEADER

#include <stdlib.h>
#include "util.h"

#define SCM_FILE_MODEL "level-"
#define SCM_FILE_EXTENSION ".txt"

void quantizeMatrix(unsigned char *, int, int, int);
void calculateSCM(unsigned char *, unsigned char *, unsigned int *, int, int);
void writeSCM(unsigned int *, char *, int, unsigned char);
void writeOrderedFile(char *, char *);

#endif