#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	if (matrix.size() == 0)
		return ans;
	int up = 0;
	int down = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;
	while (true)
	{
		for (int i = left; i <= right; i++)
		{
			ans.push_back(matrix[up][i]);
		}
		if (++up > down)
			break;
		for (int i = up; i <= down; i++)
		{
			ans.push_back(matrix[i][right]);
		}
		if (--right < left)
			break;
		for (int i = right; i >= left; i--)
		{
			ans.push_back(matrix[down][i]);
		}
		if (--down < up)
			break;
		for (int i = down; i >= up; i--)
		{
			ans.push_back(matrix[i][left]);
		}
		if (++left > right)
			break;
	}
	return ans;
}

int main()
{
	vector<vector<int>> nums = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	auto sum = spiralOrder(nums);
	int a = pow(2, 3);
	//vector<vector<int>> ans(vector<int>(4, 0));
	system("pause");
	return 0;
}