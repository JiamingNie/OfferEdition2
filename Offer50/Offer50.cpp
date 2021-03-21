/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = ""
返回 " "
 

限制：

0 <= s 的长度 <= 50000
*/
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<unordered_map>

char firstUniqChar(string s) {
	unordered_map<char, int> hashMap;
	for (auto& c:s)
	{
		hashMap[c]++;
	}
	for (auto& c:s)
	{
		if (hashMap[c] == 1)
			return c;
	}
	return ' ';
}
//模拟哈希
char firstUniqChar2(string s) {
	int hashMap[26] = { 0 };
	for (auto& c : s)
	{
		hashMap[c - 'a']++;
	}
	for (auto& c : s)
	{
		if (hashMap[c - 'a'] == 1)
			return c;
	}
	return ' ';
}

int main()
{
	string s = "abaccdeff";
	auto output = firstUniqChar2(s);
	cout << output << endl;
	return 0;
}