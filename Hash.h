#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct {
  int ocorrencias;
  char *valor;
}tipoObjeto;

typedef struct STnode* link;
typedef struct STnode {
  tipoObjeto *obj;
  link next;
}_STnode;

tipoObjeto* criar (char *v, int oco);
link create();
int hash(char *v);
void STinit();
void STinsert(tipoObjeto *obj);
tipoObjeto* STsearch(char *v);
void imprimir(int h);
void insert (link l, tipoObjeto *obj);
void elimina (link l, tipoObjeto *o);

#endif // HASH_H_INCLUDED
