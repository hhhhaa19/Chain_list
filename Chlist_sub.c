#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
void Print_Chlist(Chlist_node* phead)
{
	assert(phead);
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
	assert(pphead);
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
	assert(pphead);
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
	assert(pphead);
	assert(*pphead);//防止为空
	Chlist_node* newnode = (*pphead)->next;;//创建一个新的来存头（地址）
	free(*pphead);
	*pphead = newnode;
}
//重要，反复学习 
void Pop_back_Chlist(Chlist_node** pphead)
{
	assert(pphead);
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
	assert(phead);
	Chlist_node* cur = phead;
	while (cur != NULL)//cur->next不能这样，会少遍历一个的
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
	//假设在开头
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
			//假设在中间
			pre->next = des;
			des->next = pos;
			//无法实现尾插
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