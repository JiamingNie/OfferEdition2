/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]


提示：
节点总数 <= 10000
*/

#include<iostream>
#include<vector>
#include"../Utilities/BinaryTree.h"
using namespace std;

vector<vector<int>> res;
vector<int> current;

void backTracking(BinaryTreeNode* root, int sum)
{
	current.push_back(root->m_nValue);
	if (sum == root->m_nValue&&root->m_pLeft == nullptr && root->m_pRight == nullptr)
	{
		res.push_back(current);
		current.pop_back();
		return;
	}
	if (sum != root->m_nValue&&root->m_pLeft == nullptr && root->m_pRight == nullptr)
	{
		current.pop_back();
		return;
	}
	sum -= root->m_nValue;
	if (root->m_pLeft != nullptr)
		backTracking(root->m_pLeft, sum);
	if (root->m_pRight != nullptr)
		backTracking(root->m_pRight, sum);
	current.pop_back();
}

vector<vector<int>> pathSum(BinaryTreeNode* root, int sum) {
	if (root == nullptr)
		return {};
	backTracking(root, sum);
	return res;
}




int main()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("Two paths should be found in Test1.\n");

	backTracking(pNode10, 22);

	for (auto& rr:res)
	{
		for (auto& r : rr)
		{
			cout << r << "	";
		}
		cout << endl;
	}

	DestroyTree(pNode10);
	return 0;
}