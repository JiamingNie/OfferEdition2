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
	return 0;
}