/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 

示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
	unordered_map<int, int> mp;
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		mp[nums[i]]++;
	}
	for (auto &m : mp)
	{
		if (m.second == 1)
		{
			res = m.first;
			break;
		}

	}
	return res;
}

int singleNumber2(vector<int>& nums) {
	vector<int> binary(32, 0);

	for (auto& n : nums)
	{
		for (int i = 0; i < 32 && n != 0; i++)
		{
			binary[i] += n & 1;
			n = n >> 1;
		}
	}

	int res = 0;

	for (int i=0;i<32;i++)
	{
		if (binary[i] % 3 != 0)
		{
			res += pow(2, i);
		}
	}

	return res;
}


int main()
{
	vector<int> nums = { 1,2,1,2,1,36,2 };
	auto output = singleNumber(nums);
	cout << output << endl;
	return 0;
}