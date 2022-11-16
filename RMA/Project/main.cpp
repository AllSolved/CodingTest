#include <crtdbg.h>
#include "STLHeader.h"
#include "GreedyAlgorithm.h"
#include "Implementation.h"
#include "DFS.h"
#include "BFS.h"
#include "Sorting.h"
#include "CodingTest.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<vector<double>> objectBallPosList;

	vector<double> ballPos = { 5.0f,0.0f };
	objectBallPosList.push_back(ballPos);
	ballPos = { 0.0f,3.0f };
	objectBallPosList.push_back(ballPos);
	ballPos = { 1.0f,1.0f };

	CircleDetect (objectBallPosList, ballPos);

}