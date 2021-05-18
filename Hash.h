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
int hash(char *v);
void STinit();
void STinsert(tipoObjeto *obj);
tipoObjeto* STsearch(char *v);
void imprimir(int h);
link cria_lista();
void insert (link l, tipoObjeto *obj);

#endif // HASH_H_INCLUDED
