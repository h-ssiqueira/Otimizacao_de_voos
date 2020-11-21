//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arestas.h"

vertice* novov(){
	return NULL;
}

aresta* novoa(){
	return NULL;
}

void cria_vertice(vertice **grafo, char aero[]){
	vertice *aux = (vertice*)malloc(sizeof(vertice)), *roda;
	strcpy(aux->aero,aero);
	aux->prox = NULL;
	//aux->arestas = novoa();
	aux->arestas = NULL;
    if(!(*grafo)){
		(*grafo) = aux;
	}
	else if((*grafo)->prox == NULL)
        (*grafo)->prox = aux;
    else{
	    for(roda = (*grafo); roda->prox != NULL; roda = roda->prox)
	    	continue; // Percorre a lista até o fim para adicionar
        roda->prox = aux;
	    }
}

void adiciona_aresta(vertice *Grafo, aresta **voo, char destino[4], float preco){
	aresta *aux = (aresta*)malloc(sizeof(aresta)), *roda;
	vertice *procura;
    if(!aux)
        exit(0);
	strcpy(aux->aero,destino);
	aux->preco = preco;
	aux->prox = NULL;
	for(procura = Grafo; procura != NULL; procura = procura->prox){ // procura o aeroporto de destino na lista de aeroporto
		if(!strcmp(procura->aero,destino)){
			aux->vertice = procura;
			break;
		}
	}
	if(!(*voo)){
		(*voo) = aux;
	}
	else if((*voo)->prox == NULL)
        (*voo)->prox = aux;
    else{
		for(roda = (*voo); roda->prox != NULL; roda = roda->prox)
			continue; // Percorre a lista até o fim para adicionar
		roda->prox = aux;
	}

}

void cria_arestas(vertice **Grafo, char nome_arq[]){
	int num_aerop, num_voos, check;
	char origem[4], destino[4], anterior[4];
	float preco, cent;
    strcpy(anterior, (*Grafo)->aero);
	FILE *arq = fopen(nome_arq, "r");
	vertice *aux = (*Grafo);
	if(!arq){
        printf("\n\tErro ao abrir o arquivo.");
        exit(0);
    }
	fscanf(arq, "%d", &num_aerop);
    fscanf(arq, "%d", &num_voos);
    for(int i = num_voos; i > 0 ; i--){// Cria os vôos entre cada aeroporto
       fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);
	   preco += (cent/100);// Unir parte fracionária
	    check = strcmp(anterior, origem);
        if(check != 0){ // Atualiza o vértice
		   aux = aux->prox;
		   strcpy(anterior,origem);
        }
	   adiciona_aresta(*Grafo,&(aux)->arestas,destino,preco);   
    }
    fclose(arq);
}

void desaloca(vertice **Grafo){
    vertice *auxv = (*Grafo), *proxv = NULL;
    aresta *auxa = NULL, *proxa = NULL;
    while(auxv != NULL){//Desaloca o vértice(Aroportos)
        auxa = auxv->arestas;
        while(auxa != NULL){//Desaloca a aresta(Vôo)
            proxa = auxa->prox;
            free(auxa);
            auxa = proxa;
        }
        auxv->arestas = NULL;
        proxv = auxv->prox;
        free(auxv);
        auxv = proxv;
    }
    (*Grafo) = NULL;
}

void printateste(vertice *Grafo){
    
    for(vertice *aux = Grafo; aux !=NULL; aux = aux->prox){
        printf("\n\tOrigem: %s", aux->aero);
        for(aresta *auxa = aux->arestas; auxa != NULL; auxa = auxa->prox){
            printf("\n\tDestino(Dentro): %s\tDestino(Apontado): %s\n\tPreco: %f\n",auxa->aero,auxa->vertice->aero, auxa->preco);
        } 
        printf("\n");
    }
}