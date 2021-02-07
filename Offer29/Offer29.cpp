/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*/

#include<iostream>
using namespace std;
#include<vector>

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0)
		return {};
	vector<int> ans;
	int endX = matrix.size() - 1;
	int endY = matrix[0].size() - 1;
	int startX = 0;
	int startY = 0;
	while (true)
	{
		//上
		for (int i = startY; i <= endY; i++)
		{
			ans.push_back(matrix[startX][i]);
		}
		if (++startX > endX)
			break;
		//右
		for (int i = startX; i <= endX; i++)
		{
			ans.push_back(matrix[i][endY]);
		}
		if (--endY < startY)
			break;
		//下
		for (int i = endY; i >= startY; i--)
		{
			ans.push_back(matrix[endX][i]);
		}
		if (--endX < startX)
			break;
		//左
		for (int i = endX; i >= startX; i--)
		{
			ans.push_back(matrix[i][startY]);
		}
		if (++startY > endY)
			break;
	}
	return ans;
}

int main()
{
	int columns=5, rows = 4;
	printf("Test Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return 0;

	vector<vector<int>> matrix(rows, vector<int>(columns, -1));
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = i * columns + j + 1;
		}
	}

	for (auto& m : matrix)
	{
		for(auto &a:m)
			cout << a << "	";
		cout << endl;
	}
	cout << endl;

    auto ans = spiralOrder(matrix);
	for (auto& a:ans)
	{
		cout << a << " ";
	}
	cout << endl;

	return 0;
}