#include<stdio.h>
typedef struct student {
	int id;
	char name[10];
	struct student* next;
}STU;

//添加头结点
STU* Head()
{
	STU* p = (STU*)malloc(sizeof(STU));
	p->next = NULL;
	return p;
}

//添加多个后续节点的函数
void AddNode(STU* p)
{
	STU* pnew = NULL;
	int n = 0;//添加的节点个数
	printf("输入成员信息，当id设置为0时退出\n");
	while (1)
	{
		pnew = (STU*)malloc(sizeof(STU));
		printf("第%d个节点的信息：\n", n + 1);
		printf("id:");
		scanf_s("%d", &pnew->id);
		if (pnew->id == 0)
		{
			free(pnew);
			break;//跳出循环
		}
		printf("姓名：");
		scanf_s("%s", pnew->name, 10);
		n++;
		pnew->next = NULL;//新添加的这个节点指针置空

		//链接起来
		p->next = pnew;
		p = p->next;


	}

}

//遍历输出
void display(STU* p)
{
	p = p->next;//让p指向第一个有数据的元素
	printf("===============\n");
	while (p != NULL)
	{
		printf("%d\t%S", p->id, p->name);
		printf("\n");
		p = p->next;
	}
}
//获取链表的长度（包含头结点）
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

//删除某个节点
void delectNode(STU* p)
{
	STU* pTemp = p;//定义一个临时的指针，并指向头节点
	p = p->next;//p指向第一个有数据的节点
	/*pTemp始终在p前方一个*/
	int flag;
	printf("请输入要删除节点的id：");
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
	//这里的p始终是指向头结点的
	//printf("%d\t%s", p->next->id, p->next->name);
	display(p);
	printf("链表的长度：%d\n", length(p));

	delectNode(p);
	display(p);
	printf("删除后的链表长度为：");
	printf("%d", length(p));
	return 0;
}