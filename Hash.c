#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Hash.h"

#define M 101
#define MAXSIZE 128

link tab[M];

tipoObjeto* criar (char *v, int occur){
    tipoObjeto *obj;
    obj = (tipoObjeto*)malloc(sizeof(tipoObjeto));
    obj->valor = (char*)malloc(MAXSIZE*sizeof(char));
    strcpy(obj->valor, v);
    obj->ocorrencias=occur;
    return obj;
}

link cria_lista(){
    link aux;
    aux=(link)malloc(sizeof(_STnode));
    if(aux!=NULL){
        aux->obj=NULL;
        aux->next=NULL;
    }
    return aux;
}

void procura_link(link l, tipoObjeto *obj, link *ant, link *atual){
    *ant=l;
    *atual=l->next;

    while((*atual)!=NULL && (*atual)->obj->ocorrencias>obj->ocorrencias){
        *ant=*atual;
        *atual = (*atual)->next;
    }

    if((*atual)!=NULL && (*atual)->obj->ocorrencias!=obj->ocorrencias){
        *atual=NULL;
    }
}

void insert (link l, tipoObjeto *o){
    link no;
    link ant,atual;
    no=(link)malloc(sizeof(_STnode));
    if(no!=NULL){
        no->obj=o;
        procura_link(l, o, &ant, &atual);
        no->next=ant->next;
        ant->next=no;
    }
}

void procura_elimina(link l, tipoObjeto *obj, link *ant, link *atual){
    *ant=l;
    *atual=l->next;

    while((*atual)!=NULL && strcmp((*atual)->obj->valor,obj->valor)!=0){
        *ant=*atual;
        *atual = (*atual)->next;
    }

    if((*atual)!=NULL && strcmp((*atual)->obj->valor,obj->valor)!=0){
        *atual=NULL;
    }
}

void elimina (link l, tipoObjeto *o){
    link ant1;
    link atual1;
    procura_elimina(l,o,&ant1, &atual1);
     if (atual1 != NULL) {
        ant1->next = atual1->next;
        free (atual1);
    }
}

int codigo(char c){
    c = tolower(c);
    switch (c)
    {
        case 'a': case 'b': case 'c': case 'â': case 'ã': case 'á': case 'à': return 2;
        case 'd': case 'e': case 'f': case 'é': return 3;
        case 'g': case 'h': case 'i': case 'í': return 4;
        case 'j': case 'k': case 'l': return 5;
        case 'm': case 'n': case 'o': case 'õ': case 'ô': return 6;
        case 'p': case 'q': case 'r': case 's': return 7;
        case 't': case 'u': case 'v':  return 8;
        case 'w': case 'x': case 'y': case 'z': return 9;
        default: return -1;
    }
}

int hash(char * v) {
    int j = 1;
    int result = 0;
    for (int i = strlen(v)-1; i >= 0; i--)
    {
        result += codigo(v[i]) * j;
        j *= 10;
    }
    return result % M;
}

void STinit(){
  for (int h = 0; h < M; h++)
    tab[h] = NULL;
}

void STinsert(tipoObjeto *obj){
    char *v = obj->valor;
    int h = hash(v);
    link t = tab[h];
    for(t=tab[h];t!=NULL; t=t->next)
        if(strcmp(t->obj->valor,v)==0) break;

    if(t!=NULL) t->obj->ocorrencias++;
    else{
        obj->ocorrencias=1;
        link novo = malloc(sizeof(_STnode));
        novo->obj=obj;
        novo->next=tab[h];
        tab[h]=novo;
    }
}

tipoObjeto* STsearch(char *v){
    link t;
    int h = hash(v);
    for(t=tab[h]; t!=NULL; t=t->next){
        if(strcmp(t->obj->valor,v)==0) break;
    }
    if(t!=NULL) return t->obj;
    tipoObjeto *objetonulo=criar(v,0);
    return objetonulo;
}

void imprimir(int h){
    int hashtmp = h%M;
    link t;
    for(t=tab[hashtmp]; t!=NULL; t=t->next){
        printf("%s %d\n", t->obj->valor, t->obj->ocorrencias);
    }
}
