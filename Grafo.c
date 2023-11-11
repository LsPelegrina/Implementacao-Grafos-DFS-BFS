#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

// Estrutura para representar uma adjacência em um grafo
typedef struct adjacencia{
    int vertice; // Vértice de destino
    TIPOPESO peso; // Peso associado à aresta que leva ao vértice
    struct adjacencia *prox; // Próximo elemento da lista de adjacências
}ADJACENCIA;

// Estrutura para representar um vértice em um grafo
typedef struct vertice{
    ADJACENCIA *cab; // Cabeça da lista de adjacências
}VERTICE;

// Estrutura para representar um grafo
typedef struct grafo{
    int vertices; // Número total de vértices
    int arestas; // Número total de arestas
    VERTICE *adj; // Arranjo de vértices da estrutura
}GRAFO;

// Estrutura para representar uma fila
typedef struct fila {
    int *items; // Array para armazenar os elementos da fila
    int Ini; // Índice do primeiro elemento da fila
    int Fim; // Índice do último elemento da fila
    int max; // Tamanho máximo da fila
}FILA;

// Função para criar uma fila
FILA *criaFila(int max) {
    FILA *f = (FILA *)malloc(sizeof(FILA)); // Aloca memória para a fila
    f->items = (int *)malloc(max * sizeof(int)); // Aloca memória para os itens da fila
    f->Ini = -1; // Inicializa o índice do primeiro elemento como -1
    f->Fim = -1; // Inicializa o índice do último elemento como -1
    f->max = max; // Define o tamanho máximo da fila
    return f; // Retorna a fila criada
}

// Função para criar um grafo com v vértices
GRAFO *criaGrafo (int v){
    int i;

    // Aloca memória para o grafo
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));

    // Inicializa a lista de adjacências de cada vértice
    for(i=0; i<v; i++){
        g->adj[i].cab=NULL;
    }
    return (g);
}

// Função para criar uma adjacência com um vértice v e um peso
ADJACENCIA *criadAdj(int v, int peso){
    // Aloca espaço para a adjacência
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice =v; // Vértice alvo da adjacência
    temp->peso = peso; // Peso da aresta
    temp->prox = NULL; 
    return(temp); // Retorna o endereço da adjacência
}

// Função para criar uma aresta de vi a vf com peso p em um grafo gr
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    // Validações se o grafo existe e se os vértices são válidos
    if(!gr) return(false);
    if((vf<0)||(vf>=gr->vertices))return(false);
    if((vi<0)||(vf>=gr->vertices))return(false);

    // Cria a adjacência com o vértice final e o peso
    ADJACENCIA *novo = criadAdj(vf,p);

    // Coloca a adjacência na lista do vértice inicial
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab=novo;

    // Atualiza o número de arestas no grafo
    gr->arestas++;
    return (true);
}

// Função para imprimir um grafo
void imprime(GRAFO *gr){
    printf("Vertices..: %d. Arestas..: %d \n",gr->vertices,gr->arestas);
    int i;

    // Percorre cada vértice do grafo
    for(i = 0; i<gr->vertices; i++){
        printf("v%d:",i+1);

        // Percorre a lista de adjacências do vértice
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad){
            printf("v%d(%d) ",ad->vertice+1,ad->peso);
            ad=ad->prox;
        }
        printf("\n");
    }
}

// Função para imprimir a matriz de adjacência de um grafo
void Matriz(GRAFO *gr) {
    printf("\n\nMatriz de Adjacencia:\n");

    // Percorre cada vértice do grafo
    for (int i = 0; i < gr->vertices; i++) {
        for (int j = 0; j < gr->vertices; j++) {
            int adjacencia = 0;

            // Percorre a lista de adjacências do vértice
            ADJACENCIA *ad = gr->adj[i].cab;
            while (ad) {
                if (ad->vertice == j) {
                    adjacencia = ad->peso;
                }
                ad = ad->prox;
            }
            printf("%d\t", adjacencia);
        }
        printf("\n");
    }
}

// Função de Busca em Profundidade (DFS)
void DFS(GRAFO *gr, int origem, int *visitados) {
    // Marca o vértice de origem como visitado
    visitados[origem] = 1;
    printf("Visitado %d\n", origem); // Imprime o vértice visitado

    // Obtém a lista de adjacências do vértice de origem
    ADJACENCIA *ad = gr->adj[origem].cab;

    // Percorre a lista de adjacências
    while (ad) {
        // Se o vértice adjacente não foi visitado, realiza a busca em profundidade a partir dele
        if (!visitados[ad->vertice]) {
            DFS(gr, ad->vertice, visitados);
        }

        // Passa para a próxima adjacência
        ad = ad->prox;
    }
}

// Função para verificar se a fila está vazia
int vazia(FILA *f) {
    if(f->Fim == -1) // Se o índice do último elemento é -1, a fila está vazia
        return 1;
    else 
        return 0;
}

// Função para inserir um elemento na fila
void enfileira(FILA *f, int valor) {
    if(f->Fim == f->max - 1) // Se o índice do último elemento é igual ao tamanho máximo da fila menos 1, a fila está cheia
        printf("\nFila cheia\n");
    else {
        if(f->Ini == -1) // Se a fila estava vazia, atualiza o índice do primeiro elemento para 0
            f->Ini = 0;
        f->Fim++; // Incrementa o índice do último elemento
        f->items[f->Fim] = valor; // Insere o novo valor no final da fila
    }
}

// Função para remover um elemento da fila
int desenfileira(FILA *f) {
    int item;
    if(vazia(f)){ // Se a fila está vazia, imprime uma mensagem de erro
        printf("FILA vazia\n");
        return -1;
    }
    else{
        item = f->items[f->Ini]; // Obtém o primeiro elemento da fila
        f->Ini++; // Incrementa o índice do primeiro elemento
        if(f->Ini > f->Fim){ // Se a fila ficou vazia, reinicia os índices do primeiro e último elementos
            f->Ini = f->Fim = -1;
        }
        return item; // Retorna o elemento removido
    }
}

// Função de Busca em Largura (BFS)
void BFS(GRAFO *gr, int origem) {
    FILA *fila = criaFila(gr->vertices); // Cria uma fila com tamanho máximo igual ao número de vértices do grafo

    int visitados[gr->vertices]; // Array para armazenar os vértices visitados

    int i;
    for(i = 0; i < gr->vertices; i++) { // Inicializa todos os vértices como não visitados
        visitados[i] = 0;
    }

    enfileira(fila, origem); // Insere o vértice de origem na fila
    visitados[origem] = 1; // Marca o vértice de origem como visitado

    while(!vazia(fila)) { // Enquanto a fila não estiver vazia
        int atual = desenfileira(fila); // Remove o próximo vértice da fila
        printf("Visitado %d\n", atual); // Imprime o vértice visitado

        ADJACENCIA *ad = gr->adj[atual].cab; // Obtém a lista de adjacências do vértice atual
        while(ad) { // Percorre a lista de adjacências
            int adjacente = ad->vertice; // Obtém o vértice adjacente
            if(visitados[adjacente] == 0){ // Se o vértice adjacente não foi visitado
                enfileira(fila, adjacente); // Insere o vértice adjacente na fila
                visitados[adjacente] = 1; // Marca o vértice adjacente como visitado
            }
            ad = ad->prox; // Passa para a próxima adjacência
        }
    }
}



