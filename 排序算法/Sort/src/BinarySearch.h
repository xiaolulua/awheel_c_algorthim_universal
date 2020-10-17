/*
 * BinarySearch.h
 * 二分查找
 * 数组取值范围尽量保证左闭右开，这样end-begin=size,编码比较方便
 *  Created on: 2020年2月11日
 *      Author: LuYonglei
 */

#ifndef SRC_BINARYSEARCH_H_
#define SRC_BINARYSEARCH_H_
#include <vector>
using namespace std;
#define ELEMENT_NOT_FIND -1

//查找value在有序数组arr中的位置
template<typename T>
int indexOf(const vector<T> &arr, int size, T value) {
	int arraySize = arr.size();
	if (arraySize == 0 || size <= 0 || arraySize < size)
		return ELEMENT_NOT_FIND;
	int begin = 0; //最前面元素的索引
	int end = size; //最后一个元素索引的下一个
	while (begin < end) {
		int middle = (begin + end) / 2;
		if (value < arr[middle]) {
			end = middle;
		} else if (value > arr[middle]) {
			begin = middle + 1;
		} else {
			//value==arr[mid]
			return middle;
		}
	}
	return ELEMENT_NOT_FIND;
}

//查找value在有序数组arr中待插入的位置
//有序数组中第一个大于value的位置
template<typename T>
int indexOfInsertion(const vector<T> &arr, int size, T value) {
	//为了保证二分查找后再插入的稳定性
	int arraySize = arr.size();
	if (arraySize == 0 || size <= 0 || arraySize < size)
		return ELEMENT_NOT_FIND;
	int begin = 0; //最前面元素的索引
	int end = size; //最后一个元素索引的下一个
	while (begin < end) {
		int middle = (begin + end) / 2;
		if (value < arr[middle]) {
			end = middle;
		} else {
			//value >= arr[middle]
			begin = middle + 1;
		}
	}
	//此时begin==end
	return begin;
}

#endif /* SRC_BINARYSEARCH_H_ */
