#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	node1->val = 2;
	node2->val = 2;
	node3->val = 2;
	node4->val = 2;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode*list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* list4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	list1->val = 2;
	list2->val = 2;
	list3->val = 2;
	list4->val = 2;
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = NULL;
	/*struct ListNode* head = removeElements(node1, 2);*/
	/*struct ListNode* head = middleNode(node1);*/

	struct ListNode* head = mergeTwoLists(node1, list1);
	return 0;
}