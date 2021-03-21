/*
����һ�ö��������������ö���������ת����һ�������ѭ��˫������
Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

Ϊ���������õ�������⣬������Ķ���������Ϊ����

����ϣ�����������������ת��Ϊ˫��ѭ�����������е�ÿ���ڵ㶼��һ��ǰ���ͺ��ָ�롣
����˫��ѭ��������һ���ڵ��ǰ�������һ���ڵ㣬���һ���ڵ�ĺ���ǵ�һ���ڵ㡣

�ر�أ�����ϣ�����Ծ͵����ת����������ת������Ժ����нڵ����ָ����Ҫָ��ǰ����
���нڵ����ָ����Ҫָ���̡�����Ҫ���������еĵ�һ���ڵ��ָ�롣
*/

#include<iostream>
#include<vector>
#include"../Utilities/BinaryTree.h"
using namespace std;

BinaryTreeNode* head, *tail;

void dfs(BinaryTreeNode* root)
{
	if (root == NULL)
		return;
	dfs(root->m_pLeft);
	if (tail == NULL)
		head = root;
	else
	{
		tail->m_pRight = root;
		root->m_pLeft = tail;
	}
	tail = root;
	dfs(root->m_pRight);
}

BinaryTreeNode* treeToDoublyList(BinaryTreeNode* root) {
	if (root == NULL)
		return NULL;
	dfs(root);
	head->m_pLeft = tail;
	tail->m_pRight = head;
	return head;
}
	
void DestroyList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;
	while (pNode != nullptr)
	{
		BinaryTreeNode* pNext = pNode->m_pRight;

		delete pNode;
		pNode = pNext;
	}
}

void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;

	printf("The nodes from left to right are:\n");
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pRight == nullptr)
			break;
		pNode = pNode->m_pRight;
	}

	printf("\nThe nodes from right to left are:\n");
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pLeft == nullptr)
			break;
		pNode = pNode->m_pLeft;
	}

	printf("\n");
}

int main()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	PrintTree(pNode10);

	BinaryTreeNode* res = treeToDoublyList(pNode10);
	//PrintDoubleLinkedList(res);

	//DestroyList(pNode4);
	//DestroyTree(pNode4);
	return 0;
}