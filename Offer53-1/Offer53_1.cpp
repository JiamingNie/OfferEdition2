/*
统计一个数字在排序数组中出现的次数。

 

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

限制：

0 <= 数组长度 <= 50000
*/
#include<iostream>
#include<vector>
using namespace std;

int leftBound(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			right = mid - 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	if (left >= nums.size() || nums[left] != target)
	{
		return -1;
	}
	return left;
}

int rightBound(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid]==target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}

int search(vector<int>& nums, int target) {
	int left = leftBound(nums, target);
	if (left == -1)
		return 0;
	int right = rightBound(nums, target);
	return right - left + 1;
}

int main()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 11;
	int output = search(nums, target);
	cout << output << endl;
	return 0;
}