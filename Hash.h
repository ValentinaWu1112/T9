#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct {
  int ocorrencias;
  char *valor;
}tipoObjeto;

int hash(char *v);
void STinit();
void STinsert(tipoObjeto obj);
tipoObjeto STsearch(char *v);
void imprimir(int h);

#endif // HASH_H_INCLUDED
