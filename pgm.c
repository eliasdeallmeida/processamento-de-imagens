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

#include "pgm.h"
#include "util.h"

void readPGMImage(struct pgm *pio, char *filename){
  FILE *fp;
  char ch;
  char path[SIZE_PATH_NAME] = PATH_ADD_IMAGES;
  
  if(!(fp = fopen(strcat(path, filename), "r"))){
    perror("Erro");
    exit(1);
  }

  if((ch = getc(fp)) != 'P'){
    puts("ERRO: A imagem fornecida não está no formato pgm.");
    exit(2);
  }

  pio->type = getc(fp) - 48;

  fseek(fp, 1, SEEK_CUR);

  while((ch = getc(fp)) == '#'){
    while ((ch = getc(fp)) != '\n');
  }

  fseek(fp, -2, SEEK_CUR);

  fscanf(fp, "%d %d", &pio->columns, &pio->rows);
  if(ferror(fp)){
    perror(NULL);
    exit(3);
  }

  fscanf(fp, "%d", &pio->max_value);
  
  #ifdef __linux__
    fseek(fp, 1, SEEK_CUR);
  #elif _WIN32
    fseek(fp, 0, SEEK_CUR);
  #elif __APPLE__
    fseek(fp, 1, SEEK_CUR);
  #endif

  pio->pData = (unsigned char *)malloc(pio->rows * pio->columns * sizeof(unsigned char));

  switch(pio->type){
    case 2:
      //puts("Lendo imagem PGM (dados em texto)");
      for(int k = 0; k < (pio->rows * pio->columns); k++){
        fscanf(fp, "%hhu", pio->pData + k);
      }
      break;
    case 5:
      //puts("Lendo imagem PGM (dados em binário)");
      fread(pio->pData, sizeof(unsigned char), pio->rows * pio->columns, fp);
      break;
    default:
      puts("ERRO: Não está implementado.");
  }

  fclose(fp);
}

void writePGMImage(struct pgm *pio, char *filename){
  FILE *fp;
  char ch;
  char str[SIZE_PATH_NAME] = PATH_ADD_QUANTIZED_IMAGES;
    
  if(!(fp = fopen(strcat(str, filename), "wb"))){
    perror("Erro.");
    exit(1);
  }

  fprintf(fp, "P5\n");
  fprintf(fp, "%d %d\n", pio->columns, pio->rows);
  fprintf(fp, "%d\n", pio->max_value);

  fwrite(pio->pData, sizeof(unsigned char), pio->columns * pio->rows, fp);

  fclose(fp); 
}

void viewPGMImage(struct pgm *pio){
  printf("=-=-=- INFORMAÇÕES -=-=-=\n");
  printf("Tipo: %d\n", pio->type);
  printf("Dimensões: [%d %d]\n", pio->columns, pio->rows);
  printf("Max: %d\n", pio->max_value);
  printf("\n");
  
  for(int k = 0; k < (pio->rows * pio->columns); k++){
    if(!(k % pio->columns))
      printf("\n");
    printf("%3hhu ", *(pio->pData + k));
  }
  printf("\n");
}