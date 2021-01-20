/*
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ
�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
���磺
���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3
*/
//niejiaming 20210120

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

//�����㷨�ӱ���
//ʱ�临�Ӷ�o(nlogn)
//�ռ临�Ӷ�o(1)
int findRepeatNumber1(vector<int>& nums) {
	int size = nums.size();
	if (size < 2 || size>100000)
		return INT_MAX;
	sort(nums.begin(), nums.end());
	for (int i = 1; i < size - 1; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			return nums[i];
		}
	}
	return INT_MAX;
}

//��ϣ������㷨
//ʱ�临�Ӷ�o(n)
//�ռ临�Ӷ�o(n)
int findRepeatNumber2(vector<int>& nums) {
	unordered_set<int> store;
	for (auto& n:nums)
	{
		if (store.find(n) != store.end())
		{
			return n;
		}
		store.insert(n);
	}
	return INT_MAX;
}

//ԭ�ع�ϣ
//ʱ�临�Ӷ�o(n)
//�ռ临�Ӷ�o(1)
int findRepeatNumber3(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] != i)     //��ǰԪ�ز������±�
		{
			if (nums[i] == nums[nums[i]])    
				return nums[i];
			else
				swap(nums[i], nums[nums[i]]);
		}
	}
	return -1;
}

int main()
{
	vector<int> nums1 = { 2, 3, 1, 0, 2, 5, 3 };
	vector<int> nums2 = { 2, 3, 1, 0, 2, 5, 3 };
	vector<int> nums3 = { 2, 3, 1, 0, 2, 5, 3 };
	int ans1 = findRepeatNumber1(nums1);
	int ans2 = findRepeatNumber2(nums2);
	int ans3 = findRepeatNumber3(nums3);
	cout << "����1��������ظ������ǣ�" << ans1 << endl;
	cout << "����2��������ظ������ǣ�" << ans2 << endl;
	cout << "����3��������ظ������ǣ�" << ans3 << endl;
	system("pause");
	return 0;
}