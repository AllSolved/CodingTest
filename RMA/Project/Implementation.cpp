#include "Implementation.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <climits>

//21. 8.13 ���� 4-1 �����¿�
void UpDownLeftRight()
{
	std::vector<char> plans;

	struct Pos
	{
		int x;
		int y;

		Pos& operator+= (const Pos& _other)
		{
			this->x += _other.x;
			this->y += _other.y;

			return *this;
		}
	};


	Pos currentPos = { 1, 1 };
	int N;
	char Dir;
	std::cin >> N;

	// �Է��� �޴� ����
	while (std::cin >> Dir)
	{
		plans.push_back(Dir);
		if (std::cin.get() == '\n')
		{
			break;
		}

	}

	for (size_t i = 0; i < plans.size(); ++i)
	{
		Pos nextPos = currentPos;

		switch (plans[i])
		{
		case 'L':
			nextPos += {0, -1};
			break;

		case 'R':
			nextPos += {0, +1};
			break;

		case 'D':
			nextPos += {+1, 0};
			break;

		case 'U':
			nextPos += {-1, 0};;
			break;

		default:
			break;
		}

		if (nextPos.x <1 || nextPos.y < 1 || nextPos.x > N || nextPos.y > N)
		{
			continue;
		}

		else
		{
			currentPos = nextPos;
		}
	}

	std::cout << currentPos.x << " " << currentPos.y;

}

void Time()
{
	int N = 0;
	int Count = 0;

	// �ð��� �Է¹ޱ�
	std::cin >> N;


	for (int h = 0; h <= N; ++h)
	{
		for (int m = 0; m < 60; ++m)
		{
			for (int s = 0; s < 60; ++s)
			{
				if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
				{
					++Count;
				}
			}
		}
	}

	std::cout << Count;
}

void RoyalNight()
{
	enum Pos { X, Y };

	int CurrentPos[2] = { 0, 0 };
	int Count = 0;

	char KnightPos[] = "a1";
	std::cin >> KnightPos;

	// ��ġ�� ���
	for (int i = 0; i < sizeof(KnightPos); ++i)
	{
		if (0 == KnightPos[i])
		{
			break;
		}

		CurrentPos[i] = KnightPos[i];
	}

	// 8���� ������ üũ
	for (int i = 0; i < 8; ++i)
	{
		int NextPos[2] = { 0,0 };
		NextPos[X] = CurrentPos[X];
		NextPos[Y] = CurrentPos[Y];

		switch (i)
		{
		case 0:
			NextPos[X] += 2;
			NextPos[Y] += 1;
			break;
		case 1:
			NextPos[X] += 2;
			NextPos[Y] -= 1;
			break;

		case 2:
			NextPos[X] -= 2;
			NextPos[Y] += 1;
			break;

		case 3:
			NextPos[X] -= 2;
			NextPos[Y] += 1;
			break;

		case 4:
			NextPos[X] += 1;
			NextPos[Y] -= 2;
			break;

		case 5:
			NextPos[X] -= 1;
			NextPos[Y] -= 2;
			break;

		case 6:
			NextPos[X] += 1;
			NextPos[Y] += 2;
			break;

		case 7:
			NextPos[X] -= 1;
			NextPos[Y] += 2;
			break;

		}

		// ���� �Ѿ��ٸ� Count�� ���� ����
		if (NextPos[X] < 'a' || NextPos[X] > 'h' ||
			NextPos[Y] < '1' || NextPos[Y] > '8')
		{
			continue;
		}

		else
		{
			++Count;
		}
	}

	std::cout << Count;

}

