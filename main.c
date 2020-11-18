//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633
#include <stdio.h>
#include <stdlib.h>
#include "arestas.h"
#include <string.h>
//Biblioteca Fila, Pilha t

int main(int argc, char *argv[]){//Pegar os paramêtros pela linha de comando 
    /* string args
		0 - nome do arquivo do programa
		1 - nome do .txt
		2 - aeroporto de partida
	*/

    //printf("\nArgumentos: %d %s", argc, argv[0]);
    FILE *arq = fopen(argv[1], "r");
	vertice *grafo = novo();
    int num_aerop, num_voos;
    char origem[4], destino[4], anterior[4] = "\0";
    float preco, cent;
	if(!arq){
        printf("\n\tErro ao abrir o arquivo.");
        exit(0);
    }
    fscanf(arq, "%d", &num_aerop);
    fscanf(arq, "%d", &num_voos);
    //printf("Num. Aeroportos: %d\nNum. Voos: %d", num_aerop, num_voos);
    for(int i = num_voos; i > 0 ; i--){// Cria primeiro todos os aeroportos
       fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);
       if(!strcmp(anterior, origem))
		   cria_vertice(&grafo,origem);
    }
    fclose(arq);
    

	// Desalocar depois o grafo
    return 0;
}