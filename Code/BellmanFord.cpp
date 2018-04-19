// Bellman-Ford em C/C++ para encontrar o menor caminho com arestas negativas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Define o numero de vertices
#define V 4

// Metodo para imprimir a resposta
void mostraSolucao(int distancia[]){
    printf("Vertex   Distance from Source\n");
    int i;
    for (i = 0; i < V; ++i){
		printf("%d \t\t %d\n", i, distancia[i]);
	}
      
}

// Funcao para verificar se tem ciclo negativo e imprimir a resposta
bool hasCicloNegativo(int grafo[V][V], int distancia[]){
    bool resposta = false;
    // Se encontrar um caminho mais curto do que o ja salvo
    // e porque existe um ciclo negativo
    for (int u = 0; u < V; u++){
        for (int v = 0; v < V; v++){
            if (grafo[u][v] && distancia[u] != INT_MAX && distancia[u] + grafo[u][v] < distancia[v])
                resposta = true;
        }
    }
    return resposta;
}

// Metodo para encontrar a menor distancia entre o vertice oriem e
// todos os outros, usando o algoritmo de Bellman-Ford.
// O metodo  tambem detecta ciclos negativos
void BellmanFord(int grafo[V][V], int src){
    int distancia[V];
    int i, j;
    // Inicia o array de distancias entre o vertice fonte e todos os
	// outros com INFINITO
    for (i = 0; i < V; i++){
        distancia[i]   = INT_MAX;
	}
	// A distancia entre o vertice origem e ele mesmo e sempre zero
    distancia[src] = 0;
    
    // Passar por todos os vertices procurando o menor caminho entre o
	// vertice atual e o origem
    for (int u = 0; u < V; u++){
        for (int v = 0; v < V; v++){
			// Verifica se existe aresta, se nao existe caminho entre 
			// o vertice atual e o fonte e se o caminho encontrado e menor 
			// do que o armazenado no array de distancias. Se for
			// salvar o novo caminho
            if (grafo[u][v] && distancia[u] != INT_MAX && distancia[u] + grafo[u][v] < distancia[v]){
                distancia[v] = distancia[u] + grafo[u][v];
			}
        }
    }

	// Mostra a solucao do grafo com pesos negativos mas apenas se nao existir ciclos
	// negativos 
	if(!hasCicloNegativo){   
    		mostraSolucao(distancia);
	}else{
		printf("Contem Ciclo negativo - o programa sera encerrado\n");	
	}
    return;
}

// Metodo principal
int main(){    
    // Criando um grafo na matriz de adjacencia de exemplo
    int grafo[V][V] = {{0,   1,     0, 0},
					   {0,   0, -5000, 1},
		               {100, 0,     0, 1},
		               {0,   0,     0, 0}
    };
    
    // Executando o Bellman-Ford
    BellmanFord(grafo, 0);
    return 0;
}
