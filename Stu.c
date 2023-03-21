#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define   MAX_LEN 10                	   //�ַ�����󳤶�
#define   STU_NUM 30                       // ����ѧ������ 
#define   COURSE_NUM 6                     // ���Ŀ��Կ�Ŀ�� 
#define   LEN sizeof(struct Student)       //�ṹ���С

//����ṹ��
typedef struct student
{
	long num;                              //ѧ��ѧ��
	char name[MAX_LEN];                    //����
	float score[COURSE_NUM];               //ѧ��course_num�Ź��εĳɼ�
	float sum;                             //�ܳɼ�
	float aver;                            //ƽ���ɼ�
	struct student* next;                  //ָ����һ��ѧ���ɼ���ָ��
}STU;

//�����ӿ�
int Menu(void);
STU* CreatListNode(int n, int m);
void AverSumofEveryCourse(STU* head, int n, int m);
void AverSumofEveryStudent(STU* head, int  n, int  m);
STU* AscendSortbyScore(STU* head,int n);
void print1(STU* head,int n,int m);
STU* DeSortbyScore(STU* head, int n);
STU* SortbyNum(STU* head);
STU* SortbyName(STU* head);
void SearchbyNum(STU* head, int n, int m);
void SearchbyName(STU* head, int n, int m);
STU* ReadfromFile(STU* head, int *n, int *m);
STU* Creat1(int n, int m);
void  WritetoFile(STU* head, int n, int m);
//������
int main()
{
	int n, m;
	int i;
	STU* head = (STU*)malloc(sizeof(STU));
	while (1)
	{
		i = Menu();
		if (i == 1)
		{
			system("cls");  //����
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):\n"); //����ѧ����
			printf("\t\t\t");
			scanf_s("%d", &n);
			printf("\t\t\tInput course number(m<=6):\n");
			printf("\t\t\t");
			scanf_s("%d", &m);
		}
		switch(i)
		{
			case 1:
				printf("\t\t\tInput name��student's ID and score:\n");
				head = CreatListNode(n,m);//¼��ѧ����Ϣ
				system("cls");
				break;
			case 2:
				system("cls");
				AverSumofEveryCourse(head, n, m);//����û�Ƴɼ����ܳɼ���ƽ���ɼ�
				break;
			case 3:
				system("cls");
				AverSumofEveryStudent(head, n, m);//����ÿ��ѧ�����ܳɼ�
				break;
			case 4:
				system("cls");
				printf("\t\t\tSort in ascending order by score:\n");
				head = AscendSortbyScore(head, n);//�������ܳɼ�
				print1(head, n, m);
				break;
			case 5:
				system("cls");
				printf("\t\t\tSort in ascending order by score:\n");
				head = DeSortbyScore(head, n);//�����ųɼ�
				print1(head, n, m);
				break;
			case 6:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\tSort in ascending order by number:\n");
				head = SortbyNum(head);//������ѧ��
				print1(head, n, m);
				break;
			case 7:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\tSort in ascending order by name:\n");
				head = SortbyName(head);//����ĸ˳����
				print1(head, n, m);
			case 8:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t******************************************************************************\n");
				printf("\t\t\tInput the number you want to search:\n");
				SearchbyNum(head,n,m);//��ѧ������
				break;
			case 9:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t******************************************************************************\n");
				printf("\t\t\tInput the name you want to search:\n");
				SearchbyName(head, n, m);//����������
				break;
			case 10:
				system("cls");  
				printf("\n\n\n");
				print1(head, n, m);
				break;

			case 11:
				system("cls");  
				WritetoFile(head, n, m);////��ÿ��ѧ���ļ�¼��Ϣд���ļ�
				break;
			case 12:
				system("cls");  
				head = ReadfromFile(head, &n, &m);////���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ
				break;
			case 0:
				system("cls");  
				printf("\n\n\n");
				printf("\t\t\t******************************************************************************\n");
				printf("\t\t\tEnd of program!\n");
				printf("\t\t\t******************************************************************************\n");
				return 0;
			default:
				system("cls"); 
				printf("\n\n\n");
				printf("\t\t\t******************************************************************************\n");
				printf("\t\t\tInput error!\n");
				printf("\t\t\t******************************************************************************\n");
				return 0;
		}
	}
	Menu();
	return 0;
}

