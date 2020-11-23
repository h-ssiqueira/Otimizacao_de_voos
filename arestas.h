//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

#include <stdbool.h>

// Estrutura do aeroporto
typedef struct vertices{
    char aero[4]; // Nome do aeroporto
	bool visitado; // Usado nas funções de busca para checar se o mesmo foi visitado
	float total; // Representa o total a ser pago para chegar neste aeroporto
	int conexoes; // Número de conexões do aeroporto escolhido até o atual
    struct arestas *arestas; // Conexões
    struct vertices *prox, *anterior; // Anterior representa o nó anterior do caminho mais curto e pŕoximo representa o próximo aeroporto cadastrado da lista
}vertice;

// Estrutura dos voos
typedef struct arestas{
    //char aero[4]; // Usado para testes (nome do aeroporto apontado)
    float preco; // Preço para ir de um aeroporto a outro
    struct vertices *vertice; // Aeroporto apontado
    struct arestas *prox; // Aponta para o próximo voo
}aresta;

// Nó para pilha e fila
typedef struct No{
    vertice *aeroporto,*anterior; // Ponteiro para o aeroporto atual e anterior
	int conexoes; // Quantidade de conexões necessárias para chegar a um aeroporto
	//char *caminhos; // String dos caminhos percorridos (Conexões / BFS) Inicialmente usada no BFS
    struct No *prox; // Aponta para o príxomo nó da fila
}no;

/*
// Pilha para DFS (substituida pela recursão)
typedef struct Pilha{
    struct No *topo;//Topo pilha 
}pilha;
*/

// Fila para BFS
typedef struct Fila{
    struct No *ini; // Inicio fila
    struct No *fim;                         
}fila;

// Cria o grafo
vertice *novov();

// Cria a lista de voos
aresta *novoa();

// Adiciona um aeroporto ao grafo
void cria_vertice(vertice **grafo, char aero[]);

// Adiciona um voo
void adiciona_aresta(vertice *Grafo,aresta **voo, char destino[4], float preco);

// Adiciona todos os voos a partir do arquivo
void cria_arestas(vertice **Grafo, char nome_arq[]);

// Libera memória alocada no grafo
void desalocag(vertice **Grafo);

// Função de exibição do grafo alocado, usada para testes
void printateste(vertice *Grafo);

// Realiza a busca em profundidade
void DFS(vertice *atual/*, pilha *caminho*/);

// Inicializa as variáveis booleanas para executar a busca em profundidade
void destinos(vertice *grafo, char partida[]);

// Função de busca em largura + cálculo do caminho mais barato
void BFS(fila *f);

// Inicializa as variáveis internas de cada vértice (booleana, preço total, aeroporto anterior, conexões) para chamar a busca em largura
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

void inseref(fila *f, vertice *aero, int conection/* char path[]*/);

vertice* removef(fila *f, int *conexoes/*, char **caminhos, int *tam*/);

// Exibição da fila, usada para testes
void printfila(fila *f);

void desalocaf(fila *f);