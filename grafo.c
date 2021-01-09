//Alcides Gomes Beato Neto   RA: 19060987
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "grafo.h"

vertice* novov(){
	return NULL;
}

aresta* novoa(){
	return NULL;
}

void cria_vertice(vertice ***grafo, char aero[]){
	vertice *aux = (vertice*)malloc(sizeof(vertice)), *roda;
	strcpy(aux->aero,aero);
	aux->prox = NULL;
	aux->visitado = NULL;
	aux->arestas = novoa();
    if(!(**grafo)){
		(**grafo) = aux;
	}
    else{
	    for(roda = (**grafo); roda->prox != NULL; roda = roda->prox)
	    	continue; // Percorre a lista até o fim para adicionar
        roda->prox = aux;
	    }
}

void cria_aeroportos(vertice **grafo, char nome_arq[]){
	int num_aerop, num_voos;
    char origem[4], destino[4];
    float preco, cent;
	bool existeO,existeD;
	FILE *arq = fopen(nome_arq, "r");
	vertice *aux;
	if(!arq){
        printf("\tErro ao abrir o arquivo.\n");
        exit(0);
    }
    fscanf(arq, "%d\n", &num_aerop);
    fscanf(arq, "%d\n", &num_voos);
    //printf("Num. Aeroportos: %d\nNum. Voos: %d", num_aerop, num_voos);
    for(int i = num_voos; i > 0 ; i--){// Cria primeiro todos os aeroportos
        fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);
		existeO = false;
		existeD = false;
		for(aux = *grafo; aux != NULL; aux = aux->prox){
			if(!strcmp(aux->aero,origem)) // Verifica se o aeroporto de origem existe
				existeO = true;
			if(!strcmp(aux->aero,destino)) // Verifica se o aeroporto de destino existe
				existeD = true;
		}
		if(!existeO)
        	cria_vertice(&grafo,origem);
		if(!existeD)
			cria_vertice(&grafo,destino);
       //printf("\n\n\t(%d)Origem: %s\n\t(%d)Destino:%s\n\tValor:%.2f", strlen(origem),origem, strlen(destino),destino, preco+cent/100);
    }
    fclose(arq);
}

void adiciona_aresta(vertice *Grafo, aresta **voo, char destino[4], float preco){
	aresta *aux = (aresta*)malloc(sizeof(aresta)), *roda;
	vertice *procura;
    if(!aux){
		printf("\n\tLimite de memória atingido!");
        exit(0);
	}
	//strcpy(aux->aero,destino); // Para conferência de nomes de aeroportos (contido e apontado)
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
    else{
		for(roda = (*voo); roda->prox != NULL; roda = roda->prox)
			continue; // Percorre a lista até o fim para adicionar
		roda->prox = aux;
	}

}

void cria_arestas(vertice **Grafo, char nome_arq[]){
	int num_aerop, num_voos;
	char origem[4], destino[4];
	float preco, cent;
	FILE *arq = fopen(nome_arq, "r");
	vertice *aux = (*Grafo);
	if(!arq){
        printf("\tErro ao abrir o arquivo.\n");
        exit(0);
    }
	fscanf(arq, "%d", &num_aerop);
    fscanf(arq, "%d", &num_voos);
    for(int i = num_voos; i > 0 ; i--){// Cria os vôos entre cada aeroporto
        fscanf(arq, "%s %s R$%f,%f", origem, destino, &preco, &cent);
	    preco += (cent/100);// Unir parte fracionária
		for(aux = *Grafo; aux != NULL; aux = aux->prox){
			if(!strcmp(aux->aero,origem))
				break;
		}
	    adiciona_aresta(*Grafo,&(aux)->arestas,destino,preco);
    }
    fclose(arq);
}

bool verifica(vertice *grafo, char origem[]){
	for(vertice *aux = grafo; aux != NULL; aux = aux->prox){
		if(!strcmp(aux->aero,origem))
			return true;
	}
	return false;
}

void desalocag(vertice **Grafo){
    vertice *auxv = (*Grafo), *proxv = NULL;
    aresta *auxa = NULL, *proxa = NULL;
    while(auxv != NULL){ // Desaloca o vértice (Aeroportos)
        auxa = auxv->arestas;
        while(auxa != NULL){ // Desaloca a aresta (Vôo)
            proxa = auxa->prox;
            free(auxa);
            auxa = proxa;
        }
		auxv->anterior = NULL;
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
        for(aresta *auxa = aux->arestas; auxa != NULL; auxa = auxa->prox)
            //printf("\n\tDestino(Dentro): %s\tDestino(Apontado): %s\n\tPreco: %f\n",auxa->aero,auxa->vertice->aero, auxa->preco); // Conferência se os nomes dos aeroportos se correspondem
			printf("\n\tDestino: %s\n\tPreco: %f\n",auxa->vertice->aero, auxa->preco);
        printf("\n");
    }
}



