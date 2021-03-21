//二叉树的遍历：递归和循环
#include"../Utilities/BinaryTree.h"
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void inorderRecursive(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	inorderRecursive(root->m_pLeft);
	cout << root->m_nValue << endl;
	inorderRecursive(root->m_pRight);
}

void inorderNonRecursive(BinaryTreeNode* root) 
{
	if (root == nullptr)
		return;
	stack<BinaryTreeNode*> value;
	BinaryTreeNode* cur = root;
	while (!value.empty() || cur!=nullptr)
	{
		if (cur != nullptr)
		{
			value.push(cur);
			cur = cur->m_pLeft;
		}
		else
		{
			cur = value.top();
			value.pop();
			cout << cur->m_nValue << endl;
			cur = cur->m_pRight;
		}
		
	}
}

void preOrderRecursive(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	cout << root->m_nValue << endl;
	preOrderRecursive(root->m_pLeft);
	preOrderRecursive(root->m_pRight);
}

void preOrderNonRecursive(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	stack<BinaryTreeNode*> value;
	BinaryTreeNode* cur = root;
	while (!value.empty() || cur != nullptr)
	{
		if (cur != nullptr)
		{
			cout << cur->m_nValue << endl;
			value.push(cur);
			cur = cur->m_pLeft;
		}
		else
		{
			cur = value.top();
			value.pop();
			cur = cur->m_pRight;
		}

	}
}

void postOrderRecursive(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;
	postOrderRecursive(root->m_pLeft);
	postOrderRecursive(root->m_pRight);
	cout << root->m_nValue << endl;
}

void postOrderNonRecursive(BinaryTreeNode* root)
{
	if (root == NULL)
		return;
	stack<BinaryTreeNode*> s;
	//pCur:当前访问节点，pLastVisit:上次访问节点
	BinaryTreeNode* pCur, *pLastVisit;

	pCur = root;
	pLastVisit = NULL;
	//先把pCur移动到左子树最下边
	while (pCur)
	{
		s.push(pCur);
		pCur = pCur->m_pLeft;
	}
	while (!s.empty())
	{
		//走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
		pCur = s.top();
		s.pop();
		//一个根节点被访问的前提是：无右子树或右子树已被访问过
		if (pCur->m_pRight == NULL || pCur->m_pRight == pLastVisit)
		{
			cout << pCur->m_nValue << endl;
			//修改最近被访问的节点
			pLastVisit = pCur;
		}
		/*这里的else语句可换成带条件的else if:
		else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
		因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
		*/
		else
		{
			//根节点再次入栈
			s.push(pCur);
			//进入右子树，且可肯定右子树一定不为空
			pCur = pCur->m_pRight;
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->m_pLeft;
			}
		}
	}
	cout << endl;
}

//创建一棵树的核心代码
BinaryTreeNode* createTreeCore(vector<int> inorder, vector<int> preorder,int inorderStart,int inorderEnd,int preorderStart,int preorderEnd)
{
	if (inorder.size() != preorder.size() || inorderStart >= inorderEnd)
	{
		return nullptr;
	}
	int index = 0;
	for (int i = inorderStart; i < inorderEnd; i++)
	{
		if (inorder[i] == preorder[preorderStart])
			index = i;
	}
	int count = index - inorderStart;
	BinaryTreeNode* root = CreateBinaryTreeNode(preorder[preorderStart]);

	root->m_pLeft = createTreeCore(inorder, preorder, inorderStart, index, preorderStart + 1, preorderStart + count);

	root->m_pRight = createTreeCore(inorder, preorder, index + 1, inorderEnd, preorderStart + count + 1, preorderEnd);

	return root;
}
//创建一棵树
BinaryTreeNode* createTree(vector<int> inorder, vector<int> preorder)
{
	if (inorder.size() != preorder.size() || inorder.size() == 0)
	{
		return nullptr;
	}

	return createTreeCore(inorder, preorder, 0, inorder.size(), 0, preorder.size());

}

int main() 
{
//            8
//         /      \
//        6        10
//       /\        /\
//      5  7     9   11
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

	cout << "inorderRecursive" << endl;
	inorderRecursive(pNode8);
	cout << "inorderNonRecursive" << endl;
	inorderNonRecursive(pNode8);

	cout << "preOrderRecursive" << endl;
	preOrderRecursive(pNode8);
	cout << "preOrderNonRecursive" << endl;
	preOrderNonRecursive(pNode8);

	cout << "postOrderRecursive" << endl;
	postOrderRecursive(pNode8);
	cout << "postOrderNonRecursive" << endl;
	postOrderNonRecursive(pNode8);


//            8
//         /      \
//        6        10
//       /         /\
//      5         9  11
	vector<int> inorder = {5,6,8,9,10,11};
	vector<int> preorder = {8,6,5,10,9,11};

	auto createTreeRoot = createTree(inorder, preorder);
	PrintTree(createTreeRoot);

	return 0;
}