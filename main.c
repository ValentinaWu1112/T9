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
    str[strlen(str)-1]='\0';
    char *token;
    token = strtok(str, " ");
    while(token != NULL) {
        puts(token);
      tipoObjeto *tmp = STsearch(token);
      STinsert(tmp);
      token = strtok(NULL, " ");
    }
  }

  int tmp;
  while(1){
    scanf("%d",&tmp);
    imprimir(tmp);
  }
}
