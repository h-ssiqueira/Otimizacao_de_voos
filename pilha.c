//Alcides Gomes Beato Neto   RA: 19060987             
//Henrique Sartori Siqueira  RA: 19240472
//Rafael Silva Barbon        RA: 19243633

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arestas.h"

//Pilha par DFS
typedef struct No{
    vertice *aeroporto;
    struct No *prox;
}no;

typedef struct Pilha{
    struct No *topo;//Topo pilha 
}pilha;

typedef struct Fila{
    struct No *ini;//Topo pilha
    struct No *fim;                         
}fila;

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
    
}