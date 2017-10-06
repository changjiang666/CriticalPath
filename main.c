#include "CriticalPath.h"
#include "GraphAdjList.h"

main(void)
{
	GraphAdjList G;
	CreateGraphAdjList(&G);

	CriticalPath(&G);

	system("pause");
	return 0;
}