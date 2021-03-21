//�������ı������ݹ��ѭ��
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
	//pCur:��ǰ���ʽڵ㣬pLastVisit:�ϴη��ʽڵ�
	BinaryTreeNode* pCur, *pLastVisit;

	pCur = root;
	pLastVisit = NULL;
	//�Ȱ�pCur�ƶ������������±�
	while (pCur)
	{
		s.push(pCur);
		pCur = pCur->m_pLeft;
	}
	while (!s.empty())
	{
		//�ߵ����pCur���ǿգ����Ѿ��������������׶�(�����������������գ�����ĳ����������)
		pCur = s.top();
		s.pop();
		//һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ�
		if (pCur->m_pRight == NULL || pCur->m_pRight == pLastVisit)
		{
			cout << pCur->m_nValue << endl;
			//�޸���������ʵĽڵ�
			pLastVisit = pCur;
		}
		/*�����else���ɻ��ɴ�������else if:
		else if (pCur->lchild == pLastVisit)//���������ձ����ʹ��������Ƚ���������(���ڵ����ٴ���ջ)
		��Ϊ�����������ûͨ����һ����������������㡣��ϸ���룡
		*/
		else
		{
			//���ڵ��ٴ���ջ
			s.push(pCur);
			//�������������ҿɿ϶�������һ����Ϊ��
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

//����һ�����ĺ��Ĵ���
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
//����һ����
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