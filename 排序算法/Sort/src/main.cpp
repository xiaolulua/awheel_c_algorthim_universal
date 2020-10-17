/*
 * main.cpp
 *
 *  Created on: 2020年2月10日
 *      Author: LuYonglei
 */

#include <iostream>
#include <vector>
#include "MyTemplate.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main(int argc, char **argv) {
	vector<int> arr;
	randed(arr,15,100);
	print(arr);
//	bubbleSort(arr);
//	selectionSort(arr);
//	heapSort(arr);
//	insertionSort(arr);
//	mergeSort(arr);
	quickSort(arr);
	print(arr);

}

