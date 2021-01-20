/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."

限制：
0 <= s 的长度 <= 10000
*/
//niejiaming 20210120

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
//方法一：普通遍历，定义一个新字符串，然后对该字符串进行替换
string replaceSpace1(string s) {
	string res = "";
	for (auto& c : s)
	{
		if (c == ' ')
			res += "%20";
		else
			res += c;
	}
	return res;
}

//方法二：直接在原始字符串上进行操作，先遍历原始字符串得到空格的个数，然后扩充s的大小，最后从后向前遍历对空格进行替换
string replaceSpace2(string s) {
	int count = 0;
	int len = s.size();
	for (auto& c : s)
	{
		if (c == ' ')
			count++;
	}
	s.resize(len + count * 2);
	for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) 
	{
		if (s[i] != ' ')
		{
			s[j] = s[i];
		}
		else
		{
			s[j - 2] = '%';
			s[j - 1] = '2';
			s[j] = '0';
			j -= 2;
		}
	}
	return s;
}

int main()
{
	string s1 = " We are happy.  ";
	string s2 = " We are happy.  ";
	auto ans1 = replaceSpace1(s1);
	auto ans2 = replaceSpace2(s2);
	cout << "方法1替换后的字符串：" << ans1 << endl;
	cout << "方法2替换后的字符串：" << ans2 << endl;
	system("pause");
	return 0;
}