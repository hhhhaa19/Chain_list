#define _CRT_SECURE_NO_WARNINGS 1
#include"Chlist.h"
// �Ƴ�����Ԫ��
//����һ�������ͷ�ڵ� head ��һ������ val ��
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ�

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

//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
//����һ����ָ��+ͷ��
struct ListNode* reverseList(struct ListNode* head) 
{
	if (head != NULL&&head->next!=NULL)
	{
		struct ListNode* newcur = NULL;//������ĺ�һ���ڵ�
		struct ListNode* cur = head->next;//�����������ÿ���ڵ�
		struct ListNode* newhead = NULL;//��ͷ
		while (cur != NULL)
		{
			//��һ��
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


//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
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


//����һ����������������е�����k����㡣
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

//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
//�����ڱ�λ
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
//���ڱ�λ
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
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
