/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。

为了让您更好地理解问题，以下面的二叉搜索树为例：

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。
对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，
树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
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