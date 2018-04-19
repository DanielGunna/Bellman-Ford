// Dijkstra em C/C++ para encontrar o menor caminho
#include <stdio.h>
#include <limits.h>

// Numero de vertices do Grafo
#define V 9

// Funcao para encontrar o vertice de menor distancia entre o conjunto de vertices
// ainda nao visitados 
// nao incluido no conjunto de menor caminho
int distanciaMin(int distancia[], bool visitado[]){
   // Inicializa o valor minimo
   int min = INT_MAX;
   int min_index;
	//Percorrer o grafo procurando o vertice nao vistado
	//de menor distancia
	for (int i = 0; i < V; i++){
		if (visitado[i] == false && distancia[i] <= min){
			min = distancia[i];
			min_index =i;
		}
	}
    return min_index;
}

// Metodo p/ imprimir o array de distancia
void mostraSolucao(int distancia[], int n){
   printf("Vertice  Distancia do vertice fonte\n");
   for (int i = 0; i < V; i++){
      printf("%d \t\t %d\n", i, distancia[i]);
   }
}

// Implementacao do  Dijkstra, para matriz de adjacencia
void dijkstra(int grafo[V][V], int src){
     int distancia[V];  // Array para guardar a distancia mais curta entre src
						// e o vertice i 

     bool visitado[V];  // visitado[i] sera true se o vertice ja estiver incluido 
						// na arvore de menor caminho 

     // Inicializa a distancia de todos os vertice com  INFINITO 
	 //e false no array  visitados p/ todos os vertice
     for (int i = 0; i < V; i++){
        distancia[i] = INT_MAX, visitado[i] = false;
	 }

     // Distancia entre o vertice origem  e ele mesmo sempre sera 0
     distancia[src] = 0;

     // Encontra o menor caminho para todos os vertices
     for (int i = 0; i < V-1; i++){
		// Pega a menor distancia apartir do conjunto de vertices nao processados
		// u sempre possui o valor de src na primeira iteracao
		int u = distanciaMin(distancia, visitado);
       // Marca o vertice escolhido como visitado
       visitado[u] = true;
       // Atualiza o valor da distancia do vertice escolhido com os vertices adjacentes
       for (int j = 0; j < V; j++){
         // Atualiza a distancia[j] somente se ele nao foi visitado e 
		 // se existe uma aresta de u para j e 
		 // se o peso total do caminho da fonte para j passando por u e
		 // menor do que a distancia[j]
			if (!visitado[j] && grafo[u][j] 
						  && distancia[u] != INT_MAX 
						  && distancia[u]+grafo[u][j] < distancia[j]){
				distancia[j] = distancia[u] + grafo[u][j];
		
			}
		}
	}
     // Imprime o array de distancias
     mostraSolucao(distancia, V);
}

//Metodo principal
int main()
{
   // Grafo de exemplo
   int grafo[V][V] = {{0,  4,  0,  0,  0,  0,  0,  8,  0},
                      {4,  0,  8,  0,  0,  0,  0,  11, 0},
                      {0,  8,  0,  7,  0,  4,  0,  0,  2},
                      {0,  0,  7,  0,  9,  14, 0,  0,  0},
                      {0,  0,  0,  9,  0,  10, 0,  0,  0},
                      {0,  0,  4,  0,  10, 0,  2,  0,  0},
                      {0,  0,  0,  14, 0,  2,  0,  1,  6},
                      {8,  11, 0,  0,  0,  0,  1,  0,  7},
                      {0,  0,  2,  0,  0,  0,  6,  7,  0}};
	// Executa Dijkstra para o grafo acima
    dijkstra(grafo, 0);
    return 0;
}


