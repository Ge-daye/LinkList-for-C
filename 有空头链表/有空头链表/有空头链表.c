#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int id;
	struct Node* next;
}Node;

Node* Head = NULL;
Node* End = NULL;

//遍历链表
void display()
{
	if (Head->next == NULL)
	{
		printf("链表为空！\n");
		return;
	}

	Node* pTemp = Head->next;//先将pTemp指针移到第一个有数据的结点
	while (pTemp != NULL)
	{
		printf("%d\t", pTemp->id);
		pTemp = pTemp->next;
	}
	printf("\n");
}

//尾添加
void Addtail(int a)
{
	//申请结点并初始化
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = a;
	p->next = NULL;
	
	End->next = p; //连接上
	End = p; //更新尾结点

}

//头添加
void Addhead(int a)
{
	//申请结点并初始化
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = a;
	p->next = NULL;

	p->next = Head->next;
	Head->next = p;
	//如果原本链表为空，添加完要更新尾指针
	if (End == Head)
	{
		End = p;
	}

}

//链表长度获取
int ListLength()
{
	int n = 0;
	Node* p = Head->next;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//任意位置添加结点
void InsertNode(int index, int a)
{
	if (Head->next == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	if (index > ListLength())
	{
		printf("插入位置越界！\n");
		return;
	}
	Node* pTemp = Head->next;
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = a;
	p->next = NULL;
	for (int  i = 1; i < index-1; i++)
	{
		pTemp = pTemp->next;
	}
	p->next = pTemp->next;
	pTemp->next = p;
	//因为是中间插入，这里不用考虑插到链表最后面的情况   不用更新End指针
}
int main()
{
	//初始化，空的头结点
	Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	End = Head;
	/*Addtail(1);
	Addtail(2);
	Addtail(3);
	Addtail(4);
	Addtail(5);*/
	Addhead(1);
	Addhead(2);
	Addhead(3);
	display();
		//printf("%d", End->id);  //获取链表的尾结点、
	
	printf("链表中的非空节点数：%d\n", ListLength());
	InsertNode(3, 6);

	display();
	printf("%d", End->id);  //获取链表的尾结点、





	return 0;
}