void DFS(vertice *atual/*, pilha *caminho*/){
	if(atual != NULL){
		float total;
		for(aresta *aux = atual->arestas; aux != NULL; aux = aux->prox){
			total = atual->total + aux->preco; // Calcula o preço para o destino
			if(total < aux->vertice->total){ // Se o preço for menor atualiza todas as informações para caminho mais curto
				aux->vertice->total = aux->preco;
				aux->vertice->anterior = atual;
			}
		}
	}
	if(!atual->visitado){
		atual->visitado = true;
		//push(atual,caminho);
		printf("%s ",atual->aero);
		for(aresta *aux = atual->arestas; aux != NULL; aux = aux->prox){
			DFS(aux->vertice/*,caminho*/);
		}
	}
}

// DFS
void destinos(vertice *grafo, char partida[]){
	//pilha *caminho = criap();
	vertice *atual;
	float total;
	for(vertice *aux = grafo; aux != NULL; aux = aux->prox){
		aux->anterior = NULL; // Inicializa o último visitado para o algoritmo de caminho mais curto
		if(strcmp(aux->aero,partida) == 0){
			aux->visitado = true; // Deixa atualizado o aeroporto de início
			aux->total = 0; // Deixa o valor total como 0
			atual = aux; // Atribui o atual para chamar posteriormente na função
		}
		else{
			aux->visitado = false; // Inicializa o booleano para visitação
			aux->total = FLT_MAX; // Atribui o "infinito" sendo o limite do tipo float
		}
		//printf("\n\t%s : %s\n",aux->aero,aux->visitado ? "true" : "false"); // Conferência de atribuição do booleano
	}
	for(aresta *aux = atual->arestas; aux != NULL; aux = aux->prox){
		total = atual->total + aux->preco; // Calcula o preço para o destino
		if(total < aux->vertice->total){ // Se o preço for menor atualiza todas as informações para caminho mais curto
			aux->vertice->total = aux->preco;
			aux->vertice->anterior = atual;
		}
		DFS(aux->vertice/*,caminho*/);
	}
	//desalocap(caminho);
}

//Funções Impressão
void printa_rec_conex(vertice *aux, vertice *destino, char *origem, bool custo){
	if(!strcmp(aux->aero, origem) && !custo){
		printf("%s", aux->aero);
		return;
	}
	if(!strcmp(aux->aero, origem) && custo){
		printf("%s -> %s (R$%.2f) ", aux->aero, destino->aero, destino->total);
		return;
	}
	printa_rec_conex(aux->anterior, aux, origem, custo);
	if(custo && destino != NULL)
		printf("%s -> %s (R$%.2f) ", aux->aero, destino->aero, destino->total);
	else if(!custo)
		printf(" -> %s", aux->aero);
}

float calculatotal(vertice *atual){
	if(atual != NULL)
		return atual->total + calculatotal(atual->anterior);
}

void printconex(vertice *grafo, char *origem, bool custo){
	int maiorconex = 0, i;//Pega a maior conexão(Contador)
	vertice *aux = NULL;
	for(aux = grafo; aux != NULL; aux = aux->prox){
		if(maiorconex < aux->conexoes){
			maiorconex = aux->conexoes;
		}
	}
	for(i = 1; i <= maiorconex; i++){
		for(aux = grafo; aux != NULL; aux = aux->prox){
			if(aux->conexoes == i && !custo){
				printf("\n%s (%d): ", aux->aero, aux->conexoes);
				printa_rec_conex(aux, NULL, origem, custo);
			}
			else if(aux->conexoes == i && custo){
				printf("\n%s (R$%.2f): ", aux->aero, calculatotal(aux));
				printa_rec_conex(aux, NULL, origem, custo);
			}
		}
	}
}

