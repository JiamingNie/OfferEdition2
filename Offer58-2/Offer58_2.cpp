/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcde
fg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"

示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：
1 <= k < s.length <= 10000
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string reverseLeftWords(string s, int n) {
	n = n % s.size();
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	reverse(s.begin(), s.end());
	return s;
}

string reverseLeftWords2(string s, int n) {
	int size = s.size();
	if (size <= 1)
		return s;
	n = n % size;
	vector<char> c;
	for (int i = 0; i < n; i++)
	{
		c.push_back(s[i]);
	}
	for (int i = 0; i < size - n; i++)
	{
		s[i] = s[i + n];
	}
	for (int i = 0; i < n; i++)
	{
		s[size - n + i] = c[i];
	}
	return s;
}

int main()
{
	string intput = "abcdefghi";
	string output = reverseLeftWords(intput, 10);
	cout << output << endl;
	return 0;
}