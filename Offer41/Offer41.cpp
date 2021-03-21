/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值
排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之
后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例 1：
输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：

最多会对 addNum、findMedian 进行 50000 次调用。
*/
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

void addNum(int num) {
	if (maxheap.size()==minheap.size())
	{
		maxheap.push(num);
		minheap.push(maxheap.top());
		maxheap.pop();
	}
	else
	{
		minheap.push(num);
		maxheap.push(minheap.top());
		minheap.pop();
	}
}

double findMedian() {
	return maxheap.size() != minheap.size() ? minheap.top() : (maxheap.top() + minheap.top()) / 2.0;
}

int main()
{
	addNum(1);
	auto med1 = findMedian();
	addNum(2);
	auto med2 = findMedian();
	addNum(3);
	auto med3 = findMedian();
	addNum(2);
	auto med4 = findMedian();
	addNum(0);
	auto med5 = findMedian();

	cout << med1 << " " << med2 << " " << med3 << " " << med4 << " " << med5 << endl;

	return 0;
}