void BFS(fila *f){
	vertice *atual;
	int conexoes/*, tam*/;
	//float total;
	//char *caminhos /*= reallocarray(caminhos,4,1)*/ = (char*)malloc(f->ini->conexoes*7+4);
	atual = removef(f,&conexoes/*,&caminhos,&tam*/);

	/*
	if(conexoes != 0){
		caminhos = reallocarray(caminhos,tam,1);
		caminhos[tam-8] = ' ';
		caminhos[tam-7] = '-';
		caminhos[tam-6] = '>';
		caminhos[tam-5] = ' ';
		caminhos[tam-4] = atual->aero[0];
		caminhos[tam-3] = atual->aero[1];
		caminhos[tam-2] = atual->aero[2];
		caminhos[tam-1] = '\0';
		printf("%s (%d): %s\n",atual->aero, conexoes, caminhos);
	}
	*/
	conexoes++;
	for(aresta *voo = atual->arestas; voo != NULL; voo = voo->prox){ // Checa as arestas adjacentes
		/*total = /*atual->total +*/ /*voo->preco; // Calcula o preço para o destino
		if(total < voo->vertice->total){ // Se o preço for menor atualiza todas as informações para caminho mais curto
			voo->vertice->total = total;
			voo->vertice->conexoes = conexoes;
			voo->vertice->anterior = atual;
		}*/
		if(voo->vertice->total == voo->preco) // Checa se há um menor número de conexões até o destino
			voo->vertice->conexoes = conexoes;
		if(!voo->vertice->visitado){ // Checa se já foi visitado para adicionar na fila
			voo->vertice->visitado = true;
			inseref(f, voo->vertice,conexoes/*,caminhos*/);
		}
	}
	//printfila(f);
	//caminhos = reallocarray(caminhos,0,1);
	//free(caminhos);
}

// BFS
void conexoes(vertice *grafo, char partida[]){
	vertice *atual;
	fila *f = criaf();
	for(vertice *aux = grafo; aux != NULL; aux = aux->prox){ // Inicializa o booleano para visitação
		aux->conexoes = 0;
		if(strcmp(aux->aero,partida) == 0){
			aux->visitado = true;
			atual = aux;
		}
		else
			aux->visitado = false;
	}
	inseref(f,atual,0/*,partida*/);
	while(!vaziaf(f))
		BFS(f);
	desalocaf(f);
}

// Funções para a pilha (inutilizada)
/*
pilha* criap(){
    pilha *aux = (pilha*)malloc(sizeof(pilha));
    aux->topo = NULL;
    return aux;
}

void push(vertice *aero, pilha *P){
    no *aux = (no*)malloc(sizeof(no));
    aux->aeroporto = aero;
    aux->prox = P->topo;
    P->topo = aux;
}

vertice* pop(pilha *P){
	if(P->topo){
		vertice *retirar = P->topo->aeroporto;
		no *aux;
		aux = P->topo->prox;
		free(P->topo);
		P->topo = aux;
		return retirar;
	}
	else{
		return NULL;
	}
}

void desalocap(pilha *p){
	no *aux, *aux2;
	for(aux = p->topo; aux != NULL;){
		aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
	free(p);
}
*/
// Funções para a fila
fila* criaf(){
	fila *f = (fila*)malloc(sizeof(fila));
	f->fim = NULL;
	f->ini = NULL;
	return f;
}

bool vaziaf(fila *f){
	if(!f->ini)
		return true;
	return false;
}

void inseref(fila *f, vertice *aero, int conection/*, char path[]*/){
	no *novo = (no*)malloc(sizeof(no));
	novo->aeroporto = aero;
	novo->conexoes = conection;
	//novo->caminhos = (char*)malloc(strlen(path)*(sizeof(char))); // inicialmente usada no BFS
	//strcpy(novo->caminhos,path);
	if(!f->ini){
		f->ini = novo;
		f->fim = novo;
		novo->prox = NULL;
	}
	else{
		novo->prox = f->fim;
		f->fim = novo;
	}
}

vertice* removef(fila *f, int *conexoes/*, char **caminhos, int *tam*/){
	if(f->ini){
		no *aux;
		vertice *retorno = f->ini->aeroporto;
		(*conexoes) = f->ini->conexoes;
		//(*tam) = strlen(f->ini->caminhos)+8;
		//strcpy((*caminhos),f->ini->caminhos);
		if(f->ini == f->fim){
			f->ini->aeroporto = NULL;
			//free(f->ini->caminhos); // inicialmente usada no BFS
			free(f->ini);
			f->fim = f->ini = NULL;
		}
		else{
			for(aux = f->fim; aux->prox != f->ini; aux = aux->prox)
				continue;
			aux->prox = NULL;
			f->ini->aeroporto = NULL;
			//free(f->ini->caminhos); // inicialmente usada no BFS
			free(f->ini);
			f->ini = aux;
		}
		return retorno;
	}
	else{
		return NULL;
	}
}

void printfila(fila *f){
	no *aux;
	for(aux = f->fim; aux != NULL; aux = aux->prox)
		//printf("\n\t%s %s %d\n",aux->aeroporto->aero,aux->caminhos,aux->conexoes); // inicialmente usada no BFS
		printf("\n\t%s %d\n",aux->aeroporto->aero,aux->conexoes);
}

void desalocaf(fila *f){
	no *aux, *aux2;
	for(aux = f->fim; aux != NULL;){
		aux2 = aux->prox;
		//if(aux->caminhos)
			//free(aux->caminhos); // inicialmente usada no BFS
		aux->aeroporto = NULL;
		free(aux);
		aux = aux2;
	}
	free(f);
}