#pragma once
#define MAXVEXS 20

typedef char VertexType;
typedef int EageType;

typedef struct EageNode
{
	int adjvex;
	EageType weight;
	struct EageNode *next;
}EageNode;

typedef struct VexNode
{
	int in;
	VertexType data;
	EageNode *firsteage;
}VexNode, AdjList[MAXVEXS];

typedef struct
{
	AdjList adjList;
	int vexNum, eageNum;
}GraphAdjList;


void CreateGraphAdjList(GraphAdjList *G);

