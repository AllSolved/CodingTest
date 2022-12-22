#include <crtdbg.h>
#include "STLHeader.h"
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"
#include "etc.h"
#include "CodingTest.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<vector<int>> costs;
	std::vector<int> v1 = {0,1,1};
	std::vector<int> v2 = { 0,2,2 };
	std::vector<int> v3 = { 1,2,5 };
	std::vector<int> v4 = { 1,3,1 };
	std::vector<int> v5 = { 2,3,8 };


	costs.push_back(v1);
	costs.push_back(v2);
	costs.push_back(v3);
	costs.push_back(v4);
	costs.push_back(v5);

	LinkIsland(4,costs);
}