//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633
#include <stdio.h>
#include <stdlib.h>
#include "arestas.h"
//#include <string.h>
//Biblioteca Fila, Pilha t

float define_preco(float v, float cent);

int main(int argc, char *argv[]){//Pegar os paramêtros pela linha de comando 
    
    //printf("\nArgumentos: %d %s", argc, argv[0]);
   
    FILE *arq = fopen(argv[1], "r");
    int num_aerop, num_voos;
    char origem[4], destino[4];
    float preco, cent;
    char anterior[4] = "\0";
    fscanf(arq, "%d", &num_aerop);
    fscanf(arq, "%d", &num_voos);
    //printf("Num. Aeroportos: %d\nNum. Voos: %d", num_aerop, num_voos);
    for(int i = num_voos; i > 0 ; i--){//\Cria primeiro todos os aeroportos
       fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);//Unir parte fracionária
       if(!strcmp(anterior, origem)){
           //chama cria vértice
       }
       //preco = define_preco(preco, cent);
       //Chama função dos grafos
       //Conferindo se a existe um grafo para origem
       //printf("\n\n\tOrigem: %s\n\tDestino:%s\n\tValor:%.2f", origem, destino, preco);
    }
    fclose(arq);
    strcpy(anterior, "\0");//Limpando o anterior
    arq = fopen(argv[1], "r");
    for(int i = num_voos; i > 0 ; i--){//\Cria primeiro todos os aeroportos
       fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);//Unir parte fracionária
       if(!strcmp(anterior, origem)){
           //chama cria vértice
       }
    }

    if(!arq){
        printf("\n\tErro ao abrir o arquivo.");
        exit(0);
    }
    fclose(arq);
    return 0;
}

float define_preco(float v, float cent){
    cent = cent/100;
    return v + cent;
}