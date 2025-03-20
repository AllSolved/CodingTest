#pragma once
#include "STLHeader.h"

//21. 8.13 ���� 4-1 �����¿�
void UpDownLeftRight();

//21. 8.15 ���� 4-2 �ð�
void Time();

//21. 8.16 ���� 2 �ս��� ����Ʈ
void RoyalNight();

//21. 8.17 ���� 3 ���� ����
void GameDevelopment();

//21. 8.18 ���� 2037�� ���ڸ޽���
void Message();

//21. 8.20 ���� 2037�� ���ڸ޽���
void Message();

//23. 1.13 ���α׷��ӽ� : �ְ��� ����
vector<int> BestSet(int n ,int s);

//23. 9.5 ���α׷��ӽ� : ���� ����ǥ
int Fight(int i);
int MatchList(int n, int a, int b);


//25.03.12 ���� 18808�� ��ƼĿ ���̱�
void AttachSticker();
bool TryAttachSticker(Pos startPos, vector<Pos>& stickers);
void RotateSticker(vector<Pos>& stickers);
bool PlacedSticker(vector<Pos>& sticker);

//25.03.19 ���� 15686�� ġŲ���
void SelectedChicken();
void DeliverChicken();


struct Pos
{
	int x, y;
	Pos(int otherX, int otherY) : x(otherX), y(otherY) {}
	Pos operator+(const Pos& other) const { return Pos(this->x + other.x, this->y + other.y); }

	void Rotate(int Length)
	{
		int saveX = x;
		x = y;
		y = Length - 1 - saveX;
	}

	// �Ÿ� ���
	int Distance(const Pos other)
	{
		int result = abs(x - other.x) + abs(y - other.y);
		return result;
	}
};

//25.03.20 ���� 1316�� �׷�ܾ�üĿ
void GroupWordChecker();

