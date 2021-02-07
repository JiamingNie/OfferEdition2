/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
 

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：
0 <= 节点个数 <= 1000
*/

#include<iostream>
#include<stack>
#include"../Utilities/BinaryTree.h"
using namespace std;

BinaryTreeNode* mirrorTreeIteratively(BinaryTreeNode* root) {
    if(root==nullptr)
        return root;
    swap(root->m_pLeft,root->m_pRight);
    mirrorTreeIteratively(root->m_pLeft);
    mirrorTreeIteratively(root->m_pRight);

    return root;
}

BinaryTreeNode* mirrorTreeRecursively(BinaryTreeNode* root) {
	if (root == NULL)
		return root;
	stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(root);
	while (!stackTreeNode.empty())
	{
		BinaryTreeNode* tmp = stackTreeNode.top();
		swap(tmp->m_pLeft, tmp->m_pRight);
		stackTreeNode.pop();
		if (tmp->m_pLeft)
			stackTreeNode.push(tmp->m_pLeft);
		if (tmp->m_pRight)
			stackTreeNode.push(tmp->m_pRight);
	}
	return root;
}

int main()
{
	//printf("=====Test1 starts:=====\n");
	//BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	//BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	//BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	//BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	//BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	//BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	//BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	//ConnectTreeNodes(pNode8, pNode6, pNode10);
	//ConnectTreeNodes(pNode6, pNode5, pNode7);
	//ConnectTreeNodes(pNode10, pNode9, pNode11);

	//PrintTree(pNode8);

	printf("=====Test2 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, pNode7, nullptr);
	ConnectTreeNodes(pNode7, pNode6, nullptr);
	ConnectTreeNodes(pNode6, pNode5, nullptr);
	ConnectTreeNodes(pNode5, pNode4, nullptr);

	PrintTree(pNode8);

	printf("=====Test1: MirrorRecursively=====\n");
	mirrorTreeIteratively(pNode8);
	PrintTree(pNode8);

	printf("=====Test1: MirrorIteratively=====\n");
	mirrorTreeRecursively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);

	return 0;
}
