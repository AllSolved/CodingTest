#include <iostream>
#include "Sorting.h"
using namespace std;

void SelectionSort()
{
	int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
	int arrSize = 10;

	for (int i = 0; i < arrSize; i++)
	{
		int minIndex = i; // ���� ���� ������ �ε���

		for (int j = i + 1; j < arrSize; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}

	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
}

void InsertionSort()
{
	int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
	int arrSize = 10;

	for (int i = 1; i < arrSize; i++)
	{
		for (int j = i; j > 0; j--) // ��
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
}