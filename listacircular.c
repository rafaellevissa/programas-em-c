#include <stdio.h>
#include <stdlib.h>

typedef struct Nolistaint{
        int chave;
        struct Nolistaint *prox;
        }Nolistaint, *Listaint;
        
void inicializa(Listaint *l){
     *l=NULL;
     printf ("Inicializado");
}

void imprime(Listaint *l){
     Nolistaint *p;
     for (p=((*l)->prox); p!=(*l); p=p->prox)
        printf("->%d", p->chave);
     printf("\n");
}  
     
//versão 1:
/*
int consulta(Listaint *l, int x){
    Nolistaint *p;
    if (!(*l))
       return 0;   
    for(p=(*l)->prox; (p!=*l)&&(p->chave!=x); p=p->prox);
    if(p->chave==x)
       return 1;
    else
        return 0;

}
*/

//versão 2:
int consulta(Listaint *l, int x){
    Nolistaint *p;
    int achou;
    if(!(*l)){
             printf("Lista vazia");
             return 0;
             }   
    achou= 0;
    p=*l;
    do{
         if (p->chave==x){
            achou=1;
            printf("achou %d", p->chave);
         }
         else
             p=p->prox;
    }while((!achou)&&(p!=(*l)));
    return achou;
}

int insere (Listaint *l, int x){
    Nolistaint *p;
    if ((consulta(l,x))||(!(p=(Nolistaint*) malloc(sizeof(Nolistaint)))))
       return 0;
    p->chave= x;
    if(*l){
           p->prox=(*l)->prox;
           (*l)->prox=p;
           }
    else{
        p->prox=p;
        *l=p;
        }
    return 1;
}

void retira (Listaint*l, int x){
    Nolistaint *p;
    if (consulta(l,x)){
       for (p=(*l)->prox; (p!=(*l))&&(p->prox!=x); p=p->prox);
       if (p=(*l))
          *l=NULL;
       p->prox=p->prox->prox;
       free(p->prox);
       write("%d foi removido", x);
    }
}  
                    
int main()
{
  Listaint y;
  insere(&y,1);
  insere(&y,2);
  insere(&y,3);
  imprime(&y);
  system("PAUSE");	
  return 0;
}
