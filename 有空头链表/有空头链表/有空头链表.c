#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int id;
	struct Node* next;
}Node;

Node* Head = NULL;
Node* End = NULL;

//��������
void display()
{
	if (Head->next == NULL)
	{
		printf("����Ϊ�գ�\n");
		return;
	}

	Node* pTemp = Head->next;//�Ƚ�pTempָ���Ƶ���һ�������ݵĽ��
	while (pTemp != NULL)
	{
		printf("%d\t", pTemp->id);
		pTemp = pTemp->next;
	}
	printf("\n");
}

//β���
void Addtail(int a)
{
	//�����㲢��ʼ��
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = a;
	p->next = NULL;
	
	End->next = p; //������
	End = p; //����β���

}

//ͷ���
void Addhead(int a)
{
	//�����㲢��ʼ��
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = a;
	p->next = NULL;

	p->next = Head->next;
	Head->next = p;
	//���ԭ������Ϊ�գ������Ҫ����βָ��
	if (End == Head)
	{
		End = p;
	}

}

//�����Ȼ�ȡ
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

//����λ����ӽ��
void InsertNode(int index, int a)
{
	if (Head->next == NULL)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	if (index > ListLength())
	{
		printf("����λ��Խ�磡\n");
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
	//��Ϊ���м���룬���ﲻ�ÿ��ǲ嵽�������������   ���ø���Endָ��
}
int main()
{
	//��ʼ�����յ�ͷ���
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
		//printf("%d", End->id);  //��ȡ�����β��㡢
	
	printf("�����еķǿսڵ�����%d\n", ListLength());
	InsertNode(3, 6);

	display();
	printf("%d", End->id);  //��ȡ�����β��㡢





	return 0;
}