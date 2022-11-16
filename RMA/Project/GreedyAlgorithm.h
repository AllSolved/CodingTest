#pragma once
#include <iostream>
#include "STLHeader.h"
using namespace std;
//21. 8.8 예제 1
void Change();

//21.8.9 2번 큰 수의 법칙
void RulesOfBigNumber1();
void RulesOfBigNumber2();

//21.8.10 3번 숫자 카드 게임
void NumberCardGame1();
void NumberCardGame2();

//21.8.11 4번 1이 될때까지
void MakeOne();

//21.8.12 백준 4796번 캠핑
void Camping();

//22.7.22 백준 11399번 ATM
void ATM();

// 프로그래머스 큰 수 만들기
std::string MakeBigNumber(std::string number, int k);

// 프로그래머스 조이스틱
int JoyStick(std::string name);

// 프로그래머스 체육복
int SweatSuit(int n, vector<int> lost, vector<int> reserve);