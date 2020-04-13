#pragma once

#include "MGraph.h"
#include <stdlib.h>


EdgeData* get_edges(MGraph &G)
{
    int i,j;
    int index=0;
    EdgeData *edges;

	edges = (EdgeData*)malloc(G.arcnum*sizeof(EdgeData));
    for (i=0;i<G.vexnum;i++)
    {
        for (j=i+1;j<G.vexnum;j++)
        {
			if (G.Cost[i][j]!=INFINITY)
            {
				edges[index].start=i;
                edges[index].end=j;
				edges[index].weight=G.Cost[i][j];
                index++;
            }
        }
    }

    return edges;
}


void sorted_edges(EdgeData* edges, int elen)
{
    int i,j;

    for (i=0; i<elen; i++)
    {
        for (j=i+1; j<elen; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                
                EdgeData temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}


int get_end(int vends[], int i)
{
    while (vends[i] != 0)
        i = vends[i];
    return i;
}


void kruskal(MGraph &G)
{
    int m,n,p1,p2;
    float length;
    int index = 0;          // 索引
	int vends[MAX_VERTEX_NUM]={0};     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
	EdgeData rets[MAX_VERTEX_NUM];        // 结果数组，保存kruskal最小生成树的边
    EdgeData *edges;           // 图对应的所有边

    // 获取"图中所有的边"
    edges = get_edges(G);
    // 将边按照"权"的大小进行排序(从小到大)
    sorted_edges(edges, G.arcnum);

	for (int i=0; i<G.arcnum; i++)
    {
        p1 = edges[i].start;  
        p2 = edges[i].end;    

        m = get_end(vends, p1);                 // 获取p1在"已有的最小生成树"中的终点
        n = get_end(vends, p2);                 // 获取p2在"已有的最小生成树"中的终点
     
        if (m != n)
        {
            vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
            rets[index++] = edges[i];           // 保存结果
        }
    }
    free(edges);

    // 统计并打印"kruskal最小生成树"的信息
    length = 0;
   
	printf("**********************通信网络构建成本最小方案(Kruskal算法)*****************************\n");
    for (int i = 0; i < index; i++)
	{
		length += rets[i].weight;
		printf("%12s    <---- >   %-12s     通信成本：%.2f\n", G.CityName[rets[i].start].str, G.CityName[rets[i].end].str,rets[i].weight);
	}
    printf("通信网络构建最小成本为%.3f\n",length);
}
