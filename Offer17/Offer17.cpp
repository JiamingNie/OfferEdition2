/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：
用返回一个整数列表来代替打印
n 为正整数
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<vector>
using namespace std;

//方法一：不考虑大数问题
vector<int> printNumbers1(int n) {
    vector<int> res;
    int maxNum=pow(10,n);
    for(int i=1;i<maxNum;i++)
        res.push_back(i);
    return res;
}

bool incresment(string& s)
{
	bool overFlow = false;
	int size = s.size();
	int carry = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		int current = s[i] - '0' + carry;
		if (i==size-1)
		{
			current++;
		}
		if (current >= 10)
		{
			
			if (i == 0)
			{
				overFlow = true;
			}
			else
			{
				carry = 1;
				s[i] = current - 10 + '0';
			}
		}
		else
		{
			s[i] = current + '0';
			break;
		}
	}
	return overFlow;
}

void inputNumber(string& s, vector<int>& res)
{
	string tmp;
	bool flag = true;
	for (int i=0;i<s.size();i++)
	{
		if (flag&&s[i] != '0') flag = false;
		if (!flag) tmp.push_back(s[i]);
	}
	res.push_back(stoi(tmp));
}
//方法二：考虑大数问题
vector<int> printNumbers2(int n) {
	vector<int> res;
	string s(n, '0');
	while (!incresment(s))
	{
		inputNumber(s, res);
	}
	return res;
}

int main()
{
	//auto ans = printNumbers1(3);
	auto ans = printNumbers2(3);
	return 0;
}