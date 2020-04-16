#include<stdio.h>
typedef struct student {
	int id;
	char name[10];
	struct student* next;
}STU;

//���ͷ���
STU* Head()
{
	STU* p = (STU*)malloc(sizeof(STU));
	p->next = NULL;
	return p;
}

//��Ӷ�������ڵ�ĺ���
void AddNode(STU* p)
{
	STU* pnew = NULL;
	int n = 0;//��ӵĽڵ����
	printf("�����Ա��Ϣ����id����Ϊ0ʱ�˳�\n");
	while (1)
	{
		pnew = (STU*)malloc(sizeof(STU));
		printf("��%d���ڵ����Ϣ��\n", n + 1);
		printf("id:");
		scanf_s("%d", &pnew->id);
		if (pnew->id == 0)
		{
			free(pnew);
			break;//����ѭ��
		}
		printf("������");
		scanf_s("%s", pnew->name, 10);
		n++;
		pnew->next = NULL;//����ӵ�����ڵ�ָ���ÿ�

		//��������
		p->next = pnew;
		p = p->next;


	}

}

//�������
void display(STU* p)
{
	p = p->next;//��pָ���һ�������ݵ�Ԫ��
	printf("===============\n");
	while (p != NULL)
	{
		printf("%d\t%S", p->id, p->name);
		printf("\n");
		p = p->next;
	}
}
//��ȡ����ĳ��ȣ�����ͷ��㣩
int length(STU* p)
{
	int n = 1;
	p = p->next;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;

}

//ɾ��ĳ���ڵ�
void delectNode(STU* p)
{
	STU* pTemp = p;//����һ����ʱ��ָ�룬��ָ��ͷ�ڵ�
	p = p->next;//pָ���һ�������ݵĽڵ�
	/*pTempʼ����pǰ��һ��*/
	int flag;
	printf("������Ҫɾ���ڵ��id��");
	scanf_s("%d", &flag);
	while (p != NULL)
	{

		if (p->id == flag)
		{
			pTemp->next = p->next;
			free(p);
			p = pTemp->next;
		}


		pTemp = pTemp->next;
		if (p == NULL)
		{
			break;
		}
		p = p->next;


	}


}


int main()
{
	STU* p = Head();
	AddNode(p);
	//�����pʼ����ָ��ͷ����
	//printf("%d\t%s", p->next->id, p->next->name);
	display(p);
	printf("����ĳ��ȣ�%d\n", length(p));

	delectNode(p);
	display(p);
	printf("ɾ�����������Ϊ��");
	printf("%d", length(p));
	return 0;
}