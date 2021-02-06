/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 2 个节点是值为 4 的节点。

示例：
给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
*/
#include<iostream>
#include"../Utilities/List.h"
using namespace std;

ListNode* getKthFromEnd(ListNode* head, int k) {
	ListNode* cur = head;
	for (int i = 0; i < k; i++)
	{
		cur = cur->m_pNext;
	}
	ListNode* header = head;
	while (cur)
	{
		cur = cur->m_pNext;
		header = header->m_pNext;
	}
	return header;
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

	auto ans = getKthFromEnd(pNode1, 5);

	PrintList(ans);
	return 0;
}