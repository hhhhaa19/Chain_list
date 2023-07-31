#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
//增删
void test()
{
	Chlist_node* phead = NULL;
	//Push_fornt_Chlist(&phead, 1);
	//Push_fornt_Chlist(&phead, 2);
	//Push_fornt_Chlist(&phead, 3);
	//Print_Chlist(phead);
	Push_back_Chlist(&phead, 4);
	Push_back_Chlist(&phead, 3);
	Push_back_Chlist(&phead, 2);
	Print_Chlist(phead);
	Pop_front_Chlist(&phead);
	Print_Chlist(phead);
	Pop_back_Chlist(&phead);
	Print_Chlist(phead);
}
void test2()
{
	Chlist_node* phead = NULL;
	Push_back_Chlist(&phead, 4);
	Push_back_Chlist(&phead, 3);
	Push_back_Chlist(&phead, 2);
	Chlist_node* tag = Find_Chlist(phead, 3);
	push_pos_Chlist(&phead, tag, 5);
	Print_Chlist(phead);
}
//Push_pos_Chlist各种情况
void test3()
{
	Chlist_node* phead = NULL;
	Push_back_Chlist(&phead, 4);
	Push_back_Chlist(&phead, 3);
	Chlist_node* tag = Find_Chlist(phead, 3);
	push_pos_Chlist(&phead, tag, 5);
	 tag = Find_Chlist(phead, 3);
	push_posafter_Chlist(tag, 10);
	Print_Chlist(phead);
	tag = Find_Chlist(phead, 4);
	pop_posafter_Chlist(tag);
	Print_Chlist(phead);

}
int main()
{
	test3();
	return 0;
}