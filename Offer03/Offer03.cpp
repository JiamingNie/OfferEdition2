/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每
个数字重复了几次。请找出数组中任意一个重复的数字。
例如：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
*/
//niejiaming 20210120

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

//排序算法加遍历
//时间复杂度o(nlogn)
//空间复杂度o(1)
int findRepeatNumber1(vector<int>& nums) {
	int size = nums.size();
	if (size < 2 || size>100000)
		return INT_MAX;
	sort(nums.begin(), nums.end());
	for (int i = 1; i < size - 1; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			return nums[i];
		}
	}
	return INT_MAX;
}

//哈希表查找算法
//时间复杂度o(n)
//空间复杂度o(n)
int findRepeatNumber2(vector<int>& nums) {
	unordered_set<int> store;
	for (auto& n:nums)
	{
		if (store.find(n) != store.end())
		{
			return n;
		}
		store.insert(n);
	}
	return INT_MAX;
}

//原地哈希
//时间复杂度o(n)
//空间复杂度o(1)
int findRepeatNumber3(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] != i)     //当前元素不等于下标
		{
			if (nums[i] == nums[nums[i]])    
				return nums[i];
			else
				swap(nums[i], nums[nums[i]]);
		}
	}
	return -1;
}

int main()
{
	vector<int> nums1 = { 2, 3, 1, 0, 2, 5, 3 };
	vector<int> nums2 = { 2, 3, 1, 0, 2, 5, 3 };
	vector<int> nums3 = { 2, 3, 1, 0, 2, 5, 3 };
	int ans1 = findRepeatNumber1(nums1);
	int ans2 = findRepeatNumber2(nums2);
	int ans3 = findRepeatNumber3(nums3);
	cout << "方法1计算出的重复数字是：" << ans1 << endl;
	cout << "方法2计算出的重复数字是：" << ans2 << endl;
	cout << "方法3计算出的重复数字是：" << ans3 << endl;
	system("pause");
	return 0;
}