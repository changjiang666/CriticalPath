#pragma once
#include "GraphAdjList.h"
#define ERROR	0
#define	OK  	1

typedef int Status;


Status TopologicalSort(GraphAdjList *G);
void CriticalPath(GraphAdjList *G);

