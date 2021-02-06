/*
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ�������� 6 ���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������ 1��2��3��4��5��6���������ĵ����� 2 ���ڵ���ֵΪ 4 �Ľڵ㡣

ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5.
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