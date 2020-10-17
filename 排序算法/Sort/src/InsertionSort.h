/*
 * InsertionSort.h
 * 插入排序
 *  Created on: 2020年2月11日
 *      Author: LuYonglei
 */

#ifndef SRC_INSERTIONSORT_H_
#define SRC_INSERTIONSORT_H_
#include <vector>
#include "BinarySearch.h"
using namespace std;

#if 0

template<typename T>
void insertionSort(vector<T> &arr) {
	for (size_t begin = 1; begin < arr.size(); begin++) {
		int end = begin;
		//如果end元素小于end-1元素就交换位置，否则就跳出循环
		while (end > 0 && (arr[end] < arr[end - 1])) {
			swap(arr[end], arr[end - 1]);
			end--;
		}
	}
}

#elif 0

//优化，将交换改为挪动
template<typename T>
void insertionSort(vector<T> &arr) {
	for (size_t begin = 1; begin < arr.size(); begin++) {
		int end = begin;
		T value = arr[end];
		//如果end元素小于end-1元素就用end-1元素覆盖end元素，否则就跳出循环
		while (end > 0 && (value < arr[end - 1])) {
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = value;
	}
}

#else

//对已排序部分进行二分搜索优化(在挪动的基础上再优化比较次数)
template<typename T>
void insertionSort(vector<T> &arr) {
	for (size_t begin = 1; begin < arr.size(); begin++) {
		T value = arr[begin]; //保存要插入的值
		int index = indexOfInsertion(arr, begin, value); //得到待插入位置
		//移动元素
		for (int i = begin; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
	}
}

#endif

#endif /* SRC_INSERTIONSORT_H_ */
