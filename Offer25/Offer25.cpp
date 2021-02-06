/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

限制：
0 <= 链表长度 <= 1000
*/
#include<iostream>
#include"../Utilities/List.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* l3 = CreateListNode(-1);
	ListNode* header = l3;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->m_nValue > l2->m_nValue)
		{
			l3->m_pNext = l2;
			l2 = l2->m_pNext;
		}
		else
		{
			l3->m_pNext = l1;
			l1 = l1->m_pNext;
		}
		l3 = l3->m_pNext;
	}
	if (l1 != nullptr)
	{
		l3->m_pNext = l1;
	}
	else if (l2 != nullptr)
	{
		l3->m_pNext = l2;
	}
	return header->m_pNext;
}

int main()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(4);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(4);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);

	PrintList(pNode1);
	PrintList(pNode4);

	auto ans = mergeTwoLists(pNode1, pNode4);

	PrintList(ans);
	return 0;
}