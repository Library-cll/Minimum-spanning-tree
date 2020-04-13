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
    int index = 0;          // ����
	int vends[MAX_VERTEX_NUM]={0};     // ���ڱ���"������С������"��ÿ�������ڸ���С���е��յ㡣
	EdgeData rets[MAX_VERTEX_NUM];        // ������飬����kruskal��С�������ı�
    EdgeData *edges;           // ͼ��Ӧ�����б�

    // ��ȡ"ͼ�����еı�"
    edges = get_edges(G);
    // ���߰���"Ȩ"�Ĵ�С��������(��С����)
    sorted_edges(edges, G.arcnum);

	for (int i=0; i<G.arcnum; i++)
    {
        p1 = edges[i].start;  
        p2 = edges[i].end;    

        m = get_end(vends, p1);                 // ��ȡp1��"���е���С������"�е��յ�
        n = get_end(vends, p2);                 // ��ȡp2��"���е���С������"�е��յ�
     
        if (m != n)
        {
            vends[m] = n;                       // ����m��"���е���С������"�е��յ�Ϊn
            rets[index++] = edges[i];           // ������
        }
    }
    free(edges);

    // ͳ�Ʋ���ӡ"kruskal��С������"����Ϣ
    length = 0;
   
	printf("**********************ͨ�����繹���ɱ���С����(Kruskal�㷨)*****************************\n");
    for (int i = 0; i < index; i++)
	{
		length += rets[i].weight;
		printf("%12s    <---- >   %-12s     ͨ�ųɱ���%.2f\n", G.CityName[rets[i].start].str, G.CityName[rets[i].end].str,rets[i].weight);
	}
    printf("ͨ�����繹����С�ɱ�Ϊ%.3f\n",length);
}
