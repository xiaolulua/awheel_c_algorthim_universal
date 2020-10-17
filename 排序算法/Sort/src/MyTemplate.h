/*
 * MyTemplate.h
 *
 *  Created on: 2020年2月10日
 *      Author: LuYonglei
 */

#ifndef SRC_MYTEMPLATE_H_
#define SRC_MYTEMPLATE_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
void print(const vector<T> &arr) {
	//遍历vector中的元素
	for (size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

}

template<typename T>
void randed(vector<T> &arr, int size, int max) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		int randNumber = rand() % max;
		arr.push_back(randNumber);
	}
}

#endif /* SRC_MYTEMPLATE_H_ */
