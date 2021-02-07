/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：
输入：A = [1,2,3], B = [3,1]
输出：false

示例 2：
输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000
*/

#include<iostream>
#include"../Utilities/BinaryTree.h"
using namespace std;

bool subTree(BinaryTreeNode* A, BinaryTreeNode* B)
{
	if (B == nullptr)
	{
		return true;
	}
	else if (A == nullptr || A->m_nValue != B->m_nValue)
	{
		return false;
	}
	else
	{
		return subTree(A->m_pLeft, B->m_pLeft) && subTree(A->m_pRight, B->m_pRight);
	}
}

bool isSubStructure(BinaryTreeNode* A, BinaryTreeNode* B) {
	if (A == NULL || B == NULL)
		return false;
	else
	{
		return subTree(A, B) || isSubStructure(A->m_pLeft, B) || isSubStructure(A->m_pRight, B);
	}
}


int main()
{
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	
	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	cout << "A tree is:" << endl;
	PrintTree(pNodeA1);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
	cout << "B tree is:" << endl;
	PrintTree(pNodeB1);

	bool ans = isSubStructure(pNodeA1,pNodeB1);

	cout << ans << endl;

	return 0;
}