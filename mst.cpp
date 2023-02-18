#include	<stdio.h>
#include	<stdlib.h>

#include	"graph.h"
#include	"mst.h"

GraphType	*mst_greedy(GraphType *g)
{
	int	edges=0;
	int	n, *u;
	int	minU;

	n= g->n;
	u= new int[n];

	for(int i=0;i<n;i++)		u[i]= 0;

	u[0]= 1;
	minU= 0;
	GraphType *t=new GraphType;
	graph_init(t,n);
	
	while(edges != n-1){
		int		minV= -1; 
		int 	minE= 0;

		GraphNode	*node= g->adj_list[minU];
		while(node != NULL){
			if(u[node->vertex] == 0){
				if(node->weight < minE || minV < 0){
					minE= node->weight;
					minV= node->vertex;
				}
			}
			node= node->link;
		}

		u[minV]= 1;
		edges++;
		insert_edge(t, minU, minV, minE);
		minU= minV;
	}

	delete[] u;
	return t;
}

GraphType	*mst_prim(GraphType *g)
{
	//do programming
}