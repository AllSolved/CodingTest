#include <crtdbg.h>
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int arr[] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };

	std::cout << "Á¤·Ä Àü : ";

	for (int i = 0; i < 15; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';

	CountSort(arr,15, 0, 9);

	std::cout << '\n';

}