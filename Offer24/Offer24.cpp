/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：
0 <= 节点个数 <= 5000
*/
#include<iostream>
#include"../Utilities/List.h"
#include<stack>
using namespace std;

ListNode* reverseList(ListNode* head) {
	ListNode* cur = NULL;
	ListNode* header = head;
	while (header != NULL)
	{
		ListNode* tmp = header->m_pNext;
		header->m_pNext = cur;
		cur = header;
		header = tmp;
	}
	return cur;
}


ListNode* addInList(ListNode* head1, ListNode* head2) {
	// write code here
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	stack<int> s1;
	stack<int> s2;
	ListNode* head3 = NULL;
	while (head1 != NULL)
	{
		s1.push(head1->m_nValue);
		head1 = head1->m_pNext;
	}
	while (head2 != NULL)
	{
		s2.push(head2->m_nValue);
		head2 = head2->m_pNext;
	}
	int sum = 0;
	int carry = 0;
	while (!s1.empty() || !s2.empty())
	{
		sum = carry;
		if (!s1.empty())
		{
			sum += s1.top();
			s1.pop();
		}
		if (!s2.empty())
		{
			sum += s2.top();
			s2.pop();
		}
		if (sum >= 10)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}
		ListNode* tmp = CreateListNode(sum);
		tmp->m_pNext = head3;
		head3 = tmp;
	}
	if (carry > 0)
	{
		ListNode* tmp = CreateListNode(carry);
		tmp->m_pNext = head3;
		head3 = tmp;
	}
	return head3;
}

ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode* dummyHead = CreateListNode(0);
	ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
	while (temp1 != nullptr && temp2 != nullptr) {
		if (temp1->m_nValue <= temp2->m_nValue) {
			temp->m_pNext = temp1;
			temp1 = temp1->m_pNext;
		}
		else {
			temp->m_pNext = temp2;
			temp2 = temp2->m_pNext;
		}
		temp = temp->m_pNext;
	}
	if (temp1 != nullptr) {
		temp->m_pNext = temp1;
	}
	else if (temp2 != nullptr) {
		temp->m_pNext = temp2;
	}
	return dummyHead->m_pNext;
}

ListNode* sortInList(ListNode* head) {
	if (head == nullptr || head->m_pNext == nullptr)
		return head;
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* slowPre = head;
	while (fast != nullptr&&fast->m_pNext != nullptr)
	{
		slowPre = slow;
		fast = fast->m_pNext->m_pNext;
		slow = slow->m_pNext;
	}
	ListNode* mid = slow;
	slowPre->m_pNext = nullptr;
	ListNode* left = sortInList(head);
	ListNode* right = sortInList(mid);
	return merge(left, right);
}


int main()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	PrintList(pNode1);

	auto ans = reverseList(pNode1);
	PrintList(ans);

	ListNode* pNode11 = CreateListNode(3);
	ListNode* pNode12 = CreateListNode(7);
	ans = addInList(pNode11, pNode12);

	PrintList(ans);

	cout << "排序" << endl;
	sortInList(pNode5);
	PrintList(pNode1);

	return 0;
}