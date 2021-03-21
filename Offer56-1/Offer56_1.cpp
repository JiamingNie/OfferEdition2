/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出
这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：
2 <= nums.length <= 10000
*/
#include<iostream>
#include<vector>
using namespace std;


vector<int> singleNumbers(vector<int>& nums) {
	int sum = 0;
	for (auto& n : nums)
	{
		sum ^= n;
	}
	int i = 1;
	while ((sum&i) == 0)
	{
		i <<= 1;
	}
	int a = 0;
	int b = 0;
	for (auto&n : nums)
	{
		if ((n&i) != 0)
			a ^= n;
		else
			b ^= n;
	}
	return { a,b };
}

int main()
{
	vector<int> nums = { 1,2,10,4,1,4,3,3 };
	auto output = singleNumbers(nums);
	for (auto& out : output)
		cout << out << endl;
	return 0;
}