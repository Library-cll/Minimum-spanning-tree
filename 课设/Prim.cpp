#pragma once

#include "MGraph.h"
#include <stdlib.h>

int MinWeight(Record a[])
{
	int Min=0;
    float temp=INFINITY;
	for(int i=1;i<MAX_VERTEX_NUM;i++)
    {
        if(a[i].weight<temp&&a[i].weight>0)
        {
            temp=a[i].weight;
            Min=i;
        }
    }
    return Min;
}

void MinSpanTree_PRIM(MGraph &G)
{
	recordList record;
	EdgeData Save[MAX_VERTEX_NUM];
	int index=0;
    int a=0;
	float costsum=0;
    for(int i=0;i<G.vexnum;i++)
    {
        if(a!=i)
        {
			record[i].data=G.CityName[a];
			record[i].weight=G.Cost[a][i];
        }
    }
    record[a].weight=0;
	printf("***************************通信网络构建成本最小方案*********************************\n");
    for(int i=1;i<G.vexnum;i++)
    {
        a=MinWeight(record);

		printf("%12s    <---->    %-12s     通信成本：%.2f\n",record[a].data.str,G.CityName[a].str,record[a].weight);
		costsum+=record[a].weight;
		/*Save[index].end=LocateVex(G,G.CityName[a].str);
		Save[index].start=LocateVex(G,record[a].data.str);
		Save[index].weight=record[a].weight;
		index++;*/
        record[a].weight=0;
        for(int i=0;i<G.vexnum;i++)
        {
			if(G.Cost[a][i]<record[i].weight)
            {
				record[i].data=G.CityName[a];
				record[i].weight=G.Cost[a][i];
            }
        }
	}
	/*printf("*************************通信网络构建成本最小方案(Prim算法)**************************\n");
    for (int i = 0; i < index; i++)
	{
		costsum+=Save[i].weight;
		printf("%10s    <---->    %-10s     通信成本：%.2f\n", G.CityName[Save[i].start].str, G.CityName[Save[i].end].str,Save[i].weight);
	}*/
	printf("通信网络构建最小成本为%.3f\n",costsum);
	 
}
