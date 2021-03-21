/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，
A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
输入: [1,2,3,4,5]
输出: True
 

示例 2:
输入: [0,0,1,2,5]
输出: True
 

限制：
数组长度为 5 

数组的数取值为 [0, 13] .
*/
#include<iostream>
#include<vector>
using namespace std;
bool isStraight(vector<int>& nums) {
	int numSet[14] = { 0 };
	int min = 14;
	int max = 0;
	for (auto& n : nums)
	{
		if (n != 0) 
		{
			numSet[n]++;
			if (numSet[n] >= 2) 
			{
				return false;
			}
			if (n > max)
			{
				max = n;
			}
			if (n < min)
			{
				min = n;
			}
		}
	}
	if (max - min < 5)
		return true;
	return false;
}

int main()
{
	vector<int> nums = { 0,0,1,2,5 };
	auto output = isStraight(nums);
	cout << output << endl;
	return 0;
}