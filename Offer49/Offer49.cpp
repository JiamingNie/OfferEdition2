/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  
1 是丑数。
n 不超过1690。
*/
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

int nthUglyNumber(int n) {
	int two = 0;
	int three = 0;
	int five = 0;
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int num0 = dp[two] * 2;
		int num1 = dp[three] * 3;
		int num2 = dp[five] * 5;
		dp[i] = min(min(num0, num1), num2);
		if (dp[i] == num0)
			two++;
		if (dp[i] == num1)
			three++;
		if (dp[i] == num2)
			five++;
	}
	return dp[n - 1];
}

int main()
{
	int n = 10;
	cout << nthUglyNumber(n) << endl;

	return 0;
}