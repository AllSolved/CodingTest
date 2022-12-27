#include "BFS.h"

void BFS()
{
	//1. Graph ����
	struct Node
	{
		int value;
		std::vector<Node*> link;
		bool check;
	};

	std::vector<Node*> Graph;
	std::queue<Node*> Visit;

	for (int i = 0; i < 8; ++i)
	{
		Node* pNode = new Node;
		pNode->value = i;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//0�� ���
	Graph[0]->link.push_back(Graph[1]);
	Graph[0]->link.push_back(Graph[2]);
	Graph[0]->link.push_back(Graph[7]);


	//1�� ���
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[6]);

	//2�� ���
	Graph[2]->link.push_back(Graph[0]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//3�� ���
	Graph[3]->link.push_back(Graph[2]);
	Graph[3]->link.push_back(Graph[4]);

	//4�� ���
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[3]);

	//5�� ���
	Graph[5]->link.push_back(Graph[6]);

	//6�� ���
	Graph[6]->link.push_back(Graph[1]);
	Graph[6]->link.push_back(Graph[5]);
	Graph[6]->link.push_back(Graph[7]);

	//7�� ���
	Graph[7]->link.push_back(Graph[0]);
	Graph[7]->link.push_back(Graph[6]);

	// BFS ���� (�Ÿ��� ���� ����� ������ Ž��)

	int i = 0;
	while (true)
	{
		// �ѹ��� �湮���� ���� ����� ���
		if (!Graph[i]->check)
		{
			// �湮 ó��
			Visit.push(Graph[i]);
			Graph[i]->check = true;
			std::cout << i << "->";
		}


		// �湮 �ߴ� �����
		else
		{
			// ���� ó���� �ִ� ��带 ���� ��
			Node& pNode = *Visit.front();
			Visit.pop();

			// ���� ��� �� �湮���� ���� ��带 ��� ť�� ������ �� �湮ó����.
			for (size_t j = 0; j < pNode.link.size(); ++j)
			{
				// ���� üũ�ϰ� �ִ� ����� ��尡 �湮�� �� ���� �����
				if (!pNode.link[j]->check)
				{
					// Queue�� Push �� �湮 ó����.
					Visit.push(pNode.link[j]);
					pNode.link[j]->check= true;
					std::cout << pNode.link[j]->value << "->";
				}
			}

			// Queue�� ���� ó�� ��带 ���� Ž���� ���� �ٲ���.
			if (!Visit.empty())
			{
				i = Visit.front()->value;
			}

			else
			{
				break;
			}
		}

		
	}

	std::vector<Node*>::iterator iter = Graph.begin();
	std::vector<Node*>::iterator iterEnd = Graph.end();

	// �޸� ����
	for (; iter != iterEnd; ++iter)
	{
		delete (*iter);
	}

	// ���Ϳ� �Ҵ�� �޸� ����

	Graph.clear();
	std::cout << '\n';

}

void EscapeTheMaze()
{
	enum Pos {X,Y};
	enum Direction {DOWN,UP,RIGHT,LEFT};
	int N, M;
	int result = 0;
	std::cin >> N >> M;

	int Maze[201][201];
	std::queue<std::pair<int, int>> Check;


	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			Maze[x][y] = (int)std::cin.get() - '0';
			Check.push({x,y});
		}
		std::cin.ignore();
	}

	int DirX[4] = { 0,0,1,-1 };
	int DirY[4] = { 1,-1,0,0 };

	// Queue�� �� ����
	while (!Check.empty())
	{
		// �湮
		int currentPos[2] = { Check.front().first , Check.front().second};
		Check.pop();
		
		// 4������ Ž��
		for (int i = 0; i < 4; ++i)
		{
			int checkPos[2] = { currentPos[X] + DirX[i],currentPos[Y] + DirX[i] };

			// üũ�ؾ� �� ��ġ�� ���� �Ѿ�� ��� ����
			if (checkPos[X] <0 || checkPos[X] >= N ||
				checkPos[Y] < 0 || checkPos[Y] >= M)
			{
				continue;
			}

			// ���� ��� ����
			if (Maze[checkPos[X]][checkPos[Y]] == 0)
			{
				continue;
			}

			// �ش� ��尡 ó�� �湮�ϴ� ����� ��츸 �ִܰŸ��� ����
			if (Maze[checkPos[X]][checkPos[Y]] == 1)
			{
				Maze[checkPos[X]][checkPos[Y]] = Maze[currentPos[X]][currentPos[Y]] + 1;
				Check.push({ checkPos[X] , checkPos[Y] });
				++result;
			}
		}
	}
	
	std::cout << result;
}


