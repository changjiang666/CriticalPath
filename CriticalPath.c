#include "CriticalPath.h"
#include <stdlib.h>
#include <stdio.h>

//声明一些全局变量
int *etv, *ltv;			//事件的最早发生时间和最迟发生时间
int *stack2;			//用于存储拓扑排序序列的结果
int top2;				//stack2的栈顶指针

Status TopologicalSort(GraphAdjList *G)
{
	//定义变量
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

			//构造etv表
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