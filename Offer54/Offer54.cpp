/*
给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4

示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
输出: 4

限制：
1 ≤ k ≤ 二叉搜索树元素个数
*/

#include<iostream>
#include<vector>
#include"../Utilities/BinaryTree.h"
using namespace std;

void inorder(BinaryTreeNode* root, int k,int& res,int& count)
{
	if (root == nullptr)
		return;
	inorder(root->m_pRight, k, res, count);
	count++;
	if (count == k)
	{
		res = root->m_nValue;
		return;
	}
	inorder(root->m_pLeft, k, res, count);

}

int kthLargest(BinaryTreeNode* root, int k) {
	int res = 0, count = 0;
	inorder(root, k, res,count);
	return res;
}

int main()
{
	//            8
	//        6      10
	//       5 7    9  11
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	cout << kthLargest(pNode8, 3) << endl;

	return 0;
}

