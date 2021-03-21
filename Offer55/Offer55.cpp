/*
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点
（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：
给定二叉树 [3,9,20,null,null,15,7]，

	3
   / \
  9  20
	/  \
   15   7
返回它的最大深度 3 。

 

提示：
节点总数 <= 10000
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include"../Utilities/BinaryTree.h"
#include<queue>
using namespace std;

int maxDepth(BinaryTreeNode* root) {
	if (root == nullptr)
		return 0;
	int left = maxDepth(root->m_pLeft);
	int right = maxDepth(root->m_pRight);
	return max(left, right) + 1;
}

int maxDepth2(BinaryTreeNode* root) {
	if (root == NULL) return 0;
	int depth = 0;
	queue<BinaryTreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		depth++; // 记录深度
		for (int i = 0; i < size; i++) {
			BinaryTreeNode* node = que.front();
			que.pop();
			if (node->m_pLeft) que.push(node->m_pLeft);
			if (node->m_pRight) que.push(node->m_pRight);
		}
	}
	return depth;
}

int main()
{
	//            1
	//         /      \
	//        2        3
	//       /\         \
	//      4  5         6
	//        /
	//       7
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

	cout << maxDepth(pNode1) << endl;
	cout << maxDepth2(pNode1) << endl;

	return 0;
}