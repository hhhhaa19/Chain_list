#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
// 移除链表元素
//给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* pre = head;
	while (cur != NULL&&cur->val == val)
	{
		head = cur->next;
		free(cur);
		cur = head;
	}
	while (cur != NULL)
	{

		if (cur->val == val)
		{
			struct ListNode* temp = pre->next;
			pre->next = cur->next;
			cur = cur->next;
			free(temp);
		}
		else
		{ 
		pre = cur;
		cur = cur->next;
		}
	}
	return head;
}

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//方法一：三指针+头插
struct ListNode* reverseList(struct ListNode* head) 
{
	if (head != NULL&&head->next!=NULL)
	{
		struct ListNode* newcur = NULL;//新链表的后一个节点
		struct ListNode* cur = head->next;//遍历老链表的每个节点
		struct ListNode* newhead = NULL;//新头
		while (cur != NULL)
		{
			//第一个
			if (newhead == NULL)
			{
				newhead = cur;
				cur = cur->next;
				newhead->next = head;
				head->next = NULL;
			}
			else
			{
				newcur = newhead;
				newhead = cur;
				cur = cur->next;
				newhead->next = newcur;
			}
		}
		return newhead;
	}
	else
	{
		return head;
	}
}


//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
struct ListNode* middleNode(struct ListNode* head) 
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL&&fast->next != NULL )
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


//输入一个链表，输出该链表中倒数第k个结点。
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	if (pListHead == NULL)
	{
		return NULL;
	}
	else
	{ 
	struct ListNode* slow = pListHead;
	struct ListNode* fast = pListHead;
	while (k > 0)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		k--;
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
	}
}

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//不带哨兵位
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if (list1 == NULL)
	{
		return list2;
	}
	else if (list2 == NULL)
	{
		return list1;
	}
	struct ListNode* head = NULL;
	struct ListNode* cur = NULL;
	if (list1->val < list2->val)
	{
		head = list1;
		list1 = list1->next;
	}
	else
	{
		head = list2;
		list2 = list2->next;
	}
	cur = head;
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->val < list2->val)
		{
			cur->next = list1;
			cur = cur->next;
			list1 = list1->next;
		
		}
		else
		{
			cur->next = list2;
			cur = cur->next;
			list2 = list2->next;
			
		}
	}
	if (list1 != NULL)
	{
		cur->next = list1;
	}
	if (list2 != NULL)
	{
		cur->next = list2;
	}
	return head;
}
//带哨兵位
struct ListNode* mergeTwoLists2(struct ListNode* list1, struct ListNode* list2)
{
	if (list1 == NULL)
		return list2;
	 if (list2 == NULL)
		return list1;
	struct ListNode* newlist = malloc(sizeof(struct ListNode));
	struct ListNode* head, * cur = NULL;
	head = cur = newlist;
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->val < list2->val)
		{
			cur->next = list1;
			cur = cur->next;
			list1 = list1->next;
		}
		else
		{
			cur->next = list2;
			cur = cur->next;
			list2 = list2->next;
		}
	}
	if (list1 != NULL)
		cur->next = list1;
	if (list2 != NULL)
		cur->next = list2;
	struct ListNode* temp = head;
	head = head->next;
	free(temp);
	return head;
}
//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构
int chkPalindrome(struct ListNode* head)
{
	struct ListNode* mid = middleNode(head);
	struct ListNode* rmid = reverseList(mid);
	//从中间反转后半段，然后比较
	while (rmid != NULL)
	{
		if (head->val != mid->val)
		{
			return -1;
		}
		head = head->next;
		rmid = rmid->next;
	}
	return 0;

}
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lhead = (struct ListNode*)malloc(sizeof(struct ListNode));//记录较小数
	struct ListNode* ghead = (struct ListNode*)malloc(sizeof(struct ListNode));//记录较大数
	struct ListNode* cur = pHead;//用于遍历
	//用于保存，后续释放
	struct ListNode* newhead = lhead;
	struct ListNode* newhead2 = ghead;
	while (cur != NULL)
	{
		if (cur->val >= x)
		{
			ghead->next = cur;
			ghead = ghead->next;
		}
		else
		{
			lhead->next = cur;
			lhead = lhead->next;
		}
		cur = cur->next;
	}
	ghead ->next= NULL;
	lhead->next = newhead2->next;
	struct ListNode* ret = newhead->next;
	
	free(newhead2);
	free(newhead);
	return ret;
}
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//思路：先通过尾节点判断是否相交，并计算出长度，想办法让两者从同一长度出发
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	if (headA == NULL || headB == NULL)
		return NULL;
	struct ListNode* tailA = headA;
	struct ListNode* tailB = headB;
	int lena = 1;
	int lenb = 1;
	while(tailA->next!= NULL)
	{
		tailA = tailA->next;
		lena++;
	}
	while (tailB->next!= NULL)
	{
		tailB = tailB->next;
		lenb++;
	}
	if (tailA == tailB)
	{
		int advence = 0;
		struct ListNode* ghead = NULL;
		struct ListNode* lhead = NULL;
		if (lena > lenb)
		{
			advence = lena - lenb;
			ghead = headA;
			lhead = headB;
		}
		else
		{
			advence = lenb - lena;
			ghead = headB;
			lhead = headA;
		}
		while (advence--)
		{
			ghead = ghead->next;
		}
		//while (ghead != NULL)
		//{
		//	if (ghead == lhead)
		//	{
		//		return ghead;
		//	}
		//	lhead = lhead->next;
		//	ghead = ghead->next;
		//}
		//这段在部分编译器跑不过认为有部分不返回值
		while (ghead != lhead)
		{
			lhead = lhead->next;
			ghead = ghead->next;
		}
		return ghead;
	}
	else
	{
		return NULL;
	} 
}

//给你一个链表的头节点 head ，判断链表中是否有环。
//思路：快慢指针
int hasCycle(struct ListNode* head)
{
	if (head == NULL)
		return 0;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast!=NULL&&fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}