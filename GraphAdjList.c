#include "GraphAdjList.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGraphAdjList(GraphAdjList *G)
{
	int i, j, k,w;
	EageNode *e;
	printf("���붥�����ͱ�����");
	scanf_s("%d,%d", &G->vexNum, &G->eageNum);
	getchar();


	printf("���붥����Ϣ:");
	for (i = 0; i < G->vexNum; ++i)
	{
		scanf_s("%c", &G->adjList[i].data);
		G->adjList[i].firsteage = NULL;
		G->adjList[i].in = 0;
	}
	getchar();


	for (k = 0; k < G->eageNum; ++k)
	{
		printf("����ߣ�Vi,Vj���Ķ������У��Լ�Ȩֵ��");
		scanf_s("%d,%d,%d", &i, &j, &w);
		e = (EageNode *)malloc(sizeof(EageNode));
		e->adjvex = j;
		e->weight = w;
		e->next = G->adjList[i].firsteage;
		G->adjList[i].firsteage = e;
		++G->adjList[j].in;
	}
}
