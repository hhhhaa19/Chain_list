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