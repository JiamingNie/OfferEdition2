/*
排序算法：
1、快速排序
2、归并排序
*/

#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>& nums)
{
	for (auto&n : nums)
	{
		cout << n << " ";
	}
	cout << endl;
}

//二叉树的先序遍历
void qSort(vector<int>& nums,int left,int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && nums[j] >= nums[left])	
			j--;
		while (i < j && nums[i] <= nums[left])	
			i++;
		swap(nums[i], nums[j]);
	}
	swap(nums[left], nums[i]);
	qSort(nums, left, i - 1);
	qSort(nums, i + 1, right);
}

//快速排序
void quickSort(vector<int>& nums)
{
	qSort(nums, 0, nums.size() - 1);
	printVector(nums);
}

void merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> tmp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int index = 0;
	while (i <= mid && j <= right) 
	{
		if (nums[i]<nums[j])
		{
			tmp[index] = nums[i];
			i++;
		}
		else 
		{
			tmp[index] = nums[j];
			j++;
		}
		index++;
	}

	while (i <= mid)
	{
		tmp[index] = nums[i];
		i++;
		index++;
	}

	while (j <= right)
	{
		tmp[index] = nums[j];
		j++;
		index++;
	}
	for (int i = 0; i < index; i++)
	{
		nums[i + left] = tmp[i];
	}
}

//二叉树的后序遍历
void mSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mSort(nums,left,mid);
		mSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

//归并排序
void mergeSort(vector<int>& nums)
{
	mSort(nums, 0, nums.size() - 1);
	printVector(nums);
}

//构造大顶堆
void heapInert(vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		int currentIndex = i;
		int fatherIndex = (i - 1) / 2;
		while (nums[currentIndex] > nums[fatherIndex])
		{
			swap(nums[currentIndex], nums[fatherIndex]);
			currentIndex = fatherIndex;
			fatherIndex = (currentIndex - 1) / 2;
		}
	}
}
//调整剩余元素
void heapify(vector<int>& nums, int index, int size)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	while (left < size)
	{
		int largestIndex;
		if (right < size&&nums[left] < nums[right])
		{
			largestIndex = right;
		}
		else
		{
			largestIndex = left;
		}

		if (nums[index] > nums[largestIndex])
			break;
		swap(nums[largestIndex], nums[index]);
		index = largestIndex;
		left = 2 * index + 1;
		right = 2 * index + 2;
	}
}

//https://guguoyu.blog.csdn.net/article/details/81283998
void heapSort(vector<int>& nums)
{
	heapInert(nums);
	int size = nums.size();
	while (size > 1)
	{
		swap(nums[0], nums[size - 1]);
		size--;
		heapify(nums, 0, size);
	}

	printVector(nums);
}

int main()
{
	vector<int> nums = { 3,2,0,5,6,7,5,8,2,1 };
	printVector(nums);

	//quickSort(nums);
	//mergeSort(nums);
	heapSort(nums);
	return 0;
}