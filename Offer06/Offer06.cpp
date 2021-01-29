/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
*/
//niejiaming 20210124

 // class Solution {
 // public:
 //     vector<int> reversePrint(ListNode* head) {
 //         vector<int> v;
 //         while(head)
 //         {
 //             v.push_back(head->val);
 //             head=head->next;
 //         }
 //         reverse(v.begin(),v.end());
 //         return v;
 //     }
 // };

//class Solution {
//public:
//	vector<int> reversePrint(ListNode* head) {
//		vector<int> v;
//		stack<int> sk;
//		while (head)
//		{
//			sk.push(head->val);
//			head = head->next;
//		}
//		while (!sk.empty())
//		{
//			v.push_back(sk.top());
//			sk.pop();
//		}
//		return v;
//	}
//};

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include"../Utilities/List.h"

using namespace std;


ListNode* createListNodeData()
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

	return pNode1;
}

vector<int> reversePrint1(ListNode* head) {
	vector<int> v;
	while (head)
	{
		v.push_back(head->m_nValue);
		head = head->m_pNext;
	}
	reverse(v.begin(), v.end());
	return v;
}

vector<int> reversePrint2(ListNode* head) {
	vector<int> v;
	stack<int> sk;
	while (head)
	{
		sk.push(head->m_nValue);
		head = head->m_pNext;
	}
	while (!sk.empty())
	{
		v.push_back(sk.top());
		sk.pop();
	}
	return v;
}

int main()
{
	ListNode* head1 = createListNodeData();
	ListNode* head2 = createListNodeData();

	vector<int> nums1 = reversePrint1(head1);

	vector<int> nums2 = reversePrint2(head2);

	cout << "方法一(reserve)翻转链表："<<endl;
	for (auto& n:nums1)
	{
		cout << n << " ";
	}
	cout << endl;

	cout << "方法二(stack)翻转链表：" << endl;
	for (auto& n : nums2)
	{
		cout << n << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}