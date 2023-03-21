#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define   MAX_LEN 10                	   //字符串最大长度
#define   STU_NUM 30                       // 最多的学生人数 
#define   COURSE_NUM 6                     // 最多的考试科目数 
#define   LEN sizeof(struct Student)       //结构体大小

//定义结构体
typedef struct student
{
	long num;                              //学生学号
	char name[MAX_LEN];                    //姓名
	float score[COURSE_NUM];               //学生course_num门功课的成绩
	float sum;                             //总成绩
	float aver;                            //平均成绩
	struct student* next;                  //指向下一个学生成绩的指针
}STU;

//函数接口
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
//主函数
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
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):\n"); //输入学生数
			printf("\t\t\t");
			scanf_s("%d", &n);
			printf("\t\t\tInput course number(m<=6):\n");
			printf("\t\t\t");
			scanf_s("%d", &m);
		}
		switch(i)
		{
			case 1:
				printf("\t\t\tInput name，student's ID and score:\n");
				head = CreatListNode(n,m);//录入学生信息
				system("cls");
				break;
			case 2:
				system("cls");
				AverSumofEveryCourse(head, n, m);//计算没科成绩的总成绩和平均成绩
				break;
			case 3:
				system("cls");
				AverSumofEveryStudent(head, n, m);//计算每个学生的总成绩
				break;
			case 4:
				system("cls");
				printf("\t\t\tSort in ascending order by score:\n");
				head = AscendSortbyScore(head, n);//升序排总成绩
				print1(head, n, m);
				break;
			case 5:
				system("cls");
				printf("\t\t\tSort in ascending order by score:\n");
				head = DeSortbyScore(head, n);//降序排成绩
				print1(head, n, m);
				break;
			case 6:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\tSort in ascending order by number:\n");
				head = SortbyNum(head);//升序排学号
				print1(head, n, m);
				break;
			case 7:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\tSort in ascending order by name:\n");
				head = SortbyName(head);//按字母顺序排
				print1(head, n, m);
			case 8:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t******************************************************************************\n");
				printf("\t\t\tInput the number you want to search:\n");
				SearchbyNum(head,n,m);//按学号搜索
				break;
			case 9:
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t******************************************************************************\n");
				printf("\t\t\tInput the name you want to search:\n");
				SearchbyName(head, n, m);//按姓名搜索
				break;
			case 10:
				system("cls");  
				printf("\n\n\n");
				print1(head, n, m);
				break;

			case 11:
				system("cls");  
				WritetoFile(head, n, m);////将每个学生的纪录信息写入文件
				break;
			case 12:
				system("cls");  
				head = ReadfromFile(head, &n, &m);////从文件中读出每个学生的纪录信息并显示
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

//函数定义
int Menu()
{
	int i;
	system("title 学生成绩管理系统 v1.0 Byliugh");
	printf("\n");
	printf("\t\t\t                       学生成绩管理系统V1.0\n");
	printf("\t\t\t*****************************************************************************\n");
	printf("\t\t\t                Management for Students' scores                              \n");
	printf("\t\t\t                1.Input record                                               \n");
	printf("\t\t\t                2.Caculate total and average score of every course           \n");
	printf("\t\t\t                3.Caculate total and average score of every student          \n");
	printf("\t\t\t                4.Sort in descending order by score                          \n");//降序排成绩
	printf("\t\t\t                5.Sort in ascending order by score                           \n");//升序排成绩
	printf("\t\t\t                6.Sort in ascending order by num                             \n");//按学号升序排
	printf("\t\t\t                7.Sort in dictionary order by name                           \n");//按拼音首字母排序
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
//创建链表.录入学生信息
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
			scanf_s("%f", &(p1->score[j]));//回车确定
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
//文件操作creat
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
//求每门课的总成绩和平均成绩
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
			while(p != NULL)//遍历每门课的所有学生的成绩
			{
				sum = sum + p->score[i];
				p = p->next;
			}
			printf("\t\t\tcourse %d:    sum=%.0f , aver=%.0f\n", j, sum, sum / n);
			p = head;//还原p的位置，以计算下一门科目
			j++;
		}
		printf("\t\t\t******************************************************************************\n");
	}
}
//每个学生的总成绩和平均成绩
void AverSumofEveryStudent(STU* head,int  n, int  m)//计算每个学生的平均成绩
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
//按总成绩升序
STU* AscendSortbyScore(STU* head, int n)
{
	STU* endpt;    //控制循环比较
	STU* p;        //临时指针变量
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

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

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;

}
//降序排成绩
STU* DeSortbyScore(STU* head, int n)
{
	STU* endpt;    //控制循环比较
	STU* p;        //临时指针变量
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum < p1->next->next->sum)  //如果前面的节点键值比后面节点的键值小，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;

}
//打印函数
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
//按学号排
STU* SortbyNum(STU* head)
{
	STU* endpt;    //控制循环比较
	STU* p;        //临时指针变量
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->num > p1->next->next->num)  //如果前面的节点键值比后面节点的键值小，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}
//按字母排
STU* SortbyName(STU* head)
{
	STU* endpt;    //控制循环比较
	STU* p;        //临时指针变量
	STU* p1, * p2;

	p1 = (STU*)malloc(sizeof(STU));
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name , p1->next->next->name)>0)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;             //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}
//学号搜索
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
//姓名搜索
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
//将学生信息格式化录入文件中
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
//从文件中读出学生记录并打印在屏幕上
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
	//开始在文件中读
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


