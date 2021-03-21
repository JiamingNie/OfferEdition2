/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任
意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路
径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗
标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入这个格子。
 

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：
输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
 

提示：
1 <= board.length <= 200
1 <= board[i].length <= 200
*/
//niejiaming 20210131

#include<iostream>
#include<vector>
#include<string>
using namespace std;

////回溯法
//bool backTracking(vector<vector<char>>& board, string word, int startRow, int startCol, int index)
//{
//	if (startRow < 0 || startRow >= board.size() || startCol < 0 || startCol >= board[0].size() || board[startRow][startCol] != word[index])
//	{
//		return false;
//	}
//	else if (index == word.size() - 1)
//	{
//		return true;
//	}
//	index++;
//	int temp = board[startRow][startCol];//记录访问过的元素用于回溯
//	board[startRow][startCol] = '/0';//用/0代表已经访问过
//	if (backTracking(board, word, startRow - 1, startCol, index)|| backTracking(board, word, startRow + 1, startCol, index)|| 
//		backTracking(board, word, startRow, startCol - 1, index)|| backTracking(board, word, startRow, startCol + 1, index))
//	{
//		return true;//如果有一条路径满足就返回true
//	}
//	index--;
//	board[startRow][startCol] = temp;//回溯
//	return false;
//
//}
//
//bool exist(vector<vector<char>>& board, string word) {
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			if (backTracking(board, word, i, j, 0))
//				return true;
//		}
//	}
//	return false;
//}

//二刷
bool backTracking(vector<vector<char>>& board, string word, vector<vector<bool>>& isVisit, int startRow, int startCol, int index)
{
	if (startRow < 0 || startRow >= board.size() || startCol < 0 || startCol >= board[0].size() || board[startRow][startCol] != word[index]||isVisit[startRow][startCol])
	{
		return false;
	}
	else if (index == word.size()-1)
	{
		return true;
	}
	isVisit[startRow][startCol] = true;
	index++;
	if (backTracking(board, word, isVisit, startRow + 1, startCol, index) || backTracking(board, word, isVisit, startRow - 1, startCol, index) || 
		backTracking(board, word, isVisit, startRow, startCol + 1, index) || backTracking(board, word, isVisit, startRow, startCol - 1, index))
	{
		return true;
	}
	index--;
	isVisit[startRow][startCol] = false;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	vector<vector<bool>> isVisit(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (backTracking(board, word, isVisit, i, j, 0))
			{
				return true;
			}
		}
	}
	return false;
}




int main()
{
	vector<vector<char>> board{ {'a', 'b', 'c', 'e'},
								{'s', 'f', 'c', 's'},
								{'a', 'd', 'e', 'e'} };

	if (exist(board,"abcced"))
	{
		cout << "存在该字符串" << endl;
	}
	else
	{
		cout << "不存在该字符串" << endl;
	}
	return 0;
}