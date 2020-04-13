#pragma once

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "MGraph.h"


void View(int _bool)
{
	printf("***************************ͨ�����繹����С�ɱ�����ϵͳ**************************************\n");
	printf("*                                                                                           *\n");
	printf("*                           ��1�����������Ϣ");
	if(_bool)
	{
		                                         printf("������ɣ�                                     *\n");
	}
	else
	{
		                                         printf("��δ��ɣ�                                     *\n");
	}
	printf("*                           ��2��Prim�㷨��ͨ�����繹����С�ɱ�                             *\n");
	printf("*                           ��3��Kruskal�㷨��ͨ�����繹����С�ɱ�                          *\n");
	printf("*                           ��4���˳�ϵͳ                                                   *\n");
	printf("*                                                                                           *\n");
	printf("*********************************************************************************************\n");
}

void InitialiseWin()
{
	system("color 0a");
}

int InitialiseVer(MGraph &G)
{
	printf("***************************������е���Ϣ*********************************\n");
	G.arcnum=0;
	G.vexnum=0;
	int num=0;
	printf("�����������(����1)��");
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
			printf("���벻�Ϸ�������������:");
		}
	}
	int _bool=1;
	int index=0;
	printf("***************************������е���Ϣ*********************************\n");
	for(int i=0;i<num;i++,G.vexnum++)
	{
		if(_bool)
		{
			printf("�����%d�����б��:",i+1);
		}
		else
		{
			printf("���������ظ���");
			printf("�����������%d�����б��:",i+1);
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
			printf("�����%d����������:",i+1);
		}
		else
		{
			printf("���������ظ���");
			printf("�����������%d����������:",i+1);
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
	printf("***************************������м��ͨ�ųɱ�***************************\n");
	for(int i=0;i<G.vexnum;i++)
	{
		for(int j=i+1;j<G.vexnum;j++)
		{
			printf("%10s    <---->    %-10s֮���ͨ�ųɱ�Ϊ(������Ϊ��Ч���룬������Ϊ����ͨ):",G.CityName[i].str,G.CityName[j].str);
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