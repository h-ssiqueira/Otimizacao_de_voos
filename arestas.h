//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

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
    struct vertices *vertices;
    struct arestas *prox;
}aresta;