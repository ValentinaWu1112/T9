#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Hash.h"
#include "Link.h"

#define M 101

//#define M 32749
// Tamanho da tabela.
// A tabela tab[0..M-1] apontará para as M listas de colisões.
link tab[M];
// Função de espalhamento: transforma uma chave não vazia v em um
// número no intervalo 0..M-1.
//

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

// Inicializa uma tabela que apontará as M listas de colisões.
//
void STinit() {
  int h;
  for (h = 0; h < M; h++)
    tab[h] = inic();
}
// Se o objeto obj já está na tabela de símbolos, a função
// insert incrementa o campo ocorrencias de obj. Senão,
// obj é inserido e seu contador é inicializado com 1.
//
void STinsert(tipoObjeto obj) {
  char *v = obj.valor;
  int h = hash(v);
  link t = tab[h];
  for (t = tab[h]; t != NULL; t = t->next)
    if (strcmp(t->obj.valor, v) == 0) break;

  if (t != NULL){
    elimina(t,obj);
    obj.ocorrencias++;
    insere(t,obj);
  }
  else {
    obj.ocorrencias = 1;
    insere(t,obj);
  }

  printf("%s %d -> %d\n", tab[h]->obj.valor, tab[h]->obj.ocorrencias, h);

}

// A função search devolve um objeto obj que tenha chave v.
// Se tal objeto não existe, a função devolve um objeto cuja
// chave é a char * vazia (ou seja, chave[0] == '\0').
//
tipoObjeto STsearch(char * v) {
  tipoObjeto objetonulo;
  link t;
  int h = hash(v);
  for (t = tab[h]; t != NULL; t = t->next)
    if (strcmp(t->obj.valor, v) == 0) break;
  if (t != NULL) return t->obj;
  objetonulo.valor = v;
  objetonulo.ocorrencias = 0;
  return objetonulo;
}

void imprimir(int h){
    int hashtmp = h % M;
    printf("hash: %d\n", hashtmp);
    link t;
    for (t = tab[hashtmp]; t != NULL; t = t->next){
        printf("%s\n", t->obj.valor);
    }
}
