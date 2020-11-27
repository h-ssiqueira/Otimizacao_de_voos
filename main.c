//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "arestas.h"
//Biblioteca Fila, Pilha t

int main(int argc, char *argv[]){//Pegar os paramêtros pela linha de comando 
    /* string args
		0 - nome do arquivo do programa
		1 - nome do .txt
		2 - aeroporto de partida
	*/

    if(argc != 3){ // Verificação dos parâmetros de entrada
		printf("\tPadrão incorreto de parâmetros!\n");
        exit(0);
	}

	/*
	// Teste para os argumentos
    printf("\nArgumentos: %d", argc);
	for(int i = argc-1; i >= 0; i--)
		printf("\n%s",argv[i]);
	*/

    
	vertice *grafo = novov();

	cria_aeroportos(&grafo,argv[1]);

    cria_arestas(&grafo, argv[1]);//Cria os voos de cada aeroporto

	if(verifica(grafo,argv[2])){ // Verifica se o aeroporto de origem existe no grafo
		//printateste(grafo); // Verificação de criação do grafo
		printf("=== Destinos ===\n");
		destinos(grafo, argv[2]);// Mostra os destinos disponíveis (DFS)

		printf("\n=== Conexões ===");
		conexoes(grafo, argv[2]); // Calcula os menores preços (BFS + Dijstra)
		printconex(grafo, argv[2], false); // Mostra as conexões

		printf("\n=== Menores custos ===");
		printconex(grafo, argv[2], true); // Mostra os menores custos
		//printateste(grafo); // Verificação de criação do grafo
		printf("\n");
	}
	else
		printf("\tAeroporto de origem inexistente no arquivo.\n");
	
    desalocag(&grafo); // Liberação de memória do grafo
    return 0;
}
