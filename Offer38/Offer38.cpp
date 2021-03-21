/*
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：
1 <= s 的长度 <= 8
*/
#include<iostream>
#include<vector>
using namespace std;
#include<string>
#include<algorithm>
vector<string> res;
string current;

void backTracking(string& s, vector<bool>& isVisit)
{
	if (current.size() == s.size())
	{
		res.push_back(current);
		return;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (isVisit[i])
			continue;
		if (i > 0 && s[i] == s[i - 1] && isVisit[i - 1])
			continue;
		isVisit[i] = true;
		current.push_back(s[i]);
		backTracking(s, isVisit);
		current.pop_back();
		isVisit[i] = false;
	}
}

vector<string> permutation(string s) {
	vector<bool> isVisit(s.size(), false);
	sort(s.begin(), s.end());
	backTracking(s, isVisit);
	return res;
}

int main()
{
	string input = "abcc";
	auto output = permutation(input);
	for (auto& str:output)
	{
		cout << str << " ";
	}
	cout << endl;
	return 0;
}