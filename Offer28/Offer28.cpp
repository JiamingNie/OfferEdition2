/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
 

限制：
0 <= 节点个数 <= 1000
*/

#include<iostream>
#include"../Utilities/BinaryTree.h"
using namespace std;

bool judge(BinaryTreeNode* leftNode, BinaryTreeNode* rightNode)
{
	if (leftNode == nullptr && rightNode == nullptr)
	{
		return true;
	}
	if (leftNode == nullptr || rightNode == nullptr || leftNode->m_nValue != rightNode->m_nValue)
	{
		return false;
	}
	else
	{
		return judge(leftNode->m_pLeft, rightNode->m_pRight) && judge(leftNode->m_pRight, rightNode->m_pLeft);
	}
}


bool isSymmetric(BinaryTreeNode* root) {
	if (root == nullptr)
	{
		return true;
	}
	else
	{
		return judge(root->m_pLeft, root->m_pRight);
	}
}




int main()
{
	printf("=====Test1 starts:=====\n");
	//BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	//BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	//BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	//BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	//BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	//BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	//BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	//ConnectTreeNodes(pNode8, pNode61, pNode62);
	//ConnectTreeNodes(pNode61, pNode51, pNode71);
	//ConnectTreeNodes(pNode62, pNode72, pNode52);

	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode21, pNode22);
	ConnectTreeNodes(pNode21, pNode31, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, nullptr, nullptr);
	ConnectTreeNodes(pNode42, nullptr, nullptr);

	PrintTree(pNode1);


	printf("=====Test1: isSymmetric=====\n");
	auto ans = isSymmetric(pNode1);
	
	cout << ans << endl;

	DestroyTree(pNode1);

	return 0;
}