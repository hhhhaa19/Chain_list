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