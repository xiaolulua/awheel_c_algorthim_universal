/*
 * HeapSort.h
 * 堆排序
 *  Created on: 2020年2月10日
 *      Author: LuYonglei
 */

#ifndef SRC_HEAPSORT_H_
#define SRC_HEAPSORT_H_
#include <vector>
using namespace std;

template<typename T>
void siftDown(vector<T> &arr, int index, int heapSize) {
	//下滤
	T element = arr[index]; //保存父节点的元素
	int half = heapSize / 2;
	while (index < half) {
		//index必须是叶子节点
		int childIndex = 2 * index + 1; //默认是左子节点
		T childElement = arr[childIndex]; //左子节点的元素
		int rightIndex = childIndex + 1; //右子节点下标
		//若右子节点的元素大于左子节点的元素，
		if (rightIndex < heapSize && arr[rightIndex] > childElement) {
			childElement = arr[rightIndex];
			childIndex = rightIndex;
		}
		//如果大于等于子节点，就跳出循环
		if (element >= childElement)
			break;
		//如果父节点元素小于子节点元素，用子节点元素覆盖父节点元素
		arr[index] = childElement;
		index = childIndex;
	}
	arr[index] = element;
}

//1.对序列原地建堆(heapify)
//2.
//  将0号元素与末尾元素交换位置
//  堆的size-1
//  对0号元素进行下滤（siftdown）
//  重复2中的以上操作，直至size变为1
template<typename T>
void heapSort(vector<T> &arr) {
	int heapSize = arr.size();
	//原地建堆，对所有元素进行下滤
	for (int i = heapSize / 2 - 1; i >= 0; i--)
		siftDown(arr, i, heapSize);
	while (heapSize > 1) {
		//交换堆顶元素和堆尾部元素,堆大小减小1
		swap(arr[0], arr[--heapSize]);
		//对堆顶元素进行下滤
		siftDown(arr, 0, heapSize);
	}
}

#endif /* SRC_HEAPSORT_H_ */
