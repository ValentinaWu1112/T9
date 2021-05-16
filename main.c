#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"


#define MAXSIZE 128
#define M 101

int main (){
  FILE *f = fopen("file.txt", "r");
  STinit();
  char *str = (char*)malloc(MAXSIZE*sizeof(char));
  while(fgets(str, MAXSIZE, f) != NULL) {
    char *token;
    token = strtok(str, " ");
    printf("%s\n",token);
    while(token != NULL) {
      tipoObjeto t = STsearch(token);
      printf("main: %s %d\n", t.valor, t.ocorrencias);
      STinsert(t);
      token = strtok(NULL, " ");
    }
  }

  int tmp;
  while(1){
    scanf("%d",&tmp);
    imprimir(tmp);
  }
}
