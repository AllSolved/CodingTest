#pragma once
#include "STLHeader.h"

//21. 8.13 예제 4-1 상하좌우
void UpDownLeftRight();

//21. 8.15 예제 4-2 시각
void Time();

//21. 8.16 실전 2 왕실의 나이트
void RoyalNight();

//21. 8.17 실전 3 게임 개발
void GameDevelopment();

//21. 8.18 백준 2037번 문자메시지
void Message();

//21. 8.20 백준 2037번 문자메시지
void Message();

//23. 1.13 프로그래머스 : 최고의 집합
vector<int> BestSet(int n ,int s);

//23. 9.5 프로그래머스 : 예상 대진표
int Fight(int i);
int MatchList(int n, int a, int b);


//25.03.12 백준 18808번 스티커 붙이기
void AttachSticker();
bool TryAttachSticker(Pos startPos, vector<Pos>& stickers);
void RotateSticker(vector<Pos>& stickers);
bool PlacedSticker(vector<Pos>& sticker);

//25.03.19 백준 15686번 치킨배달
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

	// 거리 계산
	int Distance(const Pos other)
	{
		int result = abs(x - other.x) + abs(y - other.y);
		return result;
	}
};

//25.03.20 백준 1316번 그룹단어체커
void GroupWordChecker();

