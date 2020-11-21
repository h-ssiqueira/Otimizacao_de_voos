//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

#include "pilha.h"

typedef struct vertices{
    char aero[4];
    struct arestas *arestas;
    struct vertices *prox;
}vertice;

typedef struct arestas{
    char aero[4];
    float preco;
    struct vertices *vertice;
    struct arestas *prox;
}aresta;

vertice *novov();

aresta *novoa();

void cria_vertice(vertice **grafo, char aero[]);

void adiciona_aresta(vertice *Grafo,aresta **voo, char destino[4], float preco);

void cria_arestas(vertice **Grafo, char nome_arq[]);

void desaloca(vertice **Grafo);

void printateste(vertice *Grafo);