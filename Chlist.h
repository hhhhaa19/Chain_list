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
