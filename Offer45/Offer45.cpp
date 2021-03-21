/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。

示例 1:
输入: [10,2]
输出: "102"

示例 2:
输入: [3,30,34,5,9]
输出: "3033459"
 

提示:
0 < nums.length <= 100
说明:
输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

*/
#include<string>
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

string minNumber(vector<int>& nums) {
	if (nums.size() == 1)
		return to_string(nums[0]);
	vector<string> numString;
	for (int i=0;i<nums.size();i++)
	{
		numString.push_back(to_string(nums[i]));
	}
	sort(numString.begin(), numString.end(), [&](string& a, string& b) {return a + b < b + a; });

	string res = "";
	for (int i=0;i<numString.size();i++)
	{
		res += numString[i];
	}
	return res;
}

int main()
{
	vector<int> nums = { 3,30,34,5,9 };
	auto output = minNumber(nums);
	cout << output << endl;
	return 0;
}