void JumpJump()
{
	struct CStone
	{
		bool bCanVisit;
		int Number;
	};

	std::vector<CStone> vecStoneBridge;

	// ���ٸ��� ����
	int StoneCount = 0;
	std::cin >> StoneCount;

	// ���ٸ��� ������ŭ �� ����.
	for (int i = 0; i < StoneCount; ++i)
	{
		CStone stone;
		stone.bCanVisit = false;
		std::cin >> stone.Number;
		vecStoneBridge.push_back(stone);
	}

	// ������ �Է¹ޱ�.
	int StartPoint = 0;
	std::cin >> StartPoint;

	// ���� ��ġ 
	StartPoint -= 1;		// �ε����� ���߱� ����
	int Result = 0;

	std::queue<int> q;
	vecStoneBridge[StartPoint].bCanVisit = true;
	q.push(StartPoint);
	++Result;

	// �� �ǳʱ�
	while (!q.empty())
	{
		// ���� �̵��� ��ġ(���� ������� Ž��)
		int currentIndex = q.front();
		int distance = vecStoneBridge[currentIndex].Number;
		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			distance *= -1;
			int nextIndex = currentIndex + distance;

			// ���� �湮���� ���� ���̰� ���� ���� �����ϴ� ���̶��
			if (-1 < nextIndex && nextIndex < StoneCount && !vecStoneBridge[nextIndex].bCanVisit)
			{
				vecStoneBridge[nextIndex].bCanVisit = true;
				q.push(nextIndex);
				++Result;
			}
		}

	
	}

	std::cout << Result << std::endl;
}


int ShortestDistanceInGameMap(vector<vector<int>> maps)
{
	int answer = -1;

	int mapX = (int)maps[0].size();
	int mapY = (int)maps.size();

	int dirX[] = { 1,-1,0,0 };
	int dirY[] = { 0,0,1,-1 };
	int visit[101][101] = { false };
	int bfsMap[101][101] = { 0 };

	// �� �� ���� ���� �̹� �湮�� ó���� �Ѵ�.
	for (int y = 0; y < mapY; ++y)
	{
		for (int x = 0; x < mapX; ++x)
		{
			visit[y][x] = maps[y][x] == 0 ? true : false;
		}
	}

	queue<Pos> q;
	Pos startPos;
	startPos.x = 0;
	startPos.y = 0;

	q.push(startPos);
	visit[0][0] = true;
	bfsMap[0][0] = 1;

	while (!q.empty())
	{
		Pos currentPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			Pos nextPos;
			nextPos.x = currentPos.x + dirX[i];
			nextPos.y = currentPos.y + dirY[i];

			// �湮�� �� ���� ���� ���
			if (nextPos.x < 0 || nextPos.y < 0 ||
				nextPos.x >= mapX || nextPos.y >= mapY)
			{
				continue;
			}

			if (visit[nextPos.y][nextPos.x])
			{
				continue;
			}

			visit[nextPos.y][nextPos.x] = true;
			q.push(nextPos);
			bfsMap[nextPos.y][nextPos.x] = bfsMap[currentPos.y][currentPos.x] + 1;
		}
	}

	if (visit[mapY - 1][mapX - 1])
	{
		answer = bfsMap[mapY - 1][mapX - 1];
	}

	return answer;
}

bool CanChange(string src, string dest)
{
	bool result = false;
	int count = 0;

	for (int i = 0; i < dest.length(); ++i)
	{
		if (src[i] != dest[i])
		{
			++count;
		}
	}

	result = count == 1 ? true : false;
	return result;
}