void GameDevelopment()
{
	enum Direction { NORTH, EAST, SOUTH, WEST };
	enum Pos { X, Y, Dir };

	int N = 0;		// ����
	int M = 0;		// ����


	// ���� ũ�� �Է�
	std::cin >> N >> M;

	// X, Y, ����
	int player[3] = { 1,1,NORTH };

	// ĳ������ ��ġ
	std::cout << '1' << ' ' << '1' << ' ' << '0' << std::endl;
	std::vector<char> Width;
	std::vector<std::vector<char>> Map(M, std::vector<char>(N, '1'));

	Map[1][1] = '0';
	Map[1][2] = '0';
	Map[2][2] = '0';

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << Map[i][j] << ' ';
		}
		std::cout << '\n';
	}


	int canMoveCheck = 0;
	int Count = 1;

	while (true)
	{
		// ���� ��ǥ�� �̹� ���� ��
		Map[1][1] = '1';

		// �� ����
		int playerNextPos[3];

		for (int i = 0; i < 3; ++i)
		{
			playerNextPos[i] = player[i];

		}

		if (player[Dir] == WEST)
		{
			player[Dir] = NORTH;
		}

		// 1�ܰ� ���� (���� ����)
		++player[Dir];

		// 2�ܰ� ���� (���⿡ ���� �ε��� Ȯ��)
		switch (player[Dir])
		{

		case NORTH:
			playerNextPos[Y] -= 1;
			playerNextPos[Dir] = NORTH;
			break;
		case EAST:
			playerNextPos[X] += 1;
			playerNextPos[Dir] = EAST;
			break;

		case SOUTH:
			playerNextPos[Y] += 1;
			playerNextPos[Dir] = SOUTH;
			break;

		case WEST:
			playerNextPos[X] -= 1;
			playerNextPos[Dir] = WEST;
			break;

		default:
			break;
		}

		// ���� ������ �� �� �ִ� ���̶��
		if (Map[playerNextPos[X]][playerNextPos[Y]] == '0')
		{
			// ���ٰ� ǥ��
			Map[playerNextPos[X]][playerNextPos[Y]] = '1';
			canMoveCheck = 0;
		}

		// �� �� ���� ���̶��
		else
		{
			// ���� ������ �̹� ���� ĭ�̶�� ȸ���� ����
			++canMoveCheck;
			player[Dir] = playerNextPos[Dir];

			// �� ���� �� ���� ��Ȳ�� ��� �������� �̵�
			if (canMoveCheck == 4)
			{
				switch (player[Dir])
				{

				case NORTH:
					playerNextPos[Y] += 1;
					break;
				case EAST:
					playerNextPos[X] -= 1;
					break;

				case SOUTH:
					playerNextPos[Y] -= 1;
					break;

				case WEST:
					playerNextPos[X] += 1;
					break;

				default:
					break;
				}

				// �̶� �̵��ؾ��� ���� �ٴ��� ���
				if (Map[playerNextPos[X]][playerNextPos[Y]] == '1')
				{
					break;
				}
			}

			// ��� ���� ��찡 �ƴ϶�� ȸ���� ����
			else
			{
				continue;
			}
		}

		// �̵�
		player[X] = playerNextPos[X];
		player[Y] = playerNextPos[Y];
		player[Dir] = playerNextPos[Dir];
		++Count;

	}

	std::cout << Count;
}

void Message()
{
	int p = 0;
	int w = 0;
	int result = 0;
	char inputString[1000];

	// �Է�
	std::cin >> p >> w;
	std::cin.ignore();
	std::cin.getline(inputString, 1001);

	std::map<char, int> allText;
	allText['A'] = 1;
	allText['B'] = 2;
	allText['C'] = 3;

	allText['D'] = 1;
	allText['E'] = 2;
	allText['F'] = 3;

	allText['G'] = 1;
	allText['J'] = 2;
	allText['I'] = 3;

	allText['J'] = 1;
	allText['K'] = 2;
	allText['L'] = 3;

	allText['M'] = 1;
	allText['N'] = 2;
	allText['O'] = 3;

	allText['P'] = 1;
	allText['Q'] = 2;
	allText['R'] = 3;
	allText['S'] = 4;


	allText['T'] = 1;
	allText['U'] = 2;
	allText['V'] = 3;

	allText['W'] = 1;
	allText['X'] = 2;
	allText['Y'] = 3;
	allText['Z'] = 4;

	allText[' '] = 1;

	std::map<char, int> sameText;

	int count = 1;
	int group = 1;

	for (int i = 0; i < 26; ++i)
	{
		char Text = 'A' + i;

		if (count <= 3)
		{
			// ������ 4��° ������ ���
			if (Text == 'R' || Text == 'Y')
			{
				count = 3;
				sameText[Text] = group;
				continue;
			}

			sameText[Text] = group;
			++count;
		}

		else
		{
			// ���� ���ڿ��� �ٲ�� ��Ȳ
			count = 2;
			++group;
			sameText[Text] = group;
		}
	}

	sameText[' '] = 0;

	int i = 0;
	while (0 != inputString[i])
	{
		// ù ���ڴ� ������.
		if (i == 0)
		{
			result += allText[inputString[i]] * p;
			char prevString = inputString[i];
			++i;
			continue;
		}

		char prevString = inputString[i - 1];

		// ���� ���ڰ� �����
		if (' ' == inputString[i])
		{
			result += (allText[inputString[i]] * p);
		}

		// �ƴ� ���
		else
		{
			// ���ð��� üũ���� �ʾƵ� �Ǵ��� Ȯ��
			if (sameText[inputString[i]] != sameText[prevString] || ' ' == sameText[prevString])
			{
				result += (allText[inputString[i]] * p);
			}

			// ���� �׷쿡 �����ִٸ�
			else
			{
				result += w + (allText[inputString[i]] * p);
			}
		}

		++i;

	}

	std::cout << result;

}

