/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
	3
   / \
  9  20
	/  \
   15   7

*/
//niejiaming 20210130


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include <exception>
#include"../Utilities/BinaryTree.h"

using namespace std;

void inputFunction(vector<int>& preorder, vector<int>& inorder)
{
	//test1
	//preorder.push_back(3);
	//preorder.push_back(9);
	//preorder.push_back(20);
	//preorder.push_back(15);
	//preorder.push_back(7);

	//inorder.push_back(9);
	//inorder.push_back(3);
	//inorder.push_back(15);
	//inorder.push_back(20);
	//inorder.push_back(7);

	//test2
	//preorder.push_back(1);
	//preorder.push_back(2);
	//preorder.push_back(3);
	//preorder.push_back(4);
	//preorder.push_back(5);

	//inorder.push_back(5);
	//inorder.push_back(4);
	//inorder.push_back(3);
	//inorder.push_back(2);
	//inorder.push_back(1);


	//test3
	//preorder.push_back(5);
	//preorder.push_back(4);
	//preorder.push_back(3);
	//preorder.push_back(2);
	//preorder.push_back(1);
	//

	//inorder.push_back(1);
	//inorder.push_back(2);
	//inorder.push_back(3);
	//inorder.push_back(4);
	//inorder.push_back(5);


	//test4
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(7);
	preorder.push_back(3);
	preorder.push_back(5);
	preorder.push_back(6);
	preorder.push_back(8);
	

	inorder.push_back(4);
	inorder.push_back(7);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(5);
	inorder.push_back(3);
	inorder.push_back(8);
	inorder.push_back(6);
}



BinaryTreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd)
{
	if (preorderStart == preorderEnd)
		return nullptr;
	int rootVal = preorder[preorderStart];
	int index = 0;
	for (int i = inorderStart; i < inorderEnd; i++)
	{
		if (inorder[i] == rootVal)
		{
			break;
		}
		else
		{
			index++;
		}
	}
	//这里有bug,可以用throw
	if (index >= inorderEnd - inorderStart)
	{
		throw std::exception("Invalid input(value mismatch).");
		//return nullptr;
	}
	int leftPreEnd = preorderStart + index + 1;
	int leftInEnd = inorderStart + index;

	int rightPreStart = preorderStart + index + 1;
	int rightInStart = inorderStart + index + 1;

	BinaryTreeNode * root = new BinaryTreeNode();
	root->m_nValue = rootVal;

	root->m_pLeft = recursion(preorder, inorder, preorderStart + 1, leftPreEnd, inorderStart, leftInEnd);
	root->m_pRight = recursion(preorder, inorder, rightPreStart, preorderEnd, rightInStart, inorderEnd);

	return root;
}


BinaryTreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() != inorder.size())
	{
		throw std::exception("Invalid input(size mismatch).");
	}
	return recursion(preorder, inorder, 0, preorder.size(), 0, inorder.size());
}



int main()
{
	vector<int> preorder;
	vector<int> inorder;
	inputFunction(preorder, inorder);
	try {
		BinaryTreeNode* root = buildTree(preorder, inorder);
		PrintTree(root);
	}
	catch (std::exception& exception)
	{
		cout << "Error:" << exception.what() << endl;
	}
	system("pause");
	return 0;
}