#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
void test()
{
	Chlist_node* phead = NULL;
	//Push_fornt_Chlist(&phead, 1);
	//Push_fornt_Chlist(&phead, 2);
	//Push_fornt_Chlist(&phead, 3);
	//Print_Chlist(phead);
	Push_back_Chlist(&phead, 4);
	Print_Chlist(phead);
}
int main()
{
	test();
	return 0;
}