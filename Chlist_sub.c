#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
void Print_Chlist(Chlist_node* phead)
{
	assert(phead);
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
	assert(pphead);
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
	assert(pphead);
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
	assert(pphead);
	assert(*pphead);//��ֹΪ��
	Chlist_node* newnode = (*pphead)->next;;//����һ���µ�����ͷ����ַ��
	free(*pphead);
	*pphead = newnode;
}
//��Ҫ������ѧϰ 
void Pop_back_Chlist(Chlist_node** pphead)
{
	assert(pphead);
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
	assert(phead);
	Chlist_node* cur = phead;
	while (cur != NULL)//cur->next�������������ٱ���һ����
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
	return NULL;
}
void push_pos_Chlist(Chlist_node** pphead, Chlist_node* pos, DATATYPE num)
{
	assert(pphead);
	assert(pos);
	Chlist_node* pre = *pphead;
	Chlist_node* des = Creat_Chlist(num);
	//�����ڿ�ͷ
	if (pos==*pphead)
	{
		Push_fornt_Chlist(pphead,num);
	}
	else
	{
		while ( pre->next !=pos )
		{
			pre = pre->next;
		}
			//�������м�
			pre->next = des;
			des->next = pos;
			//�޷�ʵ��β��
	}
}
void push_posafter_Chlist(Chlist_node* pos, DATATYPE num)
{
	assert(pos);
	Chlist_node* des = Creat_Chlist(num);
	des->next = pos->next;
	pos->next = des;
}
void pop_pos_Chlist(Chlist_node** pphead, Chlist_node* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if (pos == *pphead)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		Chlist_node* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		pre->next = pos->next;
		free(pos);
	}
}
void pop_posafter_Chlist(Chlist_node* pos)
{
	assert(pos);
	Chlist_node* temp = pos->next;
	pos->next = temp->next;
	free(temp);
	temp = NULL;
}
void Destroy_Chlist(Chlist_node* phead)
{
	Chlist_node* cur = phead;
	Chlist_node* pre = phead;
	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;
		free(pre);
	}
}