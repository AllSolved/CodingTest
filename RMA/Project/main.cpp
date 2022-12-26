#include <crtdbg.h>
#include "STLHeader.h"
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"
#include "Search.h"
#include "etc.h"
#include "CodingTest.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<int> data = {0,2,4,6,8,10,12,14,16,18};
	
	BinarySearch(data,4);
}