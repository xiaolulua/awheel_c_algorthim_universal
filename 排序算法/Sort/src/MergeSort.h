/*
 * MergeSort.h
 * 归并排序
 *  Created on: 2020年2月12日
 *      Author: LuYonglei
 */

#ifndef SRC_MERGESORT_H_
#define SRC_MERGESORT_H_
#include <vector>
using namespace std;

#if 1
//递归实现归并排序

template<typename T>
void merge(vector<T> &arr, vector<T> &leftArray, int begin, int middle,
		int end) {
	//将[begin,middle)和[middle,end)范围内的有序元素合并为一个有序序列
	//左半部分
	int leftIndex = 0;
	int leftEnd = middle - begin;
	//右半部分
	int rightIndex = middle;
	int rightEnd = end;
	//先把[begin，middle)的元素备份出来
	for (int i = 0; i < leftEnd; i++)
		leftArray[i] = arr[begin + i];
	int arrIndex = begin;	//指向被排序数组的索引
	//这里只需要考虑右边先结束的情况,也就是说左边结束了就不用再做其他操作
	//如果左边还没结束
	while (leftIndex < leftEnd) {
		if (rightIndex < rightEnd && arr[rightIndex] < leftArray[leftIndex]) {
			//右边没有结束且右边元素小于左边元素
			//拷贝右边数组到arr
			arr[arrIndex] = arr[rightIndex];
			arrIndex++;
			rightIndex++;

		} else {
			//右边元素大于左边元素或者右边已经结束
			//拷贝左边数组到arr
			arr[arrIndex] = leftArray[leftIndex];
			arrIndex++;
			leftIndex++;
		}
	}
}

template<typename T>
void sort(vector<T> &arr, vector<T> &leftArray, int begin, int end) {
//对数组内[begin,end)的元素进行归并排序
	if ((end - begin) < 2)
		return;
	int middle = (begin + end) / 2;
	sort(arr, leftArray, begin, middle);
	sort(arr, leftArray, middle, end);
	merge(arr, leftArray, begin, middle, end);
}

template<typename T>
void mergeSort(vector<T> &arr) {
//归并排序算法
	vector<T> *leftArray = new vector<T>(arr.size() / 2);
	sort(arr, *leftArray, 0, arr.size());
	delete leftArray;
}

#endif

#endif /* SRC_MERGESORT_H_ */
