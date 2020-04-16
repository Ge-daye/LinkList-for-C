#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int id;

	struct Node* next;
}Node;

Node* Head = NULL;
Node* End = NULL;

//��β����ӽڵ�ĺ���
void AddNodetail(int a)
{
	Node* ptemp = (Node*)malloc(sizeof(Node));//Ϊ�½������ռ䣬����ptempָ����
	ptemp->id = a;
	ptemp->next = NULL;
	if (Head == NULL || End == NULL)
	{
		/*������û�ж���������ͷ Ҳ��β*/
		Head = ptemp;//Ϊͷ��㸳ֵ
		End = ptemp;//����β�����ָ��
	}
	else
	{
		End->next = ptemp;
		End = ptemp;
	}

}

//��ͷ����ӽ��ĺ���
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

//����ָ����Ԫ�أ����ظýڵ�

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
		printf("����Ϊ�գ�\n");
		return;
	}
	if (index>Listlength() )
	{
		printf("����Խ�磡\n");
			return;
	}
	Node* pTemp = Head;
	Node* p = (Node*)malloc(sizeof(Node));//Ϊ�����a������
	p->id = a;
	p->next = NULL;

	//��ǰindex-1����㶼ʹpTemp����
	for (int i = 1; i < index; i++)
	{
		pTemp = pTemp->next;
	}
	p->next = pTemp->next;
	pTemp->next = p;

}

//��������
void display()
{
	Node* p = Head;
	if (Head == NULL)
	{
		printf("������Ϊ�գ�\n");
	}
	while (p != NULL)
	{
		printf("%d\t", p->id);
		p = p->next;
	}
	printf("\n");
}

//�������
void freelist()
{
	if (Head == NULL)
	{
		printf("����Ϊ�յģ�");
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

//ɾ��ָ���Ľڵ�
void  delete(int flag)
{
	Node* p = Head;
	Node* pTemp = Head;
	if (p == NULL)
	{
		printf("����Ϊ�յģ�");
		return;
	}
	//�����һ��
	if (p != NULL && p->id == flag)
	{
		Head = Head->next;
		free(p);
		return;//���û�����У����о��棬����ֹp���ͷ� ��Ȼ���ں�߾Ͳ�����p��
	}
	p = p->next;//��pָ�����һ������֤pTempʼ����pǰ��
	while (p != NULL)
	{
		if (p->id == flag)
		{

		}

	}

}

//�����Ȳ�ѯ
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
	printf("β��ӵĽ����\n");
	display();
	AddNodeHead(6);
	AddNodeHead(7);
	AddNodeHead(8);
	printf("ͷ��Ľ����\n");
	display();

	printf("\n");
	Node* p = searchNode(2);
	if (p != NULL)
	{
		printf("�ҵ��ˡ���\n");
	}
	else {
		printf("û�ҵ�!\n");
	}
	freelist();
	display();
	AddNodetail(1);
	AddNodetail(2);
	display();
	int Length = Listlength();
	printf("����ĳ���Ϊ%d", Length);
	printf("�ڵ�2��λ���ϲ���5\n");
	InsertNode(1, 5);
	display();

	return 0;
}