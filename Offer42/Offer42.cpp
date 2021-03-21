/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


 //动态规划
int maxSubArray1(vector<int>& nums) {
    int res=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i-1]>0)
        {
            nums[i]+=nums[i-1];
        }
        res=max(res,nums[i]);
    }
    return res;
}

//贪心
int maxSubArray2(vector<int>& nums) {
	int curValue = nums[0];
	int res = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (curValue > 0)
		{
			curValue += nums[i];
		}
		else
		{
			curValue = nums[i];
		}
		res = max(curValue, res);
	}
	return res;
}

int main()
{
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	auto res2 = maxSubArray2(nums);

	auto res1 = maxSubArray1(nums);

	return 0;
}