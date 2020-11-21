//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633
#include <stdio.h>
#include <stdlib.h>
#include "arestas.h"
#include <string.h>
//Biblioteca Fila, Pilha t

int main(int argc, char *argv[]){//Pegar os paramêtros pela linha de comando 
   //   exit(0);
    /* string args
		0 - nome do arquivo do programa
		1 - nome do .txt
		2 - aeroporto de partida
	*/
    //Verificação dos parâmetros de entrada
    if(argc != 3)
        exit(0);
    //printf("\nArgumentos: %d %s", argc, argv[0]);
    FILE *arq = fopen(argv[1], "r");
	vertice *grafo = novov();
    int num_aerop, num_voos, check;
    char origem[4], destino[4], anterior[4] = "RAFA";
    float preco, cent;
	if(!arq){
        printf("\n\tErro ao abrir o arquivo.");
        exit(0);
    }
    fscanf(arq, "%d\n", &num_aerop);
    fscanf(arq, "%d\n", &num_voos);
    //printf("Num. Aeroportos: %d\nNum. Voos: %d", num_aerop, num_voos);
    for(int i = num_voos; i > 0 ; i--){// Cria primeiro todos os aeroportos
        fscanf(arq, "%s %s R$%f,%f", origem,     destino, &preco, &cent);
        check = strcmp(anterior, origem);
        if(check != 0){
		    cria_vertice(&grafo,origem);
            strcpy(anterior, origem);
        }
       //printf("\n\n\t(%d)Origem: %s\n\t(%d)Destino:%s\n\tValor:%.2f", strlen(origem),origem, strlen(destino),destino, preco+cent/100);
    }
    fclose(arq);
    //Cria as arestar
    cria_arestas(&grafo, argv[1]);//PROBLEMA
    //printateste(grafo);
	// Desalocar depois o grafo
    desaloca(&grafo);
    return 0;
}
