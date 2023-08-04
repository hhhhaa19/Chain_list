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
//����˼·����
//��ӡ
void Print_Chlist(Chlist_node* phead);
//�������
Chlist_node* Creat_Chlist(DATATYPE num);
//ǰ��
void Push_fornt_Chlist(Chlist_node** pphead, DATATYPE num);
//���
void Push_back_Chlist(Chlist_node** pphead, DATATYPE num);
//ǰɾ
void Pop_front_Chlist(Chlist_node** pphead);
//��ɾ
void Pop_back_Chlist(Chlist_node** pphead);
//����
Chlist_node* Find_Chlist(Chlist_node* phead, DATATYPE num);
//��������posλ��֮ǰ����x
void push_pos_Chlist(Chlist_node** pphead, Chlist_node* pos, DATATYPE num);
//��������posλ��֮�����x
void push_posafter_Chlist( Chlist_node* pos, DATATYPE num);
//��������posλ��֮ǰɾ��
void pop_pos_Chlist(Chlist_node** pphead, Chlist_node* pos);
//��������posλ��֮ǰɾ��
void pop_posafter_Chlist( Chlist_node* pos);
//��������
void Destroy_Chlist(Chlist_node* phead);



//Chlist_practice
struct ListNode* removeElements(struct ListNode* head, int val);
struct ListNode* middleNode(struct ListNode* head);
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);