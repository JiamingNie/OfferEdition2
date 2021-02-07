﻿/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。 

示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次
*/
#include<iostream>
#include"minStack.h"
using namespace std;
int main()
{
	MinStack minStack;
	minStack.push(3);
	cout << minStack.min() << endl;
	minStack.push(2);
	cout << minStack.min() << endl;
	minStack.pop();
	minStack.push(4);
	cout << minStack.min() << endl;
	minStack.pop();
	cout << minStack.min() << endl;
	minStack.pop();

	return 0;
}