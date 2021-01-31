/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k
的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，
因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：
输入：m = 2, n = 3, k = 1
输出：3

示例 2：
输入：m = 3, n = 1, k = 0
输出：1

提示：
1 <= n,m <= 100
0 <= k <= 20
*/
//niejiaming 20210131

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int getDigitSum(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}


//深度优先遍历
int dfs(vector<vector<bool>>& isVisit,int i,int j,int row,int col,int digitMaxSum)
{
	if (i < row&&j < col && !isVisit[i][j] && getDigitSum(i) + getDigitSum(j) <= digitMaxSum)
	{
		isVisit[i][j] = true;
		return 1 + dfs(isVisit, i + 1, j, row, col, digitMaxSum) + dfs(isVisit, i, j + 1, row, col, digitMaxSum);
		
	}
	return 0;
}

int movingCount(int m, int n, int k) {
	vector<vector<bool>> isVisit(m, vector<bool>(n, false));
	return dfs(isVisit, 0, 0, m, n, k);
}

//广度优先遍历
int movingCount2(int m, int n, int k) {
	int res = 0;
	vector<vector<bool>> isVisit(m, vector<bool>(n, false));
	queue<vector<int>> que;
	que.push({0,0});
	
	while (!que.empty())
	{
		vector<int> tmp = que.front();
		que.pop();
		int a = tmp[0], b = tmp[1];
		if (a < m&&b < n && !isVisit[a][b] && getDigitSum(a) + getDigitSum(b) <= k)
		{
			isVisit[a][b] = true;
			res++;
			que.push({ a + 1,b });
			que.push({ a,b + 1 });
		}
	}
	return res;
}



int main()
{
	//int sum = movingCount(3, 10, 100);
	int sum = movingCount2(2, 3, 0);
	cout << "一共能走过的路程是：" << sum << "步！" << endl;
	return 0;
}