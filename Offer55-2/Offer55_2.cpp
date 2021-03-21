/*
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点
的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]

	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
返回 false 。
*/
#include<iostream>
#include"../Utilities/BinaryTree.h"
#include<algorithm>
using namespace std;


int nodeDepth(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	int left = nodeDepth(root->m_pLeft);
	if (left == -1)
		return -1;
	int right = nodeDepth(root->m_pRight);
	if (right == -1)
		return -1;
	if (abs(left - right) > 1)
		return -1;
	else
		return max(left, right) + 1;
}

bool isBalanced(BinaryTreeNode* root) {
	return nodeDepth(root) != -1;
}

int maxDepth(BinaryTreeNode* root)
{
	if (root == nullptr)
		return 0;
	int left = maxDepth(root->m_pLeft);
	int right = maxDepth(root->m_pRight);
	return max(left, right) + 1;
}

bool isBalanced2(BinaryTreeNode* root) {
	if (root == nullptr)
		return true;
	int leftDepth = maxDepth(root->m_pLeft);
	int rightDepth = maxDepth(root->m_pRight);
	return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->m_pLeft) && isBalanced(root->m_pRight);
}

int main()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, nullptr, pNode6);
	ConnectTreeNodes(pNode5, pNode7, nullptr);

	cout << isBalanced(pNode1) << endl;
	cout << isBalanced2(pNode1) << endl;

	return 0;
}
