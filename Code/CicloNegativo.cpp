// Bellman-Ford em C/C++ para encontrar ciclos negativos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Numero de vertices
#define V 4

// Metodo para verificar se tem ciclo negativo e imprimir a resposta
void hasCicloNegativo(int grafo[V][V], int distancia[]){
    bool resposta = false;
    // Se encontrar um caminho mais curto do que o ja salvo
    // e porque existe um ciclo negativo
    for (int u = 0; u < V; u++){
        for (int v = 0; v < V; v++){
            if (grafo[u][v] && distancia[u] != INT_MAX && distancia[u] + grafo[u][v] < distancia[v])
                resposta = true;
        }
    }
    if(resposta)
        printf("TRUE\n");
    else
        printf("FALSE\n");
}

// Metodo para encontrar o menor caminho entre o vertice fonte e
// todos os outros vertices, usando Bellman-Ford para detectar os
// ciclos negativos
void BellmanFord(int grafo[V][V], int src){
    int distancia[V];
    int i, j;
    // Inicializar o array de distancias entre o vertice fonte e todos os
    // outros com INFINITO
    for (i = 0; i < V; i++){
        distancia[i]   = INT_MAX;
    }
    // A menor distancia entre o vertice fonte e ele mesmo sempre sera zero
    distancia[src] = 0;
    
    // Verifica se o caminho encontrado e menor do que o armazenado no 
    // array de distancias, se for menor salva o novo caminho
    // Esse passo executa para pesos positivos
    for (int u = 0; u < V; u++){
        for (int v = 0; v < V; v++){
            if (grafo[u][v] && distancia[u] != INT_MAX && distancia[u] + grafo[u][v] < distancia[v]){
				distancia[v] = distancia[u] + grafo[u][v];
			}
                
        }
    }
    
    // Checar se existe um ciclo negativo. Como o passo acima so 
    // executa para pesos positivos, se encontrar um caminho mais 
    // curto e porque existe um ciclo negativo 
    hasCicloNegativo(grafo, distancia);
    return;
}

int main(){
    // Criando um grafo para exemplo
    int grafo[V][V] = {{0,  1,  100, 0},
                       {0,  0,    0, 1},
                       {0, -5000, 0, 0},
                       {0,  0,    0, 0}
    };
    // Executa o Bellman-Ford
    BellmanFord(grafo, 0);

    return 0;
}
