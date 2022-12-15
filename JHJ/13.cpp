#include <stdio.h> 
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string strNum = "";
	int n, result = 0, maxNum = 0;
	cin >> strNum;

   const int strLen = strNum.length();

	int numCount[strLen] = {0};
	
	for(int i = 0; i < strLen; ++i)
	{
		int temp = strNum[i] - '0';
		numCount[temp] += 1;
	}
	
	for(int i = 1; i < strLen; ++i)
	{
		if(numCount[i] > maxNum)
		{
			maxNum = numCount[i]; 
			result = i;	
		}
		if(numCount[i] == maxNum)
		{
			if(i > result) 
			{
				result = i;
			}
		}
	}
	
	printf("%d", result);
	return 0;
}

/*
#include <stdio.h> 
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string strNum = "";
	int n, result = 0, maxNum = 0;
	cin >> strNum;

   const int strLen = strNum.length();

	int numCount[strLen] = {0};
	
	for(int i = 0; i < strLen; ++i)
	{
		int temp = strNum[i] - '0';
		numCount[temp] += 1;
	}
	
	for(int i = 1; i < strLen; ++i)
	{
		if(numCount[i] > maxNum) // numCount[i] : 숫자 순서의 개수
		{
			//i번째 숫자의 수가 최대값보다 클때
			maxNum = numCount[i]; //번째 숫자 값을 최대에 넣고
			result = i;	// 해당 순서를 결과값에 넣어줌
		}
		if(numCount[i] == maxNum) //번째 숫자의 수와 값이 같을때
		{
			if(i > result) // 해당 순서와 결과값을 비교해서 큰 수를 넣음
			{
				result = i;
			}
		}
	}
	
	printf("%d", result);
	return 0;
}
*/
