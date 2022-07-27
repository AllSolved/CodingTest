#include "Sorting.h"
#include <vector>
#include <iostream>

void SelectionSort()
{
	std::vector<int> arr{ 7,5,9,0,3,1,6,2,4,8 };

	int arrSize = (int)arr.size();				// �迭�� �� ������
	int minIndex = 0;							// ���� ���� ���� ������ �ִ� �ε���
	
	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// �迭 Ž��
	for (int frontIndex = 0; frontIndex < arrSize; ++frontIndex)
	{
		minIndex = frontIndex;

		// ���� ���� ���� �ε����� ������ �� ���� ���� �߰��ϸ� ��ü
		for (int compareIndex = frontIndex + 1; compareIndex < arrSize; compareIndex++)
		{
			if (arr[minIndex] > arr[compareIndex])
				minIndex = compareIndex;
		}
		
		// �� ���� ����
		int smallestValue = arr[minIndex];		
		arr[minIndex] = arr[frontIndex];
		arr[frontIndex] = smallestValue;
	}

	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout  << arr[i] << " " ;
	}
}

void InsertionSort()
{
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

	int arrSize = 10;				// �迭�� �� ������
	int minIndex = 0;				// ���� ���� ���� ������ �ִ� �ε���

	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// ���� ������ �ι�° �ε��� ���� ������ (ù��° �����ʹ� �� ��ü�� ���ĵǾ� �ִٰ� �Ǵ��ϱ� ����) 
	for (int currentIndex = 1; currentIndex < arrSize; ++currentIndex)
	{
		// ���� �ε����� ��
		int currentValue = arr[currentIndex];

		// �ڽź��� ���� �ε����� ��ȸ�ϸ� ���� �������� �ڸ��� ã�´�.
		for (int compareIndex = currentIndex-1 ; compareIndex >= 0; --compareIndex)
		{
			int compareValue = arr[compareIndex];

			// currentValue�� ���� ������ �� �۴ٸ� ��ġ�� �ű��
			if (currentValue < compareValue)
			{
				arr[compareIndex + 1] = compareValue;
				arr[compareIndex] = currentValue;
			}
			
			// currentValue�� �� ũ�ٸ� �״�� �����.
			else
			{
				break;
			}

		}
	}

	std::cout << "���� �� : ";


	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}
}

void QuickSort()
{
	int arr[10] = { 5,7,9,0,3,1,6,2,4,8 };

	int arrSize = 10;				// �迭�� �� ������

	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';

	// �Ǻ��� ����
	int pivotValue = arr[0];
	int leftIndex = 1;
	int rightIndex = arrSize - 1;
	
	// ���ʿ����� �Ǻ����� ū �����͸� ����, �����ʿ������� �Ǻ����� ���� �����͸� �����Ѵ�.

	while (leftIndex <= rightIndex)
	{
		while (leftIndex < arrSize && (arr[leftIndex] <= pivotValue))
		{
			++leftIndex;
		}

		while (rightIndex > 0 && (arr[rightIndex] >= pivotValue))
		{
			--rightIndex;

		}

		int leftValue = arr[leftIndex];
		int rightValue = arr[rightIndex];

		// �ε����� �������� ��� �������� �����͸� pivot���� �ٲ��ش�
		if (leftIndex > rightIndex)
		{
			arr[0] = rightValue;
			arr[rightIndex] = pivotValue;
		}

		else
		{
			arr[leftIndex] = rightValue;
			arr[rightIndex] = leftValue;
		}
	}

	std::cout << "���� ���� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// ���� ���� ������ ��, ��� ������ �ݺ��Ѵ�.
}

void QuickSort(int* arrData, int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}


	// �Ǻ��� ����
	int pivotValue = arrData[startIndex];
	int leftIndex = startIndex+1;
	int rightIndex = endIndex;
	
	// ���ʿ����� �Ǻ����� ū �����͸� ����, �����ʿ������� �Ǻ����� ���� �����͸� �����Ѵ�.

	while (leftIndex <= rightIndex)
	{
		while (leftIndex <= endIndex && (arrData[leftIndex] <= pivotValue))
		{
			++leftIndex;
		}

		while (rightIndex > startIndex && (arrData[rightIndex] >= pivotValue))
		{
			--rightIndex;

		}

		int leftValue = arrData[leftIndex];
		int rightValue = arrData[rightIndex];

		// �ε����� �������� ��� �������� �����͸� pivot���� �ٲ��ش�
		if (leftIndex > rightIndex)
		{
			arrData[startIndex] = rightValue;
			arrData[rightIndex] = pivotValue;
		}

		else
		{
			arrData[leftIndex] = rightValue;
			arrData[rightIndex] = leftValue;
		}
	}

	// ���� ���� ������ ��, ��� ������ �ݺ��Ѵ�.

	QuickSort(arrData, startIndex, rightIndex -1);
	QuickSort(arrData, leftIndex+1, endIndex);

}
