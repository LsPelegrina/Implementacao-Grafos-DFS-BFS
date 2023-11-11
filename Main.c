#include <stdio.h>
#include <stdlib.h>
#include "Grafo.c"

int main() {
    GRAFO *gr1 = criaGrafo(15);

    // Adiciona as arestas ao grafo
    criaAresta(gr1, 0, 1, 1);
    criaAresta(gr1, 0, 2, 1);
    criaAresta(gr1, 1, 3, 1);
    criaAresta(gr1, 1, 4, 1);
    criaAresta(gr1, 1, 5, 1);
    criaAresta(gr1, 3, 6, 1);
    criaAresta(gr1, 3, 7, 1);
    criaAresta(gr1, 5, 8, 1);
    criaAresta(gr1, 5, 9, 1);
    criaAresta(gr1, 7, 10, 1);
    criaAresta(gr1, 7, 11, 1);
    criaAresta(gr1, 7, 12, 1);
    criaAresta(gr1, 9, 13, 1);
    criaAresta(gr1, 9, 14, 1);

    // Lista de adjacencia
    imprime(gr1);

    // Imprime a matriz de adjacência do primeiro grafo
    Matriz(gr1);
    printf("\n");

    // Realiza a busca em largura a partir do vértice 1
    printf("Ordem dos vertices descobertos em Busca em largura a partir do vertice 1:\n");
    BFS(gr1, 1);

    printf("\n");
    printf("--------------------------------------------------------"); //Espacanento
    printf("\n\n");

    // Cria um grafo com 10 vértices (de 0 a 9)
    GRAFO *gr2 = criaGrafo(10);

    // Adiciona as arestas ao grafo
    criaAresta(gr2, 0, 1, 1);
    criaAresta(gr2, 1, 2, 1);
    criaAresta(gr2, 1, 4, 1);
    criaAresta(gr2, 2, 3, 1);
    criaAresta(gr2, 2, 4, 1);
    criaAresta(gr2, 2, 9, 1);
    criaAresta(gr2, 3, 4, 1);
    criaAresta(gr2, 4, 5, 1);
    criaAresta(gr2, 4, 6, 1);
    criaAresta(gr2, 4, 7, 1);
    criaAresta(gr2, 5, 6, 1);
    criaAresta(gr2, 7, 8, 1);
    criaAresta(gr2, 7, 9, 1);

    // Lista de adjacencia
    imprime(gr2);

    // Imprime a matriz de adjacência do segundo grafo
    Matriz(gr2);
    printf("\n");
    
    // Realiza a busca em profundidade a partir do vértice 0
    int i;
    int visitados[gr2->vertices];
    for(i = 0; i < gr2->vertices; i++) {
        visitados[i] = 0;
    }
    printf("Ordem dos vertices descobertos em Busca em profundidade a partir do vertice 0:\n");
    DFS(gr2, 0, visitados);

    return 0;
}