/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]

示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5
*/
#include<iostream>
#include<vector>
using namespace std;
//滑动窗口
vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>> ans;
	vector<int> current;
	int i = 1;
	int j = 1;
	int sum = 1;
	while (i <= target / 2)
	{
		if (sum > target)
		{
			sum -= i;
			i++;
		}
		else if (sum < target)
		{
			j++;
			sum += j;
		}
		else
		{
			current.clear();
			for (int n = i; n <= j; n++)
			{
				current.push_back(n);
			}
			ans.push_back(current);
			sum -= 2 * i + 1;
			i += 2;
		}
	}
	return ans;
}

int main()
{
	auto output = findContinuousSequence(15);
	for (auto& out:output)
	{
		for (auto& o:out)
		{
			cout << o << " ";
		}
		cout << endl;
	}
	return 0;
}