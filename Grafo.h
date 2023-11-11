#ifndef GRAFO_H
#define GRAFO_H

// Estruturas
typedef struct adjacencia ADJACENCIA; // Estrutura para representar uma adjacência em um grafo
typedef struct vertice VERTICE; // Estrutura para representar um vértice em um grafo
typedef struct grafo GRAFO; // Estrutura para representar um grafo
typedef struct fila FILA; 
typedef int TIPOPESO; // Tipo de dado para representar o peso de uma aresta
typedef int bool; // Tipo de dado para representar um valor booleano

// Funções
GRAFO *criaGrafo(int v); // Função para criar um grafo com v vértices
FILA *criaFila(int max); // Função para criar uma lista 
ADJACENCIA *criadAdj(int v, int peso); // Função para criar uma adjacência com um vértice v e um peso
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p); // Função para criar uma aresta de vi a vf com peso p em um grafo gr
void imprime(GRAFO *gr); // Função para imprimir um grafo
void Matriz(GRAFO *gr); // Função para imprimir a matriz de adjacência de um grafo
void DFS(GRAFO *gr, int origem, int *visitados); // Função de Busca em Profundidade (DFS)
int vazia(FILA *f); //Função para verificar se a lista está vazia
void enfileira(FILA *f, int valor); //Função para enfileirar a lista
int desenfileira(FILA *f); //Função para desenfileirar a lista
void BFS(GRAFO *gr, int origem); //Função de Busca em Largura (BFS)

#endif