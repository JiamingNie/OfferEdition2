/*
��Ŀ����
����һ���ǿ�ģ�崮S��һ���ı���T����S��T�г����˶��ٴ�

ʾ��1:
����
"ababab","abababab"
����ֵ
2

ʾ��2:
����
"abab","abacabab"
����ֵ
1
��ע:
�ռ�O(n)ʱ��O(n)���㷨
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//��ƥ��λ��
//void getNextVal(vector<int>& next,string& t)
//{
//	next[0] = -1;
//	int i = 0;
//	int j = -1;
//	while (i < int(t.size()) - 1)
//	{
//		if (j == -1 || t[i] == t[j])
//		{
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//}
//
//int KMP(string s, string t)
//{
//	vector<int> next(t.size());
//	getNextVal(next, t);
//	int i = 0;
//	int j = 0;
//	int size1 = s.size();
//	int size2 = t.size();
//	while (i < size1 && j < size2)
//	{
//		if (j == -1 || s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j >= t.size())
//		return i - j;
//	else
//		return -1;
//}


//int KMP(string s, string t)
//{
//	vector<int> next(t.size());
//	getNextVal(next, t);
//	int i = 0;
//	int j = 0;
//	while (i < s.size() && j < t.size())//�����size�������޷������ͣ�j=-1ʱ�Ƚϻ���ִ���
//	{
//		if (j == -1 || s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j >= t.size())
//		return i - j;
//	else
//		return -1;
//}

////��ƥ�����
//void getNextVal(vector<int>& next, string& t)
//{
//	next[0] = -1;
//	int i = 0;
//	int j = -1;
//	while (i < int(t.size()) - 1)
//	{
//		if (j == -1 || t[i] == t[j])
//		{
//			i++;
//			j++;
//			next[i] = j;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//}
//
//int KMP(string s, string t)
//{
//	vector<int> next(t.size());
//	getNextVal(next, t);
//	int res = 0;
//	int i = 0;
//	int j = 0;
//	int size1 = s.size();
//	int size2 = t.size();
//	while (i < size1 && j < size2)
//	{
//		if (j == -1 || s[i] == t[j])
//		{
//			i++;
//			j++;
//			if (j == size2)
//			{
//				res++;
//				i = i - j + 1;
//				j = 0;
//			}
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	return res;
//}

//ţ��
void getNextVal(const string&S, vector<int>& next)
{
	next[0] = -1;
	int i = 0;
	int j = -1;
	int tSize = S.size();
	while (i < tSize - 1)
	{
		if (j == -1 || S[i] == S[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
int kmp(string S, string T) {
	// write code here
	vector<int> next(S.size());
	getNextVal(S, next);
	int res = 0;
	int i = 0;
	int j = 0;
	int sSize = S.size();
	int tSize = T.size();
	while (i < tSize && j < sSize)
	{
		if (j == -1 || S[j] == T[i])
		{
			if (j == sSize-1)
			{
				res++;
   				j = next[j];
				//i = i - j + 1;
				//j = 0;
			}
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	return res;
}

int main()
{
	string s = "abababab";
	string t = "ababab";
	//int output = KMP(s, t);
	int output = kmp(t, s);

	cout << output << endl;
	return 0;
}