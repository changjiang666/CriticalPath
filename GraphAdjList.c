#include "GraphAdjList.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGraphAdjList(GraphAdjList *G)
{
	int i, j, k,w;
	EageNode *e;
	printf("输入顶点数和边数：");
	scanf_s("%d,%d", &G->vexNum, &G->eageNum);
	getchar();


	printf("输入顶点信息:");
	for (i = 0; i < G->vexNum; ++i)
	{
		scanf_s("%c", &G->adjList[i].data);
		G->adjList[i].firsteage = NULL;
		G->adjList[i].in = 0;
	}
	getchar();


	for (k = 0; k < G->eageNum; ++k)
	{
		printf("输入边（Vi,Vj）的顶点序列，以及权值：");
		scanf_s("%d,%d,%d", &i, &j, &w);
		e = (EageNode *)malloc(sizeof(EageNode));
		e->adjvex = j;
		e->weight = w;
		e->next = G->adjList[i].firsteage;
		G->adjList[i].firsteage = e;
		++G->adjList[j].in;
	}
}

