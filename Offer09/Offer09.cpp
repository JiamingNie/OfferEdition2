/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
//niejiaming 20210130


#include<iostream>
#include<vector>
using namespace std;

//Fibonacci递归解法
int Fibonacci_Solution1(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		return (Fibonacci_Solution1(n - 1) % 1000000007 + Fibonacci_Solution1(n - 2) % 1000000007)% 1000000007;
	}
}
//Fibonacci DP 解法
int Fibonacci_Solution2(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		int dp0 = 0;
		int dp1 = 1;
		int dp2;
		for (int i=2;i<=n;i++)
		{
			dp2 = (dp0 % 1000000007 + dp1 % 1000000007) % 1000000007;
			dp0 = dp1;
			dp1 = dp2;
		}
		return dp1;
	}
}


void test()
{
	cout << Fibonacci_Solution1(20) << endl;
	cout << Fibonacci_Solution2(40) << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}
