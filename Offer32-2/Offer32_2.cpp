/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
例如:
给定二叉树: [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

提示：
节点总数 <= 1000
*/
#include<iostream>
#include<vector>
#include<queue>
#include"../Utilities/BinaryTree.h"
using namespace std;

vector<vector<int>> levelOrder(BinaryTreeNode* root) {

	if (root == nullptr)
		return {};
	queue<BinaryTreeNode*> qNode;
	qNode.push(root);
	int levelCount = 1;
	int nextLevelCount = 0;
	vector<int> levelVlaue;
	vector<vector<int>> res;
	while (!qNode.empty())
	{
		
		BinaryTreeNode* tmp = qNode.front();
		levelVlaue.push_back(tmp->m_nValue);
		qNode.pop();
		levelCount--;
		if (tmp->m_pLeft != nullptr)
		{
			qNode.push(tmp->m_pLeft);
			nextLevelCount++;
		}
			
		if (tmp->m_pRight != nullptr)
		{
			qNode.push(tmp->m_pRight);
			nextLevelCount++;
		}
		if (levelCount == 0)
		{
			res.push_back(levelVlaue);
			levelVlaue.clear();
			levelCount = nextLevelCount;
			nextLevelCount = 0;
		}
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

	vector<vector<int>> res = levelOrder(pNode8);

	for (auto& r : res)
	{
		for (auto& a : r)
			cout << a << "	";
		cout << endl;
	}
	cout << endl;
	return 0;
}