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
	printf("\n");
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
void Pop_front_Chlist(Chlist_node** pphead)
{
	assert(*pphead);//��ֹΪ��
	Chlist_node* newnode = (*pphead)->next;;//����һ���µ�����ͷ����ַ��
	free(*pphead);
	*pphead = newnode;
}
//��Ҫ������ѧϰ 
void Pop_back_Chlist(Chlist_node** pphead)
{
	assert(*pphead);//��ֹΪ��
	if ((*pphead)->next == NULL)
		//һ��
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
		//һ������
	{
		Chlist_node* tail = *pphead;
		while (tail->next->next!=NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
//���ص�ǰ�ڵ�ĵ�ַ����ǰһ���ڵ��next
Chlist_node* Find_Chlist(Chlist_node* phead, DATATYPE num)
{
	Chlist_node* cur = phead;
	while (cur->next != NULL)
	{
		if (cur->data != num)
		{
			cur = cur->next;
		}
		else
		{
			return cur;
		}
	}
}
void push_pos_Chlist(Chlist_node** pphead, Chlist_node* pos, DATATYPE num)
{
	Chlist_node* cur = *pphead;
	Chlist_node* des = Creat_Chlist(num);
	//�����ڿ�ͷ
	if (cur == NULL)
	{
		*pphead = des;
	}
	else
	{
		while (cur->next != NULL && cur !=pos )
		{
			cur = cur->next;
		}
		if (cur->next != NULL)
		{	//�������м�
			Chlist_node* temp = pos->next;
			pos->next = des;
			des->next = temp;
		}
		else
		{
			pos->next = des;
		}
	}
}