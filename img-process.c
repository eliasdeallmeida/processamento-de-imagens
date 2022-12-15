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

#include "img-process.h"
#include "util.h"

void quantizeMatrix(unsigned char *pData, int rows, int columns, int levels) {
  int max_level = MAX_LEVEL / levels;
  for (unsigned char *i = pData; i < (pData + rows * columns); i++) {
    *i /= max_level;
  }
}

void calculateSCM(unsigned char *pData1, unsigned char *pData2, unsigned int *scm, int levels, int size) {
  for (int i = 0; i < size; i++) {
    *(scm + *(pData1 + i) * levels + *(pData2 + i)) += 1;
  }
}

void writeSCM(unsigned int *scm, char *scm_file, int size, unsigned char label) {
  FILE *fp;
  fp = fopen(scm_file, "a+");
  
  if (fp == NULL) {
    printf("ERRO: Não foi possível abrir o arquivo.\n");
    exit(1);
  }

  for (int i = 0; i <= size; i++) {
    (i == size)? fprintf(fp, "%c\n", label) : fprintf(fp, "%u, ", *(scm + i));
  }

  fclose(fp);
}

void writeOrderedFile(char *img_name, char *file_name) {
  FILE *fp;
  fp = fopen(file_name, "a+");
  
  if (fp == NULL) {
    printf("ERRO.\n");
    exit(1);
  }
  
  fprintf(fp, "%s\n", img_name);
  fclose(fp);
}