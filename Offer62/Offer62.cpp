/*
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个
数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删
除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。


示例 1：
输入: n = 5, m = 3
输出: 3

示例 2：
输入: n = 10, m = 17
输出: 2
 
限制：
1 <= n <= 10^5
1 <= m <= 10^6
*/
//https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/jian-zhi-offer-62-yuan-quan-zhong-zui-ho-dcow/
#include<iostream>
using namespace std;
int lastRemaining(int n, int m) {
	int x = 0;
	for (int i = 2; i <= n; i++) {
		x = (x + m) % i;
	}
	return x;
} 

int main()
{
	auto output = lastRemaining(10, 17);
	cout << output << endl;
	return 0;
}