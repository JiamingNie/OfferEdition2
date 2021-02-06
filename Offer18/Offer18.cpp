/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。

注意：此题对比原题有改动
示例 1:
输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

示例 2:
输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

说明：
题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue> 
#include<vector>
#include"../Utilities/List.h"

using namespace std;


void deleteNode(ListNode* head, int val) {
	if (head == nullptr)
		return;
	else if (head->m_nValue == val)
	{
		ListNode* tmp = head->m_pNext;
		head->m_nValue = head->m_pNext->m_nValue;
		head->m_pNext = head->m_pNext->m_pNext;
		delete tmp;
		tmp = nullptr;
	}
	else
	{
		ListNode* cur = CreateListNode(-1);
		ConnectListNodes(cur, head);
		ListNode* header = cur;
		while (cur->m_pNext != nullptr)
		{
			if (cur->m_pNext->m_nValue == val)
			{
				ListNode* tmp = cur->m_pNext;
				cur->m_pNext = cur->m_pNext->m_pNext;
				delete tmp;
				tmp = nullptr;
				break;
			}
			else
				cur = cur->m_pNext;
		}
		delete header;
		header = nullptr;
	}
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

	deleteNode(pNode1,1);

	PrintList(pNode1);

	return 0;
}