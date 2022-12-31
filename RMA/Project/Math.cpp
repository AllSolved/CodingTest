#include "Math.h"

// 유클리드 호제법
vector<int> AdditionOfFractions(int denum1, int num1, int denum2, int num2)
{
    vector<int> answer;

    // 1. 공통 분모를 구함 (최소 공배수)
    int Min = min(num1, num2);
    int Max = max(num1, num2);

    int denominator = Max;
    while (denominator % Min != 0)
    {
        denominator += Max;
    }
    int molecule = denum1 * (denominator / num1) + denum2 * (denominator / num2);

    // 2. 최대 공약수를 구해서 나눔
    Min = min(denominator, molecule);
    Max = max(denominator, molecule);

    int remain = 0;
    while (Min != 0)
    {
        remain = Max % Min;
        Max = Min;
        Min = remain;
    }

    answer.push_back(molecule / Max);
    answer.push_back(denominator / Max);

    return answer;
}
