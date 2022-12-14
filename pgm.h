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

#ifndef PGM_HEADER
#define PGM_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pgm{
  int type;
  int c;
  int r;
  int mv;
  unsigned char *pData;
};

void readPGMImage(struct pgm*, char*);
void writePGMImage(struct pgm*, char*);
void viewPGMImage(struct pgm*);

#endif