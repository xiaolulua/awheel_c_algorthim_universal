/*
 * main.c
 *
 *  Created on: 2020年3月12日
 *      Author: LuYonglei
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void getNext(char const *pattern, int *next) {
	//获得模式串pattern的next数组
	next[0] = -1;
	int i = 0; //next数组索引下标
	int n = -1;
	int imax = strlen(pattern) - 1; //下标最大值
	while (i < imax) {
		if (n < 0 || pattern[i] == pattern[n]) {
			i++;
			n++;
			if (pattern[i] == pattern[n]) { //以下属于优化操作
				next[i] = next[n];
			} else {
				next[i] = n;
			}
		} else {
			n = next[n];
		}
	}
}

int search(char const *text, char const *pattern) {
	assert(text!=NULL);
	assert(pattern!=NULL);
	int tlen = strlen(text); //字符串长度
	int plen = strlen(pattern); //模式串长度
	if (plen == 0 || tlen == 0)
		return -1;

	int tmax = tlen - plen; //字符串索引最大值
	int pi = 0; //模式串索引下标
	int ti = 0; //字符串索引下标
	int *next = (int*) malloc(sizeof(int) * plen); //next数组,next[0]=-1

	//获得next表
	getNext(pattern, next);

	while (pi < plen && ti - pi < tmax) { //当模式串索引下标不越界,字符串下标小于最大可匹配成功下标时
		if (pi < 0 || text[ti] == pattern[pi]) { //若失配的是模式串0号位置或者匹配成功,移动字符串和模式串下标
			ti++;
			pi++;
		} else {
			pi = next[pi]; //失配时,快速移动模式串来进行匹配
		}
	}
	free(next); //释放next内存
	return (pi == plen ? (ti - pi) : -1); //找到匹配位置,返回匹配位置;未找到匹配位置,返回-1
}

int main(int argc, char **argv) {
	char *text = "1cb212366";
	char *pattern = "23";
	printf("%d", search(text, pattern));
}

