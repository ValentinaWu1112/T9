#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Hash.h"


#define MAXSIZE 128
#define M 32749

int main (){
  /*FILE *f = fopen("file.txt", "r");
  STinit();
  char *str = (char*)malloc(MAXSIZE*sizeof(char));
  while(fgets(str, MAXSIZE, f) != NULL) {
    str[strlen(str)-1]='\0';
    char *token;
    token = strtok(str, " ");
    while(token != NULL) {
      tipoObjeto *tmp = STsearch(token);
      STinsert(tmp);
      token = strtok(NULL, " ");
    }
  }*/

  FILE *f = fopen("file.txt", "r");
    if(f==NULL) printf("Cannot open");
    char *str = (char*)malloc(MAXSIZE*sizeof(char));
    char *tmp = (char*)malloc(MAXSIZE*sizeof(char));
    int ind =0;
    while(fgets(str, MAXSIZE, f) != NULL){
        //puts(str);
        if(str[strlen(str)-1]=='\n') str[strlen(str)-1]='\0';
        for(int i=0; i<strlen(str); i++){
            //printf("%c\n", str[i]);
            if(isalpha(str[i])){
                printf("alpha\n");
                tmp[ind++]=str[i];
            }
            else if(ispunct(str[i])){
                printf("punct\n");
                tmp[ind++]='\0';
                if(tmp[0]!='\0'){
                    tipoObjeto *to = STsearch(tmp);
                    STinsert(to);
                }
                puts(tmp);
                //printf("%s",tmp);
                ind=0;
                free(tmp);
                tmp = (char*)malloc(MAXSIZE*sizeof(char));
                tmp[ind++]=str[i];
                tmp[ind++]='\0';
                tipoObjeto *to1 = STsearch(tmp);
                STinsert(to1);
                puts(tmp);
                //printf("%s",tmp);
                ind=0;
                free(tmp);
                tmp = (char*)malloc(MAXSIZE*sizeof(char));

            }
            else if (str[i]==' ' || str[i]=='\n'){
                printf("space\n");
                tmp[ind++]='\0';
                puts(tmp);
                tipoObjeto *to2 = STsearch(tmp);
                STinsert(to2);
                //printf("%s", tmp);
                ind=0;
                free(tmp);
                tmp = (char*)malloc(MAXSIZE*sizeof(char));
            }
        }
    }

  int cod;
  printf("Ready\n");
  while(1){
    scanf("%d",&cod);
    imprimir(cod);
  }
}
