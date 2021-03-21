/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：
输入: n = 3
输出: 6

示例 2：
输入: n = 9
输出: 45
 

限制：
1 <= n <= 10000
*/
#include<iostream>
#include<vector>
using namespace std;

//int sumNums(int n) {
//	if (n == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return n + sumNums(n - 1);
//	}
//}

//方法一
//int sumNums(const int n) {
//	bool a[n][n + 1];
//	return sizeof(a) >> 1;
//}
//方法二
int sumNums(int n) {
	n && (n += sumNums(n - 1));
	return n;
}

int main()
{
	cout << sumNums(100) << endl;
	return 0;
}