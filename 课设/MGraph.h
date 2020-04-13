#pragma once

#include <stdio.h>

#define MAX_VERTEX_NUM 100
#define INFINITY 1000000
#define MaxSize 35

typedef struct
{
	char str[MaxSize];
	char Num[MaxSize];

}List[MAX_VERTEX_NUM],CityData;

// 边的结构体
typedef struct EdgeData
{
    int start; // 边的起点
    int end;   // 边的终点
    float weight; // 边的权重
}EdgeData;


typedef struct Record
{
    CityData data;
    float weight;
}recordList[MAX_VERTEX_NUM];


typedef struct 
{
	List CityName;
	float Cost[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
}MGraph;

inline int InitialiseVer(MGraph &G);
inline int CreateMGraph(MGraph &G);
inline void InitialiseArc(MGraph &G);
inline int LocateVex(MGraph &G,char str[]);
inline int MinWeight(Record a[]);
inline void MinSpanTree_PRIM(MGraph &G);
inline EdgeData* get_edges(MGraph &G);
inline void sorted_edges(EdgeData* edges, int elen);
inline int get_end(int vends[], int i);
inline void kruskal(MGraph &G);
inline void InitialiseWin();
inline void View(int _bool);
inline void Print(MGraph &G);