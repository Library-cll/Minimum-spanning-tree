#include "MGraph.cpp"
#include "Kruskal.cpp"
#include "Prim.cpp"

int main()
{
	MGraph Graph;
	int choose=0;
	int _bool=0;
	while(1)
	{
		
		View(_bool);
		printf("�������ѡ��1-4����");
		scanf("%d",&choose);
		fflush(stdin);
		system("CLS");
		switch (choose)
		{
		case 1:CreateMGraph(Graph);_bool=1;
			break;
		case 2:MinSpanTree_PRIM(Graph);
			break;
		case 3:kruskal(Graph);
			break;
		case 4:exit(0);
			break;
		//case -5:Print(Graph);
		//	break;
		default:
			printf("���벻�Ϸ������������룡");
			break;
		}
		system("pause");
		system("CLS");
	}
	return 0;
}
