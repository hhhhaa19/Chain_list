#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
void Print_Chlist(Chlist_node* phead)
{
	Chlist_node* tail = phead;//这里没有哨兵位，每个数据都有用
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
	//malloc要判断
	if (des == NULL)
	{
		perror("Creat_Chlist");
		exit(-1);
	}
	des->data = num;
	des->next = NULL;//初始化时指针记得赋NULL
	return des;
}
void Push_fornt_Chlist(Chlist_node** pphead, DATATYPE num)
{
	Chlist_node* newnode = Creat_Chlist(num);
#if 0
	//链表不为空
	newnode->next = phead;
	phead = newnode;//这边不行，因为形参是实参的一份拷贝，没有实际连接上,所以要传址
#endif
	newnode->next = *pphead;//链接
	*pphead = newnode;//变成新头

}
void Push_back_Chlist(Chlist_node** pphead, DATATYPE num)
{
	Chlist_node* tail = Creat_Chlist(num);
	//为空
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
	assert(*pphead);//防止为空
	Chlist_node* newnode = (*pphead)->next;;//创建一个新的来存头（地址）
	free(*pphead);
	*pphead = newnode;
}
//重要，反复学习 
void Pop_back_Chlist(Chlist_node** pphead)
{
	assert(*pphead);//防止为空
	if ((*pphead)->next == NULL)
		//一个
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
		//一个以上
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
//返回当前节点的地址，即前一个节点的next
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
	//假设在开头
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
		{	//假设在中间
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