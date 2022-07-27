#include <crtdbg.h>
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int arr[] = { 5,7,9,0,3,1,6,2,4,8 };

	std::cout << "정렬 전 : ";

	for (int i = 0; i < 10; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';

	QuickSort(arr, 0, 9);

	std::cout << "정렬 후 : ";

	for (int i = 0; i < 10; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}