#include <stdio.h>
#include <stdlib.h>

typedef struct Nolistaint {
        int chave ;
        struct Nolistaint *prox;
        struct Nolistaint *ant;
        }Nolistaint, *Listaint;

void inicializa (Listaint*l){
    printf("Lista iniciada...\n");
    *l=NULL; 
     }
     

void imprime (Listaint*l){
     Nolistaint *p;
     for(p=*l; p!=NULL; p=p->prox )
        printf("->%d",p->chave);
       // printf("<-%d\n",p->ant->chave);
        // printf("->%d\n",p->prox);
     printf("\n");
}     
     
int consulta (Listaint *l, int x){
      Nolistaint *p;
      for (p=*l;(p)&&(p->chave!= x); p=p->prox);
      if(p){
            printf("%d esta na lista\n", x);
            return 1;
            }
      else{
            printf("%d nao esta na lista\n", x);
            return 0;
            }
}
             
int insere (Listaint*l,int x){
     Nolistaint *p;
     if((consulta(l,x))||(!(p=(Nolistaint*)malloc(sizeof(Nolistaint)))))
        return 0;     
     p->chave=x;
     p->prox=*l;
     p->ant=NULL;
     if(*l)
           p->prox->ant=p;
     *l=p;
     printf("insercao sucessfull\n");
     return 1;
}
//versão 1 do retira:
/*void retira(Listaint*l, int x){
     Nolistaint *p, *q;
     for(q=NULL, p=*l; (p)&&(p->chave!=x); q=p, p=p->prox)
     if(p){
           if(q){
                 q->prox=p->prox;
                 if(p->prox)
                            p->prox->ant=q;
                 }
           else{
                *l=p->prox;
                if(p->prox)
                           p->prox->ant=NULL;
                }
           printf("%d retirado com sucesso\n", x);
           free(p);
           }
}
*/
//versão 2 do retira:
void retira(Listaint*l, int x){
     Nolistaint*p;
     for(p=*l; (p)&&(p->chave!=x); p=p->prox)
        if(p){
              if(p->ant)
                        p->ant->prox=p->prox;
              else
                   *l=p->prox;
              if(p->prox)
                         p->prox->ant=p->ant;
              //free(p);
              printf("retirou com sucesso");
              }
}
int main(){
Listaint y;
inicializa(&y);
insere(&y,1);
insere(&y,9);
insere(&y,2);
imprime(&y);
//consulta(&y,13);
retira(&y,9);
imprime(&y);
system( "PAUSE");
return 0;
}
