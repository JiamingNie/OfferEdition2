/*
����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������
11 ����� ��l����������25 ����� ��z����һ�����ֿ����ж�����롣����ʵ��һ����������
������һ�������ж����ֲ�ͬ�ķ��뷽����

ʾ�� 1:
����: 12258
���: 5
����: 12258��5�ֲ�ͬ�ķ��룬�ֱ���"bccfi", "bwfi", "bczi", "mcfi"��"mzi"

��ʾ��
0 <= num < 231
*/

#include<string>
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int translateNum(int num) {
	if (num <= 9)
		return 1;
	string numStr = to_string(num);
	int dp0 = 1;
	int dp1 = 1;
	int dp2 = 0;
	for (int i = 1; i < numStr.size(); i++)
	{
		dp2 = dp1;
		string tmp = numStr.substr(i - 1, 2);
		if (tmp >= "10"&&tmp <= "25")
		{
			dp2 += dp0;
		}
		dp0 = dp1;
		dp1 = dp2;
	}
	return dp2;
}

//int translateNum(int num) {
//	if (num <= 9)
//		return 1;
//	string str = to_string(num);
//	int size = str.size();
//	int res0 = 1;
//	int res1 = 1;
//	int res2 = 0;
//	for (int i = 2; i <= size; i++)
//	{
//		res2 += res1;
//		auto pre = str.substr(i - 2, 2);
//		if (pre <= "25"&&pre >= "10")
//			res2 += res0;
//		res0 = res1;
//		res1 = res2;
//		res2 = 0;
//	}
//	return res1;
//}

int main()
{
	int num = 12258;
	int output = translateNum(num);
	cout << output << endl;
	return 0;
}