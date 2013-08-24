/* 
 * File:   main.c
 * Author: Levi
 *Programa para calcular a area de um poligono pelo metodo de gauss
 * Created on 24 de Agosto de 2013, 13:23
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
float area[2][10];
float a1,a2,at;
int p;
int i,j;

int main(int argc, char** argv) {
    i=0;
    p=1;
    while (p!=0) { // condicao de parada
        printf("digite x \n");
        scanf ("%f", &area[0][i]); //valores de x
        printf("digite y\n");
        scanf ("%f", &area[1][i]); //valores de y
        printf("outro ponto? (1/0)\n"); //se 0 sai do laco
        scanf("%d",&p);
        i++;
    }
    a1=0;
    a2=0;
    for (j=0; j<i; j++){
        if(j==(i-1)){ //se for o ultimo termo da multiplicacao
            a1= a1 + (area[0][j])*(area[1][0]);
            a2= a2 + (area[1][j])*(area[0][0]);
        }else{ //senao
            a1= a1 + (area[0][j])*(area[1][j+1]);
            a2= a2 + (area[1][j])*(area[0][j+1]); 
        }
    }
    at=(a1-a2)/2; //area
    printf("\na area total e: %f \n",at);
    for(j=0;j<i; j++){ //imprimindo as coordenadas
        printf("Coordenada %d: ",j);
        printf("%f ", area[0][j]);
        printf(", %f \n",area[1][j]);              
    }
    return (EXIT_SUCCESS);
}
