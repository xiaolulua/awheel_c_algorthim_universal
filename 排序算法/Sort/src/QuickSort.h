/*
 * QuickSort.h
 * 快速排序(将每一个元素转换为轴点元素)
 *  Created on: 2020年2月12日
 *      Author: LuYonglei
 */

#ifndef SRC_QUICKSORT_H_
#define SRC_QUICKSORT_H_
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
int compare(const T &left, const T &right) {
	//比较两个元素大小
	//left > right    return  1
	//left = right    return  0
	//left < right    return -1
	return left > right ? 1 : (left == right ? 0 : -1);
}

template<typename T>
int pivotIndex(vector<T> &arr, int begin, int end) {
	//构造出arr中的轴点元素并返回索引位置
	//为保证尽可能不出现最坏情况，随机选择一个begin-end范围内的元素作为轴点元素
	srand(time(0));
	int randIndex = rand() % (end - begin);
	//把随机选择的轴点位置和begin位置交换元素
	swap(arr[begin], arr[begin + randIndex]);
	//备份begin位置的元素
	T pivotValue = arr[begin];
	//end指向最后一个元素
	end--;
	//当begin<end时进行扫描
	while (begin < end) {
		while (begin < end) {
			//先从右往左扫描
			if (-1 == compare(pivotValue, arr[end])) {
				//如果轴点元素小于end位置的元素
				end--;
			} else {
				//轴点元素大于等于end位置元素
				arr[begin] = arr[end];
				begin++;
				break;
			}
		}
		while (begin < end) {
			//从左往右扫描
			if (compare(pivotValue, arr[begin]) == 1) {
				//如果轴点元素大于begin位置的元素
				begin++;
			} else {
				//如果轴点元素小于等于begin位置的元素
				arr[end] = arr[begin];
				end--;
				break;
			}
		}
	}
	//将轴点位置用value覆盖
	arr[begin] = pivotValue;
	//返回轴点元素位置
	return begin;
}

#if 0
//递归实现
template<typename T>
void sort(vector<T> &arr, int begin, int end) {
	//对[begin,end)范围内的元素进行快速排序
	if ((end - begin) < 2)
		return;
	int pivot = pivotIndex(arr, begin, end);
	sort(arr, begin, pivot);
	sort(arr, pivot + 1, end);
}

#else
//迭代实现
typedef struct _sortPair {
	int begin;
	int end;
} SORT_PAIR;

template<typename T>
void sort(vector<T> &arr, int begin, int end) {
	if ((end - begin) < 2)//元素个数小于2,直接退出
		return;
	stack<SORT_PAIR> s;
	s.push(SORT_PAIR { begin, end });
	int sBegin=0;
	int sEnd=0;
	int pivot=0;
	while (s.size() != 0) {
		sBegin = s.top().begin;
		sEnd = s.top().end;
		pivot = pivotIndex(arr, sBegin, sEnd);//确定轴点元素位置
		s.pop();//弹出栈顶元素
		if ((pivot - sBegin) >= 2) {//元素个数大于等于2,才需要进行排序
			s.push(SORT_PAIR { sBegin, pivot });
		}
		if ((sEnd - pivot - 1 >= 2)) {//元素个数大于等于2才需要进行排序
			s.push(SORT_PAIR { pivot + 1, sEnd });
		}
	}
}

#endif

template<typename T>
void quickSort(vector<T> &arr) {
	sort(arr, 0, arr.size());
}

#endif /* SRC_QUICKSORT_H_ */
