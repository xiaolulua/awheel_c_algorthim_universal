/*
 * BubbleSort.h
 * 冒泡排序
 *  Created on: 2020年2月10日
 *      Author: LuYonglei
 */

#ifndef SRC_BUBBLESORT_H_
#define SRC_BUBBLESORT_H_
#include <vector>
using namespace std;

#if 0

template<typename T>
void bubbleSort(vector<T> &arr) {
	//冒泡排序，从小到大(数组存在提前有序的情况下可以优化,但此情况出现概率较低)
	for (int end = arr.size() - 1; end > 0; end--) {
		//外层循环控制遍历次数
		bool sorted = true; //优化添加的标记
		for (int begin = 1; begin <= end; begin++) {
			//内层循环控制比较和交换次数
			if (arr[begin] < arr[begin - 1]) {
				swap(arr[begin], arr[begin - 1]);
				sorted = false;
			}
		}
		//若已经有序，则提前退出排序
		if (sorted)
			break;
	}
}
#else

template<typename T>
void bubbleSort(vector<T> &arr) {
	//冒泡排序，从小到大(如果序列尾部局部有序，可以记录最后一次交换位置，减少比较次数)
	for (int end = arr.size() - 1; end > 0; end--) {
		//外层循环控制遍历次数
		int sortedIndex = 0; //优化添加的索引(此索引不可以随便设置，为数据完全有序做准备,若完全有序会提前退出)
		for (int begin = 1; begin <= end; begin++) {
			//内层循环控制比较和交换次数
			if (arr[begin] < arr[begin - 1]) {
				swap(arr[begin], arr[begin - 1]);
				sortedIndex = begin;
			}
		}
		//记录最后一次交换位置，减少比较次数
		end = sortedIndex;
	}
}

#endif

#endif /* SRC_BUBBLESORT_H_ */