int ChangeWords(string begin, string target, vector<string> words)
{
	queue<pair<string, int>> q;
	pair<string, int> p(begin, 0);

	q.push(p);
	bool visit[51] = { false };

	while (!q.empty())
	{
		pair<string, int> currentWord = q.front();
		q.pop();

		for (int i = 0; i < words.size(); ++i)
		{
			if (visit[i] == true)
			{
				continue;
			}

			if (CanChange(currentWord.first, words[i]))
			{
				if (words[i] == target)
				{
					return currentWord.second + 1;
				}

				visit[i] = true;
				q.push(pair<string, int>(words[i], currentWord.second + 1));
			}
		}
	}

	return 0;
}

int Y, X;

int dirX[] = { 0,0,1,-1 };
int dirY[] = { -1,1,0,0 };

int LaboratoryMap[8][8] = { 0 };

int answer = 0;
int tempMap[8][8] = { 0 };


void Virus()
{
	queue<Pos> qVirus;
	int mapCopy[8][8] = {0};
	copy(&tempMap[0][0], &tempMap[0][0] + (Y * X), &mapCopy[0][0]);

	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (mapCopy[y][x] == 2)
			{
				Pos virusPos;
				virusPos.x = x;
				virusPos.y = y;

				qVirus.push(virusPos);
			}
		}
	}

	while (!qVirus.empty())
	{
		Pos pos = qVirus.front();
		qVirus.pop();

		// 4������ Ž���Ͽ� ���̷����� �۶߸�
		for (int i = 0; i < 4; ++i)
		{
			Pos nextPos;
			nextPos.x = pos.x + dirX[i];
			nextPos.y = pos.y + dirY[i];

			// ������ ��� ���
			if ((nextPos.x >= 0 && nextPos.y >= 0 &&
				nextPos.x < X && nextPos.y < Y) && 
				mapCopy[nextPos.y][nextPos.x] == 0)
			{
				mapCopy[nextPos.y][nextPos.x] = 2;
				qVirus.push(nextPos);
			}
		}
	}

	// 0�� ������ ����.
	int result = 0;
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (mapCopy[y][x] == 0)
			{
				++result;
			}
		}
	}

	answer = max(answer,result);
}

void Virus(int mapCopy[][8])
{
	queue<Pos> qVirus;

	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (mapCopy[y][x] == 2)
			{
				Pos virusPos;
				virusPos.x = x;
				virusPos.y = y;

				qVirus.push(virusPos);
			}
		}
	}

	while (!qVirus.empty())
	{
		Pos pos = qVirus.front();
		qVirus.pop();

		// 4������ Ž���Ͽ� ���̷����� �۶߸�
		for (int i = 0; i < 4; ++i)
		{
			Pos nextPos;
			nextPos.x = pos.x + dirX[i];
			nextPos.y = pos.y + dirY[i];

			// ������ ��� ���
			if (nextPos.x >= 0 && nextPos.y >= 0 &&
				nextPos.x < X && nextPos.y < Y)
			{
				if (mapCopy[nextPos.y][nextPos.x] == 0)
				{
					mapCopy[nextPos.y][nextPos.x] = 2;
					qVirus.push(nextPos);
				}
			}
		}
	}

	// 0�� ������ ����.
	int result = 0;
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			int value = mapCopy[y][x];
			if (value  == 0)
			{
				++result;
			}
		}
	}

	answer = max(answer, result);
}

void MakeWall(int count)
{
	if (count == 3)
	{
		Virus();
		return;
	}

	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (tempMap[y][x] == 0)
			{
				tempMap[y][x] = 1;
				MakeWall(count + 1);
				tempMap[y][x] = 0;
			}
		}
	}
}

void Laboratory()
{
	// Input
	cin >> Y >> X;

	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			cin >> LaboratoryMap[y][x];
		}
	}

	// �� ����� BFS
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			// ��ĭ �߰����� ���
			if (LaboratoryMap[y][x] == 0)
			{
				// �� ������ ������ ��,
				copy(&LaboratoryMap[0][0], &LaboratoryMap[0][0] +(Y*X), &tempMap[0][0]);
				tempMap[y][x] = 1;
				MakeWall(1);
				tempMap[y][x] = 0;
			}
		}
	}


	cout << answer;
}
