/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"

输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

提示：
s.length <= 40000
*/

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

int lengthOfLongestSubstring(string s) {
	int res = 0;
	int left = 0;
	int right = 0;
	unordered_map<char, int> hashMap;
	while (right < s.size())
	{
		if (hashMap.find(s[right]) != hashMap.end())
		{
			left = max(left, hashMap[s[right]]);
		}
		hashMap[s[right]] = right + 1;
		right++;
		res = max(res, right - left);
	}
	return res;
}

int lengthOfLongestSubstring(string s) {
	if (s.size() < 1)
		return 0;
	unordered_set<char> sss;
	int res = -1;
	int right = 0;
	for (int left = 0; left < s.size(); left++)
	{
		while (right < s.size() && !sss.count(s[right]))
		{
			sss.insert(s[right]);
			right++;
		}
		res = max(res, right - left);
		sss.erase(s[left]);
		if (right >= s.size()) { break; }
	}
	return res;
}

int main()
{
	string s = "abcabcbb";
	auto output = lengthOfLongestSubstring(s);

	cout << output << endl;
	return 0;
}