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
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ
int chkPalindrome(struct ListNode* head)
{
	struct ListNode* mid = middleNode(head);
	struct ListNode* rmid = reverseList(mid);
	//���м䷴ת���Σ�Ȼ��Ƚ�
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
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lhead = (struct ListNode*)malloc(sizeof(struct ListNode));//��¼��С��
	struct ListNode* ghead = (struct ListNode*)malloc(sizeof(struct ListNode));//��¼�ϴ���
	struct ListNode* cur = pHead;//���ڱ���
	//���ڱ��棬�����ͷ�
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
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
//˼·����ͨ��β�ڵ��ж��Ƿ��ཻ������������ȣ���취�����ߴ�ͬһ���ȳ���
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
		//����ڲ��ֱ������ܲ�����Ϊ�в��ֲ�����ֵ
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

//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
//˼·������ָ��
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