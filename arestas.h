//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

#include <stdbool.h>

typedef struct vertices{
    char aero[4];
	bool visitado;
    struct arestas *arestas;
    struct vertices *prox;
}vertice;

typedef struct arestas{
    //char aero[4];
    float preco;
    struct vertices *vertice;
    struct arestas *prox;
}aresta;

// Nó para pilha e fila
typedef struct No{
    vertice *aeroporto;
	int conexoes;
	char *caminhos;
    struct No *prox;
}no;

/*
// Pilha para DFS
typedef struct Pilha{
    struct No *topo;//Topo pilha 
}pilha;
*/

// Fila para BFS
typedef struct Fila{
    struct No *ini; // Inicio fila
    struct No *fim;                         
}fila;

vertice *novov();

aresta *novoa();

void cria_vertice(vertice **grafo, char aero[]);

void adiciona_aresta(vertice *Grafo,aresta **voo, char destino[4], float preco);

void cria_arestas(vertice **Grafo, char nome_arq[]);

void desalocag(vertice **Grafo);

void printateste(vertice *Grafo);

void DFS(vertice *atual/*, pilha *caminho*/);

void destinos(vertice *grafo, char partida[]);

void conexoes(vertice *grafo, char partida[]);

/*
// Funções para a pilha
pilha* criap();

void push(vertice *aero, pilha *P);

vertice* pop(pilha *P);

void desalocap(pilha *p);
*/

// Funções para a fila
fila* criaf();

bool vaziaf(fila *f);

void inseref(fila *f, vertice *aero, int conection, char path[]);

vertice* removef(fila *f, int *conexoes, char **caminhos, int *tam);

void printfila(fila *f);

void desalocaf(fila *f);