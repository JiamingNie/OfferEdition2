/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7

返回：
[3,9,20,15,7]
 

提示：
节点总数 <= 1000
*/
#include<iostream>
#include<vector>
#include<queue>
#include"../Utilities/BinaryTree.h"
using namespace std;

vector<int> levelOrder(BinaryTreeNode* root) {
	vector<int> res;
	if (root == nullptr)
		return {};
	queue<BinaryTreeNode*> qNode;
	qNode.push(root);
	while (!qNode.empty())
	{
		BinaryTreeNode* tmp = qNode.front();
		qNode.pop();
		res.push_back(tmp->m_nValue);
		if (tmp->m_pLeft != nullptr)
			qNode.push(tmp->m_pLeft);
		if (tmp->m_pRight != nullptr)
			qNode.push(tmp->m_pRight);
		
	}
	return res;
}

int main()
{
	printf("=====Test1 starts:=====\n");
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

	PrintTree(pNode8);

	vector<int> res = levelOrder(pNode8);

	for (auto& r : res)
	{
		cout << r << "	";
	}
	cout << endl;
	return 0;
}