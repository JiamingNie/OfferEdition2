/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了
下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 
提示：
所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
*/
#include<vector>
#include<iostream>
using namespace std;

vector<int> constructArr(vector<int>& a) {
	vector<int> left(a.size(), 1);
	vector<int> right(a.size(), 1);
	for (int i = 1; i < a.size(); i++)
	{
		left[i] = left[i - 1] * a[i - 1];
	}
	for (int i = a.size()-2; i >=0; i--)
	{
		right[i] *= right[i + 1] * a[i + 1];
	}
	vector<int> res(a.size());
	for (int i = 0; i < a.size(); i++)
	{
		res[i] = left[i] * right[i];
	}
	return res;
}

//优化内存
vector<int> constructArr2(vector<int>& a) {
	vector<int> res(a.size(),1);
	int left = 1;
	int right = 1;
	for (int i = 1; i < a.size(); i++)
	{
		left *= a[i - 1];
		res[i] *= left;
	}

	for (int i = a.size() - 2; i >= 0; i--)
	{
		right *= a[i + 1];
		res[i] *= right;
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,2,3,4,5 };
	auto output = constructArr2(nums);
	for (auto& out : output)
	{
		cout << out << " ";
	}
	return 0;
}