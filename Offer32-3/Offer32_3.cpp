/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

例如:
给定二叉树: [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回其层次遍历结果：
[
  [3],
  [20,9],
  [15,7]
]

提示：

节点总数 <= 1000
*/
#include<iostream>
#include<vector>
#include<deque>
#include"../Utilities/BinaryTree.h"
using namespace std;

vector<vector<int>> levelOrder(BinaryTreeNode* root) {
	if (root == nullptr)
		return {};
	deque<BinaryTreeNode*> qNode;
	qNode.push_front(root);
	int levelCount = 1;
	int nextLevelCount = 0;
	vector<int> levelVlaue;
	vector<vector<int>> res;
	bool reverseFlag = false;
	while (!qNode.empty())
	{	
		if (!reverseFlag)
		{
			BinaryTreeNode* tmp = qNode.front();
			levelVlaue.push_back(tmp->m_nValue);
			qNode.pop_front();
			levelCount--;
			if (tmp->m_pLeft != nullptr)
			{
				qNode.push_back(tmp->m_pLeft);
				nextLevelCount++;
			}
			if (tmp->m_pRight != nullptr)
			{
				qNode.push_back(tmp->m_pRight);
				nextLevelCount++;
			}
		}
		else
		{
			BinaryTreeNode* tmp = qNode.back();
			levelVlaue.push_back(tmp->m_nValue);
			qNode.pop_back();
			levelCount--;
			if (tmp->m_pRight != nullptr)
			{
				qNode.push_front(tmp->m_pRight);
				nextLevelCount++;
			}
			if (tmp->m_pLeft != nullptr)
			{
				qNode.push_front(tmp->m_pLeft);
				nextLevelCount++;
			}
		}
		if (levelCount == 0)
		{
			reverseFlag = !reverseFlag;
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