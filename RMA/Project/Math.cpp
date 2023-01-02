#include "Math.h"

// ��Ŭ���� ȣ����
vector<int> AdditionOfFractions(int denum1, int num1, int denum2, int num2)
{
    vector<int> answer;

    // 1. ���� �и� ���� (�ּ� �����)
    int Min = min(num1, num2);
    int Max = max(num1, num2);

    int denominator = Max;
    while (denominator % Min != 0)
    {
        denominator += Max;
    }
    int molecule = denum1 * (denominator / num1) + denum2 * (denominator / num2);

    // 2. �ִ� ������� ���ؼ� ����
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
