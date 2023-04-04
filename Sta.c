#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
typedef struct Sta
{
	char name[20];
	int num;
	int Sale[3];
	int sum;
	float aver;
	struct Sta* next;
}Sta;
int Menu()
{
	int i;
	printf("\t\t\t1.录入员工信息\n");
	printf("\t\t\t2.打印员工信息\n");
	printf("\t\t\t3.员工销售总额排序\n");
	printf("\t\t\t4.查找员工信息\n");
	printf("\t\t\t5.增加员工信息\n");
	printf("\t\t\t6.删除员工信息\n");
	printf("\t\t\t7.修改员工信息\n");
	printf("\t\t\t8.向文件中录入信息\n");
	printf("\t\t\t9.在文件中读取数据输出到屏幕上\n");

	printf("\t\t\tInput your choice: ");
	scanf("%d", &i);
	return i;

}
Sta* CreatNode(int n)//创建链表
{
	int i, j;
	Sta* head;
	Sta* p1, *p2;
	head = p1 = p2=NULL;
	for (i = 1; i < n + 1; i++)
	{
		p1 = (Sta*)malloc(sizeof(Sta));
		p1->sum = 0;
		p1->aver = 0.0;
		printf("\t\t\t");
		scanf("%s", p1->name);
		printf("\t\t\t");
		scanf("%d", &(p1->num));
		for (j = 0; j < 3; j++)
		{
			printf("\t\t\t");
			scanf("%d", &(p1->Sale[j]));
			p1->sum = p1->sum + p1->Sale[j];
		}
		p1->aver =(p1->sum)/3.0;
		p1->next = NULL;
		if (head == NULL)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return head;
}
Sta* CreatfForRead(int n)//文件操作creat
{
	Sta* head = NULL;
	Sta* p1 = NULL;
	Sta*p2 = NULL;
	int i, j;
	for (i = 1; i < n + 1; i++)
	{
		p1 = (Sta*)malloc(sizeof(Sta));
		p1->next = NULL;
		if (head == NULL)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return head;

}
void Print(Sta *head,int n)//打印函数
{
	int j;
	if (head == NULL)
	{
		printf("nothing number");
		exit(-1);
	}
	Sta* p = head;
	while (p != NULL)
	{
		printf("\t\t\t");
		printf("%s ", p->name);
		printf("%d ", p->num);
		for (j = 0; j < 3; j++)
		{
			printf("%d ", p->Sale[j]);
		}
		printf("%d %f", p->sum, p->aver);
		printf("\n");
		p = p->next;
	}
}
Sta* SortBySum(Sta* head)//按销售总额进行排序
{
	Sta* endpt;    
	Sta* p;        
	Sta* p1, * p2;

	p1 = (Sta*)malloc(sizeof(Sta));
	p1->next = head;        
	head = p1;                 

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum > p1->next->next->sum)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;             
	head = head->next;       
	free(p1);          
	p1 = NULL;

	return head;
}
Sta* AddNode(Sta* head, int p)//增加员工数据
{
	Sta* p1, * p2;
	p1 =NULL;
	p2 = head;
	for (int i = 1; i < p + 1; i++)
	{
		p1 = (Sta*)malloc(sizeof(Sta));
		p1->sum = 0;
		p1->aver = 0.0;
		printf("\t\t\tInput name,num,sale\n");
		printf("\t\t\t");
		scanf("%s", p1->name);
		printf("\t\t\t");
		scanf("%d", &(p1->num));
		for (int j = 0; j < 3; j++)
		{
			printf("\t\t\t");
			scanf("%d", &(p1->Sale[j]));
			p1->sum = p1->sum + p1->Sale[j];
		}
		p1->aver = (p1->sum) / 3.0;
		p1->next = NULL;
		while (p2->next != NULL)
		{
			p2 = p2->next;
		}
		p2->next = p1;
		p2 = p1;	
	}
	return head;
}
Sta* Searchbyname(Sta* head, char* ch)//查找
{
	Sta* p = head;
	int i;
	while (p != NULL)
	{
		if ((strcmp(p->name, ch)) == 0)
		{

			return p;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("seach fail");
		return NULL;
	}
}
void deletedbyname(Sta* head, Sta* pos)//删除员工数据
{
	Sta* p1, * p2;
	int flag = 0;
	p1 = head;
	if (p1->num == pos->num)
	{
		head = p1->next;
		free(p1);
		p1 = NULL;
		return;
	}
	while (p1)
	{
		if (p1->next->num == pos->num)
		{
			p2 = p1->next;
			flag = 1;
			if (p1->next->next == NULL)
			{
				free(p1->next);
				p1->next = NULL;
			}
			else
			{
				p1->next = p1->next->next;
				free(p2);
			}
			printf("\t\t\tdeleted successfully\n");
		}
		if (flag == 0)
		{
			p1 = p1->next;
		}
		else if (flag == 1)
		{
			break;
		}
	}

}
void  WritetoFile(Sta* head, int n)//将每个学生的纪录信息写入文件
{
	Sta* p;
	p = head;
	FILE* fp;
	int i,j;
	printf("\n\n\n");
	if ((fp = fopen("Sta.txt", "w")) == NULL)
	{
		printf("\t\t\tFail to open student.txt\n");
		return;
	}
	fprintf(fp, "%d\n", n);
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%12s%12ld", p->name,p->num);
		for (j = 0; j < 3; j++)
		{
			fprintf(fp, "%12.0d", p->Sale[j]);
		}
		fprintf(fp, "%12.0d%12.0f\n", p->sum, p->aver);

		p = p->next;
	}
	printf("\t\t\tExport Successfully!\n");
	fclose(fp);

}
Sta* ReadfromFile(Sta* head, int* n)
{
	Sta* p;
	FILE* fp;
	int i,j;
	if ((fp = fopen("Sta.txt", "r")) == 0)
	{
		printf("\t\t\tFail To Open File");
		return NULL;
	}
	fscanf(fp, "%d", n);
	head = CreatfForRead(*n);
	p = head;
	for (i = 0; i < *n; i++)
	{
		fscanf(fp, "%12s", p->name);
		fscanf(fp, "%12ld", &(p->num));
		for (j = 0; j < 3; j++)
		{
			fscanf(fp, "%12d", &(p->Sale[j]));
		}
		fscanf(fp, "%12d%12f\n", &(p->sum), &(p->aver));
		p = p->next;
	}
	i = *n;
	printf("\t\t\tImport Successfully!\n");
	Print(head, i);
	return head;
}
int main()
{
	int i;
	int n;
	Sta* head = (Sta*)malloc(sizeof(Sta));
	//Menu();
	while (1)
	{
		i = Menu();
		if (i == 1)
		{
			printf("\t\t\tNumber of people entered\n");
			printf("\t\t\t");
			scanf("%d", &n);
		}
		switch (i)
		{
		case 1:
			system("cls");
			printf("\t\t\tInput name ,num,sale\n");
			head = CreatNode(n);
			break;
		case 2:
			system("cls");
			Print(head, n);
			break;
		case 3:
			system("cls");
			head= SortBySum(head);
			Print(head, n);
			break;
		case 4:
			system("cls");
			char ch[100];
			printf("Input Sta name:\n");
			printf("\t\t\t");
			scanf("%s", ch);
			Sta*pos= Searchbyname(head,ch);
			if (pos != NULL)
			{
				printf("\t\t\t");
				printf("%s ", pos->name);
				printf("%d ", pos->num);
				for (int m = 0; m < 3; m++)
				{
					printf("%d ", pos->Sale[m]);
				}
				printf("\n");
			}
			break;
		case 5:
			system("cls");
			printf("\t\t\tInput add Sta number:\n");
			printf("\t\t\t");
			int p = 0;
			scanf("%d", &p);
			n = n + p;
			head=AddNode(head, p);
			Print(head,n);
			break;
		case 6:
			system("cls");
			printf("\t\t\tEnter the name of the deleted person name:\n");
			char ch1[100];
			printf("\t\t\t");
			scanf("%s", ch1);
			Sta* pos1 = Searchbyname(head, ch1);
			if (pos1 != NULL)
			{
				deletedbyname(head, pos1);
			}
		case 8:
			system("cls");
			WritetoFile(head, n);
			break;
		case 9:
			system("cls");
			head = ReadfromFile(head, &n);
			break;
			
		}
	}
}
