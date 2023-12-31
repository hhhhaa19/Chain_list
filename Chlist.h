#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DATATYPE;
typedef struct Chlist_node
{
	DATATYPE data;
	struct Chlist_node* next;
}Chlist_node;

struct ListNode
{
	int val;
	struct ListNode* next;

};
struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};
//总体思路就是
//打印
void Print_Chlist(Chlist_node* phead);
//产生结点
Chlist_node* Creat_Chlist(DATATYPE num);
//前插
void Push_fornt_Chlist(Chlist_node** pphead, DATATYPE num);
//后插
void Push_back_Chlist(Chlist_node** pphead, DATATYPE num);
//前删
void Pop_front_Chlist(Chlist_node** pphead);
//后删
void Pop_back_Chlist(Chlist_node** pphead);
//查找
Chlist_node* Find_Chlist(Chlist_node* phead, DATATYPE num);
//单链表在pos位置之前插入x
void push_pos_Chlist(Chlist_node** pphead, Chlist_node* pos, DATATYPE num);
//单链表在pos位置之后插入x
void push_posafter_Chlist( Chlist_node* pos, DATATYPE num);
//单链表在pos位置之前删除
void pop_pos_Chlist(Chlist_node** pphead, Chlist_node* pos);
//单链表在pos位置之前删除
void pop_posafter_Chlist( Chlist_node* pos);
//销毁链表
void Destroy_Chlist(Chlist_node* phead);



//Chlist_practice
struct ListNode* removeElements(struct ListNode* head, int val);
struct ListNode* middleNode(struct ListNode* head);
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);