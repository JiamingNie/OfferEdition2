// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

#include<iostream>
#include"../Utilities/List.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* headerA = headA;
	ListNode* headerB = headB;
	while (headerA != nullptr || headerB != nullptr)
	{
		if (headerA == headerB)
			return headerA;
		if (headerA == nullptr)
			headerA = headB;
		else
			headerA = headerA->m_pNext;
		if (headerB == nullptr)
			headerB = headA;
		else
			headerB = headerB->m_pNext;
	}
	return nullptr;
}

int main()
{
	// 第一个公共结点在链表中间
	// 1 - 2 - 3 \
	//            6 - 7
	//     4 - 5 /
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode6);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	auto output = getIntersectionNode(pNode1, pNode4);
	if (output != nullptr)
		cout << output->m_nValue << endl;
	else
		cout << "没有公共节点！" << endl;

	return 0;

}