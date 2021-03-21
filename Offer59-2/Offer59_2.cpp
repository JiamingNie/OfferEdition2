/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，
要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：
输入:
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]

示例 2：
输入:
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：
1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5
*/
#include<iostream>
#include<deque>
#include<queue>
using namespace std;
class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		if (data.empty())
			return -1;
		return maxValue.front();
	}

	void push_back(int value) {
		data.push(value);
		while (!maxValue.empty()&&value>maxValue.back()) 
		{
			maxValue.pop_back();
		}
		maxValue.push_back(value);
	}

	int pop_front() {
		if (data.empty())
			return -1;
		int tmp = data.front();
		data.pop();
		if (tmp == maxValue.front())
		{
			maxValue.pop_front();
		}
		return tmp;
	}
private:
	deque<int> maxValue;
	queue<int> data;
};
int main()
{
	MaxQueue myque;
	cout << myque.max_value() << endl;
	cout << myque.pop_front() << endl;
	myque.push_back(1);
	cout << myque.max_value() << endl;
	myque.push_back(2);
	cout << myque.max_value() << endl;
	cout << myque.pop_front() << endl;
	cout << myque.max_value() << endl;
	return 0;
}