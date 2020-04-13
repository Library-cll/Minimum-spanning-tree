#pragma once

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "MGraph.h"


void View(int _bool)
{
	printf("***************************通信网络构建最小成本计算系统**************************************\n");
	printf("*                                                                                           *\n");
	printf("*                           【1】输入城市信息");
	if(_bool)
	{
		                                         printf("（已完成）                                     *\n");
	}
	else
	{
		                                         printf("（未完成）                                     *\n");
	}
	printf("*                           【2】Prim算法求通信网络构建最小成本                             *\n");
	printf("*                           【3】Kruskal算法求通信网络构建最小成本                          *\n");
	printf("*                           【4】退出系统                                                   *\n");
	printf("*                                                                                           *\n");
	printf("*********************************************************************************************\n");
}

void InitialiseWin()
{
	system("color 0a");
}

int InitialiseVer(MGraph &G)
{
	printf("***************************输入城市的信息*********************************\n");
	G.arcnum=0;
	G.vexnum=0;
	int num=0;
	printf("输入城市数量(大于1)：");
	while(1)
	{
		scanf("%d",&num);
		//printf("%d ",num);
		fflush(stdin);
		if(num>1)
		{
			system("CLS");
			break;
		}
		else
		{
			printf("输入不合法，请重新输入:");
		}
	}
	int _bool=1;
	int index=0;
	printf("***************************输入城市的信息*********************************\n");
	for(int i=0;i<num;i++,G.vexnum++)
	{
		if(_bool)
		{
			printf("输入第%d个城市编号:",i+1);
		}
		else
		{
			printf("城市名称重复，");
			printf("请重新输入第%d个城市编号:",i+1);
		}
		char temp;
		int num=0;
		while((temp=getchar())!='\n')
		{
			G.CityName[i].Num[num++]=temp;
		}
		G.CityName[i].Num[num]='\0';
		fflush(stdin);
		//scanf("%s",G.CityName[i].Num);
		//fflush(stdin);
		if(_bool)
		{
			printf("输入第%d个城市名称:",i+1);
		}
		else
		{
			printf("城市名称重复，");
			printf("请重新输入第%d个城市名称:",i+1);
		}
		_bool=1;
		num=0;
		while((temp=getchar())!='\n')
		{
			G.CityName[i].str[num++]=temp;
		}
		G.CityName[i].str[num]='\0';
		fflush(stdin);
		//scanf_s("%s",G.CityName[i].str,MaxSize);
		index=LocateVex(G,G.CityName[i].str);
		if(index!=-1)
		{
			_bool=0;
			G.vexnum--;
			i--;
		}
	}
	system("cls");
	return 0;
}

void InitialiseArc(MGraph &G)
{
	for(int i=0;i<MAX_VERTEX_NUM;i++)
	{
		for(int j=0;j<MAX_VERTEX_NUM;j++)
		{
			G.Cost[i][j]=INFINITY;
		}
	}
}

int LocateVex(MGraph &G,char str[])
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(strcmp(G.CityName[i].str,str)==0)
		{
			return i;
		}
	}
	return -1;
}

int CreateMGraph(MGraph &G)
{
	//InitialiseWin();
	InitialiseVer(G);
	InitialiseArc(G);
	int v1=0,v2=0;
	float weight=0;
	printf("***************************输入城市间的通信成本***************************\n");
	for(int i=0;i<G.vexnum;i++)
	{
		for(int j=i+1;j<G.vexnum;j++)
		{
			printf("%10s    <---->    %-10s之间的通信成本为(仅数字为有效输入，其余视为不连通):",G.CityName[i].str,G.CityName[j].str);
			scanf("%f",&weight);
			fflush(stdin);
			if(weight>0)
			{
				v1=LocateVex(G,G.CityName[i].str);
				v2=LocateVex(G,G.CityName[j].str);

				G.Cost[v1][v2]=weight;
				G.Cost[v2][v1]=weight;
				G.arcnum+=1;
			}
		}
	}
	system("cls");
	return 0;
}

void Print(MGraph &G)
{
	for(int i=0;i<G.vexnum;i++)
	{
		for(int j=0;j<G.vexnum;j++)
		{
			printf("%.1f ",G.Cost[i][j]);
		}
		printf("\n");
	}
}