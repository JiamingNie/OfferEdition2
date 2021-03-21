/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：
1 <= 数组长度 <= 50000
*/

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
	int count = 1;
	int ret = nums[0];
	for (int i = 1; i < nums.size() - 1; i++)
	{
		if (nums[i] == ret)
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count == 0)
		{
			count = 1;
			ret = nums[++i];
		}
	}
	return ret;
}


int main()
{
	vector<int> nums = {1,2,2,2,1,1,2,2,1};

	int res = majorityElement(nums);

	cout << res << endl;

	return 0;
}