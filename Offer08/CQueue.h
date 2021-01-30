#pragma once
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead
 操作返回 -1 )

示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]


示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

提示：
1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用


*/
#include<stack>
using namespace std;

class CQueue
{
public:
	CQueue();
	~CQueue();
	// 在队列末尾添加一个结点
	void appendTail(int value);
	// 删除队列的头结点
	int deleteHead();
private:
	stack<int> stack1;//添加节点
	stack<int> stack2;//删除节点
};

CQueue::CQueue()
{

}

CQueue::~CQueue()
{

}

void CQueue::appendTail(int value)
{
	stack1.push(value);
}

int CQueue::deleteHead()
{
	//如果stack2为空，则将stack1的元素全放进stack2中，这时stack2是appendTail的正序
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	//如果stack2为空，那么返回-1
	if (stack2.empty())
	{
		return -1;
	}
	int res = stack2.top();
	stack2.pop();
	return res;
}