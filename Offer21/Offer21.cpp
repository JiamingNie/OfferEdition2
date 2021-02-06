/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数
位于数组的前半部分，所有偶数位于数组的后半部分。

示例：
输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。

提示：
1 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> exchange1(vector<int>& nums)
{
	int fast = 0;
	int low = 0;
	while (fast < nums.size())
	{
		if (nums[fast] % 2 == 1)
		{
			swap(nums[low], nums[fast]);
			low++;
		}
		fast++;
	}
	return nums;
}

vector<int> exchange2(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left < right)
	{
		if (nums[left] % 2 == 1)
		{
			left++;
			continue;
		}
		if (nums[right] % 2 == 0)
		{
			right--;
			continue;
		}
		swap(nums[left], nums[right]);
	}
	return nums;
}

int main()
{
	vector<int> nums1{ 1,2,3,4 };
	vector<int> nums2{ 1,2,3,4 };
	auto ans1 = exchange1(nums1);

	auto ans2 = exchange2(nums2);

	for (auto& a : ans1)
	{
		cout << a << " ";
	}
	cout << endl;

	for (auto& a : ans2)
	{
		cout << a << " ";
	}
	cout << endl;
}