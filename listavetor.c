#include <stdio.h>
#include <stdlib.h>

#define TAMMAXLISTA 10

typedef struct{
        int chaves[TAMMAXLISTA];
        int nelems;
        } Listaint;
        
void inicializa(Listaint*l){
     l.nelems=0;
}

int consulta(Listaint l, int x){
    int x;
    for (i=0; (i<l.nelems)&&(l.chaves[i]!=x); i++)
    if (i<l.nelems)
       return 1;
    else
        return 0;
}

int insere (Listaint *l, int x)
{
    if((consulta(l,x))||(l->nelems==TAMMAXLISTA)
        return 0;
    l->chaves[l->nelems]=x;
    l->nelems++;
    return 1
}
//como seria se eu implementasse o retornaposição no consulta???w
void retira(Listaint*l, intx){
     int pos;
     pos=retornaposição(l,x);
     if(pos>=0){
        l->nelems--;
        l->chaves[pos]= l->chaves[l->nelems]; //não entendi essa linha!!!
     }
}         
     
int main()
{
  Listaint y;
  inicializa(&y);
  printf(y.nelems);
  system("PAUSE");	
  return 0;
}
