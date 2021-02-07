/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，
否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

	 5
	/ \
   2   6
  / \
 1   3

示例 1：
输入: [1,6,3,2,5]
输出: false

示例 2：
输入: [1,3,2,6,5]
输出: true
 

提示：
数组长度 <= 1000
*/
#include<iostream>
#include<vector>
using namespace std;

bool recur(vector<int>& postorder, int left, int right)
{
	if (left >= right)
		return true;
	int pos = left;
	while (postorder[pos] < postorder[right])
	{
		pos++;
	}
	int split = pos;
	while (postorder[pos] > postorder[right])
	{
		pos++;
	}
	return pos == right && recur(postorder, left, split - 1) && recur(postorder, split, right - 1);
}

bool verifyPostorder(vector<int>& postorder) {
	return recur(postorder, 0, postorder.size() - 1);
}


int main()
{
	vector<int> postorder = { 1,3,2,6,5 };
	cout << verifyPostorder(postorder) << endl;
	return 0;
}