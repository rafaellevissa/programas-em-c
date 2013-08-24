#include <stdio.h>
#include <stdlib.h>
//#include <iostream.h>

typedef struct Nolistaint{
        int chave;
        struct Nolistaint *prox;
}Nolistaint, *Listaint;

void inicializa(Listaint *l){
     *l=NULL;
}

int consulta(Listaint *l, int x){
     Nolistaint *p;
     for (p=*l;(p)&&(p->chave!=x);p=p->prox)
     if(p)       
         return 1;
     else
         return 0;
}
int insere (ListaInt *l , int x ){
      p=(NoListaInt * ) malloc(sizeof(NoListaInt));
      if((consulta(l,x))||(!p)){
         printf("ja existe na lista\n");
         return 0;}
      else{
      p-> chave = x;
      p-> prox=*l;
      *l=p;
      return 1;
      }
}
void retira (Listaint *l, int x){
     Nolistaint *p,*q;
     for (q=NULL, p=*l; (p)&&(p->chave!=x);q=p, p=p->prox)
     if(p){
          if(q)
               q->prox=p->prox;
          else
              *l=p->prox;   
          free(p);
          }
}
                   
void imprime (ListaInt*l){
     NoListaInt *p;
     for(p=*l; p!=NULL; p=p->prox ){
         printf("->%d\n",p->chave);
     }
     printf("\n");
}

int main(){
  Listaint y;
  inicializa(&y);
  insere(&y,4);
  imprime(&y);
  insere(&y,7);
  imprime(&y);
  system("PAUSE");	
  return 0;
}