//��������
int Menu()
{
	int i;
	system("title ѧ���ɼ�����ϵͳ v1.0 Byliugh");
	printf("\n");
	printf("\t\t\t                       ѧ���ɼ�����ϵͳV1.0\n");
	printf("\t\t\t*****************************************************************************\n");
	printf("\t\t\t                Management for Students' scores                              \n");
	printf("\t\t\t                1.Input record                                               \n");
	printf("\t\t\t                2.Caculate total and average score of every course           \n");
	printf("\t\t\t                3.Caculate total and average score of every student          \n");
	printf("\t\t\t                4.Sort in descending order by score                          \n");//�����ųɼ�
	printf("\t\t\t                5.Sort in ascending order by score                           \n");//�����ųɼ�
	printf("\t\t\t                6.Sort in ascending order by num                             \n");//��ѧ��������
	printf("\t\t\t                7.Sort in dictionary order by name                           \n");//��ƴ������ĸ����
	printf("\t\t\t                8.Search by Number                                           \n");
	printf("\t\t\t                9.Search by name                                             \n");
	printf("\t\t\t                10.List recore                                               \n");
	printf("\t\t\t                11.Write to a file                                           \n");
	printf("\t\t\t                12.Read form a file                                          \n");
	printf("\t\t\t                0.Exit                                                       \n");
	printf("\t\t\t*****************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************Please Input your choice:");
	scanf("%d",&i);
	return i;
}
//��������.¼��ѧ����Ϣ
STU* CreatListNode(int n, int m)
{
	int i, j;
	STU* p1, * p2;
	STU* head;
	head = p1 = p2 = NULL;
	for (i = 1; i < n + 1; i++)
	{
		p1 = (STU*)malloc(sizeof(STU));
		printf("\t\t\t");
		scanf("%s", p1->name);
		printf("\t\t\t");
		scanf("%ld", &(p1->num));
		for (j = 0; j < m; j++)
		{

			printf("\t\t\t");
			scanf_s("%f", &(p1->score[j]));//�س�ȷ��
		}
		p1->next = NULL;
		if (head==NULL)
		{
			head =p2 =p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	
	return head;
}
//�ļ�����creat
STU* Creat1(int n, int m)
{
	STU* head=NULL;
	STU* p1=NULL, * p2=NULL;
	int i, j;
	for (i = 1; i < n + 1; i++)
	{
		p1 = (STU*)malloc(sizeof(STU));
		p1->next = NULL;
		if (head== NULL)
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
//��ÿ�ſε��ܳɼ���ƽ���ɼ�
void AverSumofEveryCourse(STU* head,int n,int m)
{
	STU* p = head;
	int i, j=1;
	float sum;
	if (head!=NULL)
	{
		printf("\t\t\t******************************************************************************\n");
		for (i = 0; i < m; i++)
		{
			sum = 0.0;
			while(p != NULL)//����ÿ�ſε�����ѧ���ĳɼ�
			{
				sum = sum + p->score[i];
				p = p->next;
			}
			printf("\t\t\tcourse %d:    sum=%.0f , aver=%.0f\n", j, sum, sum / n);
			p = head;//��ԭp��λ�ã��Լ�����һ�ſ�Ŀ
			j++;
		}
		printf("\t\t\t******************************************************************************\n");
	}
}
//ÿ��ѧ�����ܳɼ���ƽ���ɼ�
void AverSumofEveryStudent(STU* head,int  n, int  m)//����ÿ��ѧ����ƽ���ɼ�
{
	if (head == NULL)return;
	printf("\n\n\n");
	printf("\t\t\t******************************************************************************\n");
	STU* p = head;
	int i,j;
	for (i = 0; i < n; i++)
	{
		p->sum = 0.0;
		for (j = 0; j < m; j++)
		{
			p->sum = p->sum + p->score[j];
		}
		p->aver = (p->sum) / m;
		printf("\t\t\tstudent %d:    sum=%.0f , aver=%.0f\n", i + 1, p->sum, p->aver);
		p = p->next;
	}
	printf("\t\t\t******************************************************************************\n");
}
//���ܳɼ�����
STU* AscendSortbyScore(STU* head, int n)
{
	STU* endpt;    //����ѭ���Ƚ�
	STU* p;        //��ʱָ�����
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum > p1->next->next->sum)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;

}
//�����ųɼ�
STU* DeSortbyScore(STU* head, int n)
{
	STU* endpt;    //����ѭ���Ƚ�
	STU* p;        //��ʱָ�����
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum < p1->next->next->sum)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵС���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;

}
//��ӡ����
void print1(STU* head, int n, int m)
{
	STU* p = head;
	int i;
	if (head != NULL)
	{
		while (p != NULL)
		{
			printf("\t\t\t%ld\t%s\t", p->num, p->name);
			for (i = 0; i < m; i++)
			{
				printf("%.0f\t", p->score[i]);
			}
			printf("%.0f\t%.0f\n", p->sum, p->sum / m);
			p = p->next;
		}
	}
	printf("\t\t\t******************************************************************************\n");
}
//��ѧ����
STU* SortbyNum(STU* head)
{
	STU* endpt;    //����ѭ���Ƚ�
	STU* p;        //��ʱָ�����
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->num > p1->next->next->num)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵС���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}
//����ĸ��
STU* SortbyName(STU* head)
{
	STU* endpt;    //����ѭ���Ƚ�
	STU* p;        //��ʱָ�����
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name , p1->next->next->name)>0)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;             //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}
//ѧ������
void SearchbyNum(STU* head,int n,int m)
{
	STU* p = head;
	long j = 0;
	int i;
	int flag = 0;
	printf("\t\t\t");
	scanf("%ld", &j);
	while (p != NULL)
	{
		if (p->num == j)
		{
			printf("\t\t\t");
			printf("%ld\t%s\t", p->num, p->name);
			for (i = 0; i < m; i++)
			{
				printf("%.0f\t", p->score[i]);
			}
			printf("%.0f\t%.0f\n", p->sum, p->sum / m);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("\t\t\t");
		printf("Not Found");
	}
	printf("\t\t\t******************************************************************************\n");

}
//��������
void SearchbyName(STU* head, int n, int m)
{
	STU* p = head;
	int i;
	char arr[MAX_LEN];
	int flag = 0;
	printf("\t\t\t");
	scanf("%s", arr);
	while (p != NULL)
	{
		if((strcmp(arr,p->name))==0)
		{
			printf("\t\t\t");
			printf("%ld\t%s\t", p->num, p->name);
			for (i = 0; i < m; i++)
			{
				printf("%.0f\t", p->score[i]);
			}
			printf("%.0f\t%.0f\n", p->sum, p->sum / m);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("\t\t\t");
		printf("Not Found");
	}
	printf("\t\t\t******************************************************************************\n");

}
//��ѧ����Ϣ��ʽ��¼���ļ���
void  WritetoFile(STU* head, int n, int m)
{
	STU* p;
	p = head;
	FILE* fp;
	int i, j;
	printf("\n\n\n");
	printf("\t\t\t******************************************************************************\n");
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("\t\t\tFail to open student.txt\n");
		return;
	}
	fprintf(fp, "%d\t%d\n", n, m);
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%12ld%12s", p->num, p->name);
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%12.0f", p->score[j]);
		}
		fprintf(fp, "%12.0f%12.0f\n", p->sum, p->sum / m);

		p = p->next;
	}
	printf("\t\t\tExport Successfully!\n");
	fclose(fp);
	printf("\t\t\t******************************************************************************\n");

}
//���ļ��ж���ѧ����¼����ӡ����Ļ��
STU* ReadfromFile(STU* head, int* n, int* m)
{
	STU* p;
	FILE* fp;
	int i,j;
	if ((fp = fopen("student.txt", "r")) == 0)
	{
		printf("\t\t\tFail To Open File");
		return NULL;
	}
	//��ʼ���ļ��ж�
	fscanf(fp,"%d\t%d", n, m);
	head = Creat1(*n, *m);
	p = head;
	for (i = 0; i < *n; i++)
	{
		fscanf(fp, "%12ld", &(p->num));
		fscanf(fp, "%12s", p->name);
		for (j = 0; j < *m; j++)
		{
			fscanf(fp, "%12f", &(p->score[j]));
		}
		fscanf(fp, "%12f%12f", &(p->sum), &(p->aver));
		p = p->next;
	}
	i =* n;
	j =* m;
	printf("\t\t\tImport Successfully!\n");
	fclose(fp);
	print1(head, i, j);
	return head;


}


