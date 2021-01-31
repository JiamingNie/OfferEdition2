/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数
组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：
输入：[3,4,5,1,2]
输出：1

示例 2：
输入：[2,2,2,0,1]
输出：0
*/
//niejiaming 20210130

#include<iostream>
#include<vector>
using namespace std;


//常规遍历法
int RotatedArray_Solution1(const vector<int>& nums)
{
	int min = INT_MAX;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < min)
			min = nums[i];
	}
	return min;
}
//二分法
int RotatedArray_Solution2(const vector<int>& nums)
{
	int min = INT_MAX;
	int left = 0;
	int right = nums.size() - 1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid]<nums[right])
		{
			right = mid;
		}
		else if(nums[mid] > nums[right])
		{
			left = mid + 1;
		}
		else if (nums[mid] == nums[right])
		{
			right = right - 1;
		}
	}
	return nums[left];
}


int main()
{
	vector<int> nums{ 2,1,2,2,2,2 };

	cout << "RotatedArray_Solution1(nums)" << endl;
	cout << RotatedArray_Solution1(nums) << endl;
	
	cout << "RotatedArray_Solution2(nums)" << endl;
	cout << RotatedArray_Solution2(nums) << endl;

	system("pause");
	return 0;
}