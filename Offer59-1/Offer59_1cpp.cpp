/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	deque<int> max;
	max.push_back(nums[0]);
	for (int i = 1; i < k; i++)
	{
		while (!max.empty() && nums[i] > max.back())
		{
			max.pop_back();
		}
		max.push_back(nums[i]);
	}

	for (int i = k; i < nums.size(); i++)
	{
		int tmp = max.front();
		res.push_back(tmp);
		if (nums[i - k] == tmp) 
		{
			max.pop_front();
		}
		while (!max.empty()&&nums[i] > max.back())
		{
			max.pop_back();
		}
		max.push_back(nums[i]);
		
	}
	res.push_back(max.front());
	return res;
}

int main()
{
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	auto output = maxSlidingWindow(nums, k);
	for (auto& o : output)
	{
		cout << o << endl;
	}
	return 0;
}