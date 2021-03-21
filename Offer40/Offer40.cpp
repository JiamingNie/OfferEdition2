/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8
这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void quickSort(vector<int>& arr, int left, int right)
{
	if (left >= right) return;
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j&&arr[j] >= arr[left]) j--;
		while (i < j&&arr[i] <= arr[left]) i++;
		
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[left]);
	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}


vector<int> getLeastNumbers(vector<int>& arr, int k) {
	vector<int> res;
	//sort(arr.begin(), arr.end());
	quickSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < k; i++)
	{
		res.push_back(arr[i]);
	}
	return res;
}

vector<int> getLeastNumbers2(vector<int>& arr, int k) {
	vector<int> ret;
	if (k == 0) { // 排除 0 的情况
		return ret;
	}
	priority_queue<int, vector<int>, less<int> > Q;
	for (int i = 0; i < k; i++)
	{
		Q.push(arr[i]);
	}
	for (int i = k; i < arr.size(); i++)
	{
		if (arr[i] < Q.top())
		{
			Q.pop();
			Q.push(arr[i]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		ret.push_back(Q.top());
		Q.pop();
	}
	return ret;
}

vector<int> quickSort(vector<int>& arr, int left, int right, int k)
{
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j&&arr[j] >= arr[left]) j--;
		while (i < j&&arr[i] <= arr[left]) i++;
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[left]);
	if (i > k) return quickSort(arr, left, i - 1, k);
	if (i < k) return quickSort(arr, i + 1, right, k);
	vector<int> ret;
	ret.assign(arr.begin(), arr.begin() + k);
	return ret;
}

vector<int> getLeastNumbers3(vector<int>& arr, int k) {
	if (k >= arr.size()) return arr;
	return quickSort(arr, 0, arr.size() - 1, k);
}


int main()
{
	vector<int> nums = { 0,1,2,1 };

	auto output = getLeastNumbers(nums, 3);

	for(auto& out:output)
		cout << out << endl;

	return 0;
}