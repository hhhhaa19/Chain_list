#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
void Print_Chlist(Chlist_node* phead)
{
	Chlist_node* tail = phead;//����û���ڱ�λ��ÿ�����ݶ�����
	while (tail!=NULL)
	{
		printf("%d ", tail->data);
		tail = tail->next;
	}
}
Chlist_node*  Creat_Chlist(DATATYPE num)
{
	Chlist_node* des = (Chlist_node*)malloc(sizeof(Chlist_node));
	//mallocҪ�ж�
	if (des == NULL)
	{
		perror("Creat_Chlist");
		exit(-1);
	}
	des->data = num;
	des->next = NULL;//��ʼ��ʱָ��ǵø�NULL
	return des;
}
void Push_fornt_Chlist(Chlist_node** pphead, DATATYPE num)
{
	Chlist_node* newnode = Creat_Chlist(num);
#if 0
	//����Ϊ��
	newnode->next = phead;
	phead = newnode;//��߲��У���Ϊ�β���ʵ�ε�һ�ݿ�����û��ʵ��������,����Ҫ��ַ
#endif
	newnode->next = *pphead;//����
	*pphead = newnode;//�����ͷ

}
void Push_back_Chlist(Chlist_node** pphead, DATATYPE num)
{
	Chlist_node* tail = Creat_Chlist(num);
	//Ϊ��
	if (*pphead == NULL)
	{
		*pphead = tail;
	}
	else
	{
		Chlist_node* temp = *pphead;
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = tail;
	}


}