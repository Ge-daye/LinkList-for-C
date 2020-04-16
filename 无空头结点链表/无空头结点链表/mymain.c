#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int id;

	struct Node* next;
}Node;

Node* Head = NULL;
Node* End = NULL;

//从尾部添加节点的函数
void AddNodetail(int a)
{
	Node* ptemp = (Node*)malloc(sizeof(Node));//为新结点申请空间，并用ptemp指向它
	ptemp->id = a;
	ptemp->next = NULL;
	if (Head == NULL || End == NULL)
	{
		/*链表中没有东西，即是头 也是尾*/
		Head = ptemp;//为头结点赋值
		End = ptemp;//更新尾部结点指针
	}
	else
	{
		End->next = ptemp;
		End = ptemp;
	}

}

//从头部添加结点的函数
void AddNodeHead(int a)
{
	Node* ptemp = (Node*)malloc(sizeof(Node));
	ptemp->id = a;
	ptemp->next = NULL;
	if (Head == NULL)
	{
		Head = ptemp;
		End = ptemp;
	}
	else {
		ptemp->next = Head;
		Head = ptemp;

	}
}

//查找指定的元素，返回该节点

Node* searchNode(int a)
{
	Node* pTemp = Head;
	while (pTemp != NULL)
	{
		if (pTemp->id == a)
		{
			return pTemp;
		}
		pTemp = pTemp->next;
	}
	return NULL;
}

void InsertNode(int index, int a)
{
	if (Head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	if (index>Listlength() )
	{
		printf("索引越界！\n");
			return;
	}
	Node* pTemp = Head;
	Node* p = (Node*)malloc(sizeof(Node));//为插入的a申请结点
	p->id = a;
	p->next = NULL;

	//在前index-1个结点都使pTemp后移
	for (int i = 1; i < index; i++)
	{
		pTemp = pTemp->next;
	}
	p->next = pTemp->next;
	pTemp->next = p;

}

//遍历链表
void display()
{
	Node* p = Head;
	if (Head == NULL)
	{
		printf("该链表为空！\n");
	}
	while (p != NULL)
	{
		printf("%d\t", p->id);
		p = p->next;
	}
	printf("\n");
}

//清空链表
void freelist()
{
	if (Head == NULL)
	{
		printf("链表为空的！");
		return;
	}

	/*while (Head != NULL)
	{
		Node* ptemp = Head;
		Head = Head->next;
		free(ptemp);
	}*/
	Node* p = Head;
	while (p != NULL)
	{
		Node* pTemp = p;
		p = p->next;
		free(pTemp);
	}
	Head = NULL;
	End = NULL;
}

//删除指定的节点
void  delete(int flag)
{
	Node* p = Head;
	Node* pTemp = Head;
	if (p == NULL)
	{
		printf("链表为空的！");
		return;
	}
	//如果第一个
	if (p != NULL && p->id == flag)
	{
		Head = Head->next;
		free(p);
		return;//如果没有这行，会有警告，它防止p被释放 ，然后在后边就不能用p了
	}
	p = p->next;//让p指针后移一个，保证pTemp始终在p前面
	while (p != NULL)
	{
		if (p->id == flag)
		{

		}

	}

}

//链表长度查询
int Listlength()
{
	int n = 0;
	Node* p = Head;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
int main()
{

	AddNodetail(1);
	AddNodetail(2);
	AddNodetail(3);
	AddNodetail(4);
	AddNodetail(5);
	printf("尾添加的结果：\n");
	display();
	AddNodeHead(6);
	AddNodeHead(7);
	AddNodeHead(8);
	printf("头添的结果：\n");
	display();

	printf("\n");
	Node* p = searchNode(2);
	if (p != NULL)
	{
		printf("找到了……\n");
	}
	else {
		printf("没找到!\n");
	}
	freelist();
	display();
	AddNodetail(1);
	AddNodetail(2);
	display();
	int Length = Listlength();
	printf("链表的长度为%d", Length);
	printf("在第2个位置上插上5\n");
	InsertNode(1, 5);
	display();

	return 0;
}