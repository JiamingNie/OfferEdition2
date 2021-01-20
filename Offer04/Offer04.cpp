/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入
这样的一个二维数组和一个整数，判断数组中是否含有该整数。

现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/
//niejiaming 20210120

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//暴力法
//时间复杂度o(n*m)
bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()||matrix.size()==0||matrix[0].size()==0)return false;
    int width = matrix[0].size()-1;
    int higth = matrix.size()-1;
    if(target<matrix[0][0]&&target>matrix[higth][width])
        return false;
    for(int h =0;h <= higth;h++)
    {
        for(int w = 0;w<=width;w++)
        {
            if(matrix[h][w]==target)
                return true;
        }
    }
    return false;
}


//线性查找
//时间复杂度o(n+m)
/*
注意这是一个部分有序的二维数组，每次遍历完都可以排除一行或者一列元素。
从二维数组的右上角开始查找。如果当前元素等于目标值，则返回 true。
如果当前元素大于目标值，则移到左边一列。如果当前元素小于目标值，则移到下边一行。
若数组为空，返回 false
初始化行下标为 0，列下标为二维数组的列数减 1
重复下列步骤，直到行下标或列下标超出边界
获得当前下标位置的元素 num
如果 num 和 target 相等，返回 true
如果 num 大于 target，列下标减 1
如果 num 小于 target，行下标加 1
*/
bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int higth = matrix.size() - 1;
	int width = matrix[0].size() - 1;
	if (target<matrix[0][0] || target>matrix[higth][width])
		return false;
	int row = higth;
	int col = 0;
	while (row >= 0 && col <= width)
	{
		if (matrix[row][col] == target)
		{
			return true;
		}
		else if (matrix[row][col] > target)
		{
			row--;
		}
		else
		{
			col++;
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> nums1 = { 
									{1, 4, 7, 11, 15}, 
									{2, 5, 8, 12, 19}, 
									{3, 6, 9, 16, 22}, 
									{10, 13, 14, 17, 24}, 
									{18, 21, 23, 26, 30} 
								};
	vector<vector<int>> nums2 = {
									{1, 4, 7, 11, 15},
									{2, 5, 8, 12, 19},
									{3, 6, 9, 16, 22},
									{10, 13, 14, 17, 24},
									{18, 21, 23, 26, 30}
	};
	bool ans1 = findNumberIn2DArray2(nums1, 20);
	bool ans2 = findNumberIn2DArray2(nums2, 20);
	cout << "方法1计算出数组中有目标数字吗？（0代表没有，1代表有）：" << ans1 << endl;
	cout << "方法2计算出数组中有目标数字吗？（0代表没有，1代表有）：" << ans2 << endl;
	system("pause");
	return 0;
}