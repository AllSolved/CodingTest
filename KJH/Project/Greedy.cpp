#include <string>
#include <vector>
#include <iostream>

using namespace std;

#pragma region �õ�
string solution(string number, int k)
{
    string answer = "";

    int size = number.size() - k; //�ڸ���

    int numberi = atoi(number.c_str()); //number�� int�� ��ȯ

    string maxNum; // ������ �ִ�

    vector<char> digit; // �� �ڸ����� ��

    for (int i = 0; i < number.size(); i++)
    {
        digit.push_back(number.at(i));
    }

    for (int i = 0; i < digit.size(); i++)
    {
        // ��;˰������� answer ���ϱ�

    }

    return answer;
}

void AddNum(vector<char> digit, string ans, int i, int digitSize, int size) {
    if (size <= 0)
    {
        int prev = atoi(ans.c_str());

        int answ = atoi(ans.c_str());

        if (prev <= answ)
        {
            return;
        }
        else
        {
            ans = ans;
            return;
        }
    }

    for (int n = i; n < digitSize; n++)
    {
        ans += digit[n];
    }
}

#pragma endregion


#pragma region ����

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    // answersize��ŭ for���� ������ �� ���� �� ���ھ� answer�� ������, �� �� ���� ������ startidx���� k+i���� ������.
    // �̷��� �ѵ��� �ΰ� ������ answersize��ŭ�� answer ���ڵ��� �̾ƿ� �� �ֱ� �����̴�.

    int answersize = number.size() - k; // return���� ���̴� number�� ������� k�� �� ��

    int startidx = 0; // ���� index

    for (int i = 0; i < answersize; ++i)
    { // answersize��ŭ �ݺ�
        char maxint = number[startidx]; // ó������ startidx�� ���� �ִ밪
        int maxidx = startidx; // ó������ maxidx�� startidx

        for (int j = startidx; j <= k + i; j++)
        { // startidx���� k+i���� Ȯ���ؼ� max�� ã�� -k
            if (maxint < number[j])
            { // �� ū ���� ������ �� ���� index�� number�� ����
                maxint = number[j];
                maxidx = j;
            }
        }

        startidx = maxidx + 1; // ���������� maxindex + 1�������� ����
        answer += maxint; // answer�� ���� ū ���� �ִ´�
    }

    return answer;
}

#pragma endregion

// ���� ����
// �տ������� ū ���� �����ϸ� �Ǵµ� �����ϰ� ��� ����� ���� ���Ϸ��� ����
