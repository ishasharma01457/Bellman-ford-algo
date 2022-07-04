#include<iostream>
#include <conio.h>
#include <bits/stdc++.h>
struct Edge {
	int src, dest, weight;
};
struct Graph {
	int V, Y;
   struct Edge* edge;
};
struct Graph* createGraph(int V, int Y)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->Y = Y;
	graph->edge = new Edge[Y];
	return graph;
}
void print(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}
void Bellman(struct Graph* graph, int src)
{
	int V = graph->V;
	int Y = graph->Y;
	int dist[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < Y; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX
				&& dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}
	for (int i = 0; i < Y; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX
			&& dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return;
		}
	}

	print(dist, V);

	return;
}
int main()
{
    	int V = 3;
	int Y = 5;
	struct Graph* graph = createGraph(V, Y);
    graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;
	Bellman(graph, 0);

	return 0;
}


