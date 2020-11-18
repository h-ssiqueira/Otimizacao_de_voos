//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633
#include <stdio.h>
#include <stdlib.h>
struct aresta;
struct vertice;

typedef struct vertices{
    char aero[4];
    struct aresta *arestas;
    struct vertices *prox;
}vertice;

typedef struct arestas{
    char aero[4];
    float preco;
    struct vertices *vertice;
    struct arestas *prox;
}aresta;

vertice *novo(){
	return NULL;
}

aresta *novo(){
	return NULL;
}

void cria_vertice(vertice **grafo, char aero[]){
	vertice *aux = (vertice*)malloc(sizeof(vertice)), *roda;
	strcpy(aux->aero,aero);
	aux->prox = NULL;
	aux->arestas = novo();
	if(!*grafo){
		(*grafo) = aux;
	}
	else{
		for(roda = (*grafo); roda->prox != NULL; roda = roda->prox)
			continue; // Percorre a lista até o fim para adicionar
		roda->prox = aux;
	}
}

void adiciona_aresta(vertice *Grafo,aresta **voo, char destino[4], float preco){
	aresta *aux = (aresta*)malloc(sizeof(aresta)), *roda;
	vertice *procura;
	strcpy(aux->aero,destino);
	aux->preco = preco;
	aux->prox = NULL;
	for(procura = Grafo; procura != NULL; procura = procura->prox){ // procura o aeroporto de destino na lista de aeroporto
		if(!strcmp(procura->aero,destino)){
			aux->vertice = procura;
			break;
		}
	}
	if(!*voo){
		(*voo) = aux;
	}
	else{
		for(roda = (*voo); roda->prox != NULL; roda = roda->prox)
			continue; // Percorre a lista até o fim para adicionar
		roda->prox = aux;
	}
}

void cria_arestas(vertice **Grafo, char nome_arq[]){
	int num_aerop, num_voos;
	char origem[4], destino[4], anterior[4] = "\0";
	float preco, cent;
	FILE *arq = fopen(nome_arq, "r");
	vertice *aux = *Grafo;
	if(!arq){
        printf("\n\tErro ao abrir o arquivo.");
        exit(0);
    }
	fscanf(arq, "%d", &num_aerop);
    fscanf(arq, "%d", &num_voos);
    for(int i = num_voos; i > 0 ; i--){// Cria os vôos entre cada aeroporto
       fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);
	   preco += (cent/100);// Unir parte fracionária
	   //printf("\n\n\tOrigem: %s\n\tDestino:%s\n\tValor:%.2f", origem, destino, preco);
       if(!strcmp(anterior, origem)){ // Adiciona uma aresta no mesmo vértice que o anterior
		   adiciona_aresta(*Grafo,&aux->arestas,destino,preco);
       }
	   else{ // Adiciona uma aresta no próximo vértice
		   aux = aux->prox;
		   strcpy(anterior,origem);
		   adiciona_aresta(*Grafo,&aux->arestas,destino,preco);
	   }
    }

    
    fclose(arq);
}