vector<int> BestSet(int n, int s)
{
	vector<int> answer;

	int q = s / n;
	int mod = s % n;

	if (q != 0)
	{
		for (int i = 0; i < n; ++i)
			answer.push_back(q);

		for (int i = answer.size() - 1; mod != 0; --i)
		{
			++answer[i];
			--mod;
		}
	}

	else
		answer.push_back(-1);

	return answer;
}

int Fight(int i)
{
	if (i % 2 == 0)
		return i / 2;
	else
		return (i / 2) + 1;
}

int MatchList(int n, int a, int b)
{
	int answer = 0;

	while (a != b)
	{
		a = Fight(a);
		b = Fight(b);
		++answer;
	}
	return answer;
}


int N, M, K, R, C, answer;
int board[41][41] = { 0 };
void AttachSticker()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i)
	{
		cin >> R >> C;

		vector<Pos> sticker;
		for (int x = 0; x < R; ++x)
		{
			for (int y = 0; y < C; ++y)
			{
				int data;
				cin >> data;
				if (data == 1)
				{
					sticker.push_back(Pos(x, y));
				}
			}
		}

		PlacedSticker(sticker);
	}

	cout << answer << "\n";
}

bool TryAttachSticker(Pos startPos, vector<Pos>& stickers)
{
	for (int i = 0; i < stickers.size(); ++i)
	{
		Pos nextPos = stickers[i] + startPos;
		if (nextPos.x < 0 || nextPos.y < 0 || nextPos.x >= N || nextPos.y >= M
			|| board[nextPos.x][nextPos.y] == 1)
		{
			return false;
		}
	}

	for (int i = 0; i < stickers.size(); ++i)
	{
		Pos nextPos = stickers[i] + startPos;
		board[nextPos.x][nextPos.y] = 1;
		++answer;
	}

	return true;
}

void RotateSticker(vector<Pos>& stickers)
{
	for (auto& pos : stickers)
	{
		pos.Rotate(R);
	}

	swap(R, C);
}

bool PlacedSticker(vector<Pos>& sticker)
{
	for (int k = 0; k < 4; ++k)
	{
		// �̺κ� �ٽ� �����ϱ�
		for (int i = 0; i <= N - R; ++i)
		{
			for (int j = 0; j <= M - C; ++j)
			{
				if (TryAttachSticker(Pos(i, j), sticker))
				{
					return true;
				}
			}
		}
		RotateSticker(sticker);
	}
	return false;
}

vector<Pos> vHouse;
vector<Pos> vChicken;
vector<vector<int>> vAllDistance;   // ������ ġŲ�������� �Ÿ�
vector<int> vCombi;                 // ġŲ���� ����
int answer = INT_MAX;
int N, M;
void SelectedChicken()
{
	vCombi.resize(vChicken.size(), 1);

	// ����� ġŲ���� ��Ƴ��� ġŲ���� 0,1�� ����
	fill(vCombi.begin(), vCombi.begin() + (vChicken.size() - M), 0);


	// ���� Ž��
	do
	{
		// ���õ� ġŲ�� �ε��� ����
		vector<int> selected;
		for (int i = 0; i < vChicken.size(); ++i)
		{
			if (vCombi[i] == 1) selected.push_back(i);
		}

		// ���õ� ġŲ������ ������ ġŲ �Ÿ� ���
		int totalDistance = 0;
		for (int i = 0; i < vHouse.size(); ++i)
		{
			int minDist = INT_MAX;
			for (int idx : selected)
			{
				minDist = min(minDist, vAllDistance[i][idx]);
			}
			totalDistance += minDist;
		}

		// �ּ� ���� ġŲ �Ÿ� ����
		answer = min(answer, totalDistance);

	}
	while (next_permutation(vCombi.begin(), vCombi.end()));
}

void DeliverChicken()
{

	cin >> N >> M;

	// ���� ġŲ���� ��ǥ�� ����
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int data = 0;
			cin >> data;
			if (data == 1) { vHouse.emplace_back(i, j); }
			else if (data == 2) { vChicken.emplace_back(i, j); }
		}
	}

	// ���� ������ ġŲ�������� �Ÿ��� ���� ���
	vAllDistance.resize(vHouse.size(), vector<int>(vChicken.size()));
	for (int i = 0; i < vHouse.size(); ++i)
	{
		for (int j = 0; j < vChicken.size(); ++j)
		{
			vAllDistance[i][j] = vHouse[i].Distance(vChicken[j]);
		}
	}

	SelectedChicken();

	cout << answer << '\n';
}

void GroupWordChecker()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, answer;
	cin >> N;

	answer = 0;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		bool isGroup = true;
		string checked = "";
		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] == checked.back()) { continue; }
			if (checked.find(str[j]) != string::npos)
			{
				isGroup = false;
				break;
			}
			checked += str[j];
		}
		answer = isGroup ? answer + 1 : answer;
	}

	cout << answer << '\n';
}
