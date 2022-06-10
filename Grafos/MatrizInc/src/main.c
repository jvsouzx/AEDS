#include "incMatrix.h"
#include "search.h"

int main(){

	Graph G = GraphInitialize(10);
	Vertex v1, v2;
	v1 = malloc(sizeof(Vertex));
	v2 = malloc(sizeof(Vertex));

	v1->value = 0; v2->value = 2;
	GraphInsertEdge(G, v1, v2);
	v1->value = 0; v2->value = 1;
	GraphInsertEdge(G, v1, v2);
	v1->value = 1; v2->value = 0;
	GraphInsertEdge(G, v1, v2);
	v1->value = 1; v2->value = 4;
	GraphInsertEdge(G, v1, v2);
	v1->value = 1; v2->value = 5;
	GraphInsertEdge(G, v1, v2);	
	v1->value = 2; v2->value = 0;
	GraphInsertEdge(G, v1, v2);
	v1->value = 2; v2->value = 3;
	GraphInsertEdge(G, v1, v2);
	v1->value = 3; v2->value = 2;
	GraphInsertEdge(G, v1, v2);
	v1->value = 4; v2->value = 1;
	GraphInsertEdge(G, v1, v2);
	v1->value = 4; v2->value = 5;
	GraphInsertEdge(G, v1, v2);
	v1->value = 4; v2->value = 6;
	GraphInsertEdge(G, v1, v2);
	v1->value = 5; v2->value = 1;
	GraphInsertEdge(G, v1, v2);
	v1->value = 5; v2->value = 4;
	GraphInsertEdge(G, v1, v2);
	v1->value = 5; v2->value = 6;
	GraphInsertEdge(G, v1, v2);
	v1->value = 5; v2->value = 7;
	GraphInsertEdge(G, v1, v2);
	v1->value = 6; v2->value = 4;
	GraphInsertEdge(G, v1, v2);
	v1->value = 6; v2->value = 5;
	GraphInsertEdge(G, v1, v2);
	v1->value = 6; v2->value = 7;
	GraphInsertEdge(G, v1, v2);		
	v1->value = 7; v2->value = 6;
	GraphInsertEdge(G, v1, v2);
	v1->value = 7; v2->value = 5;
	GraphInsertEdge(G, v1, v2);

	printf("Grafo:\n");
	ImprimeGraph(G);
	printf("\n");

	v1->value = 0;
	printf("BFS: \n");
	BFS(G, v1);
	printf("\n");
	printf("DFS: \n");
	DFS(G);

	return 0;
}