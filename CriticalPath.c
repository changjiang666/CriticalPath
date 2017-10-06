#include "CriticalPath.h"
#include <stdlib.h>
#include <stdio.h>

//����һЩȫ�ֱ���
int *etv, *ltv;			//�¼������緢��ʱ�����ٷ���ʱ��
int *stack2;			//���ڴ洢�����������еĽ��
int top2;				//stack2��ջ��ָ��

Status TopologicalSort(GraphAdjList *G)
{
	//�������
	int i, gettop;
	int count = 0;
	EageNode *e;

	int top = 0;
	int *stack;
	stack = (int *)malloc(MAXVEXS * sizeof(int));

	stack2 = (int *)malloc(MAXVEXS * sizeof(int));
	top2 = 0;

	etv = (int *)malloc(G->vexNum * sizeof(int));
	for (i = 0; i < G->vexNum; ++i)
		etv[i] = 0;
	
	for (i = 0; i < G->vexNum; ++i)
	{
		if (0 == G->adjList[i].in)
			stack[++top] = i;
	}

	while (top != 0)
	{
		gettop = stack[top--];
		stack2[++top2] = gettop;
		//printf("%c", G->adjList[gettop].data);
		++count;
		for (e = G->adjList[gettop].firsteage; e; e = e->next)
		{
			if (!(--G->adjList[e->adjvex].in))
				stack[++top] = e->adjvex;

			//����etv��
			if (etv[e->adjvex] < e->weight + etv[gettop])
				etv[e->adjvex] = e->weight + etv[gettop];
		}
	}

	if (G->vexNum == count)
		return OK;
	else
		return ERROR;

}

void CriticalPath(GraphAdjList *G)
{
	int gettop;
	int ete, lte;
	int i, k;
	EageNode *e;

	TopologicalSort(G);
	ltv = (int *)malloc(G->vexNum * sizeof(int));
	for (i = 0; i < G->vexNum; ++i)
		ltv[i] = etv[G->vexNum - 1];

	while (top2 != 0)
	{
		gettop = stack2[top2--];
		for (e = G->adjList[gettop].firsteage; e; e = e->next)
		{
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	
	for (i = 0; i < G->vexNum; ++i)
	{
		for (e = G->adjList[i].firsteage; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[i];
			lte = ltv[k] - e->weight;

			if (ete == lte)
				printf("<%d ,%d>:%d\n", i, k, e->weight);
		}
	}
}