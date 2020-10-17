/*
 * SelectionSort.h
 * 选择排序(选择排序交换次数远远小于冒泡排序，所以平均性能比冒泡排序要好)
 *  Created on: 2020年2月10日
 *      Author: LuYonglei
 */

#ifndef SRC_SELECTIONSORT_H_
#define SRC_SELECTIONSORT_H_
#include <vector>
using namespace std;

#if 1

template<typename T>
void selectionSort(vector<T> &arr) {
	//从序列中选择最大的元素，与末尾元素交换位置
	for (int end = arr.size() - 1; end > 0; end--) {
		int maxIndex = 0; //最大元素的索引
		for (int begin = 0; begin <= end; begin++) {
			if (arr[begin] >= arr[maxIndex])
				maxIndex = begin; //保留最大元素位置的索引(要保证排序算法的稳定性，需要加=)
		}
		swap(arr[maxIndex], arr[end]); //选择最大的元素，与末尾元素交换位置
	}
}
#else
//利用堆来选择最值，配合排序算法可以降低算法复杂度，所以衍生出了堆排序
#endif

#endif /* SRC_SELECTIONSORT_H_ */
