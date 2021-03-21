/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则输出任意一对即可。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

示例 2：
输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

限制：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(target - nums[i]) != m.end())
			return { nums[i],target - nums[i] };
		m[nums[i]]++;
	}
	return {};
}

vector<int> twoSum2(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left<right)
	{
		if (nums[left] + nums[right] == target)
		{
			return { nums[left],nums[right] };
		}
		else if (nums[left] + nums[right] < target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return {};
}

int main()
{
	vector<int> nums = { 10,26,30,31,47,60 };
	int target = 40;
	auto output = twoSum2(nums, target);
	for (auto& out : output)
		cout << out << endl;
	return 0;
}