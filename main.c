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
#include "pgm.h"
#include "util.h"
#include <dirent.h>
#include <time.h>

int main(void) {
  unsigned int *scm;
  int levels;
  char levels_str[SIZE_LVL];
  char img_name[SIZE_FILE_NAME];

  int qt_img = 0;
  float total_time = 0;
  unsigned char label;
  clock_t begin, end;

  struct pgm img_original;
  struct pgm img_mean;

  struct dirent *dir_img;

  DIR *dir;
  char scm_file[SIZE_FILE_NAME] = SCM_FILE_MODEL;

  getLevel(&levels);
  sprintf(levels_str, "%d", levels);

  strcat(scm_file, levels_str);
  strcat(scm_file, SCM_FILE_EXTENSION);

  remove(scm_file);
  remove(ORDERED_FILE_NAME);


  if ((dir = opendir(PATH_IMAGES_ORIGINAL))) {
    printf("\n=-=-=- PROCESSANDO IMAGENS -=-=-=\n");
    printf("Aguarde...\n");

    while ((dir_img = readdir(dir)) != NULL) {
      if (dir_img->d_name[0] == '.' || strstr(dir_img->d_name, "mean")) {
        continue;
      }
      begin = clock();

      readPGMImage(&img_original, dir_img->d_name);
      quantizeMatrix(img_original.pData, img_original.r, img_original.c, levels);
      //writePGMImage(&img_original,dir_img->d_name);
      
      strcpy(img_name, dir_img->d_name);
      img_name[17] = '\0';
      writeOrderedFile(img_name, ORDERED_FILE_NAME);
      strcat(img_name, "_mean.pgm");

      readPGMImage(&img_mean, img_name);
      quantizeMatrix(img_mean.pData, img_mean.r, img_mean.c, levels);
      //writePGMImage(&img_mean,img_name);
      if (!(scm = calloc(levels * levels, sizeof(unsigned int)))) {
        printf("ERRO: Memória insuficiente para alocação.\n");
        exit(1);
      }

      label = dir_img->d_name[0];
      calculateSCM(img_original.pData, img_mean.pData, scm, levels,img_mean.r * img_mean.c);
      free(img_original.pData);
      free(img_mean.pData);

      writeSCM(scm, scm_file, levels * levels, label);

      free(scm);

      qt_img += 2;

      end = clock();
      total_time += (float)(end - begin) / CLOCKS_PER_SEC;
    }
    closedir(dir);
  }
  printf("Finalizado.\n");

  printf("\n=-=-=-= TEMPO DE EXECUÇÃO =-=-=-=\n");
  printf("Média por imagem: %f\n", total_time / (qt_img / 2));
  printf("Total: %f\n", total_time);

  return 0;
}
