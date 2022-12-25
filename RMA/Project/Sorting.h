#pragma once
#include "STLHeader.h"
using namespace std;

// 선택 정렬
void SelectionSort();

// 삽입 정렬
void InsertionSort();

// 퀵 정렬
void QuickSort(int* arrData, int startIndex, int endIndex);

void CountSort(int* arrData, int arrSize, int minValue, int maxValue);

// 22.12.25 프로그래머스 H-Index
int HIndex(vector<int> citations);