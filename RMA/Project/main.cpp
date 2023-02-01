#include <crtdbg.h>
#include "STLHeader.h"
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"
#include "Search.h"
#include "Math.h"
#include "DataStructure.h"
#include "DP.h"
#include "etc.h"
#include "CodingTest.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::vector<string> v;
	v.push_back("I -45");
	v.push_back("I 653");
	v.push_back("D 1");
	v.push_back("I -642");
	v.push_back("I 45");
	v.push_back("D 1");
	v.push_back("D -1");
	v.push_back("I 333");

	DoublePriorityQueue(v);
}