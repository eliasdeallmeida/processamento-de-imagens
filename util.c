#include "util.h"

void getLevel(int *level){
  showMenu();
  int valid = 0;
  do {
    printf(">>> Sua opção: ");
    scanf("%d",level);
    valid = (*level % LEVEL_MIN || LEVEL_MX % *level) ? valid : 1;
    if (!valid) {
      printf("ERRO: Por favor digite um número válido listado acima.\n");
    }
  } while (!valid);
}

void showMenu() {
  printf("=-=-=-=-=-=-= MENU =-=-=-=-=-=-=\n");
  printf("Informe um nível de quantização\n");
  printf("[8]\n[16]\n[32]\n[64]\n[128]\n[256]\n");
}
