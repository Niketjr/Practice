#include <stdio.h>
#include <stdlib.h>

#define max 50

typedef struct Graph{
    int val;
    bool adj[max][max];
}*Graph;

Graph* create(int v){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->val = v;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            g->adj[i][j] = false;
        }
    }
    return g;
}

void Graph_addEdge(Graph* g,int u, int v){
    g->adj[u][v] = true;
    g->adj[v][u] = true;
}

void BFS(Graph* g, int v){
    bool visited[max];
    for(int i=0; i<g->val; i++){
        visited[i] = false;
    }
    visited[v] = true;
    int queue[max];
    int front = 0, rear = 0;
    queue[rear++] = v;
    while(front!=rear){
        int x = queue[front++];
        printf("%d ",x);
        for(int i=0; i<g->val; i++){
            if(g->adj[x][i] == 1 && visited[i]==0){
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void DFS(Graph* g, int u){
    bool visited[max];
    for(int i=0; i<g->val; i++){
        visited[i] = false;
    }
    if(visited[u] == 0){
        printf("%d ",u);
        visited[u] = true;
        for(int v=0; v<g->val; v++){
            if(g->adj[u][v]==1 && visited[v]==0){
                DFS(g,v);
            }
        }
    }
}

int main(){
    Graph* g = create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 3);
	
	BFS(g, 2);
	DFS(g, 2);
	
    return 0;
}
