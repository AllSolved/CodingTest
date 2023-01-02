#include "etc.h"

string MaxMin(string s)
{
    vector<int> numbers;
    string answer = "";

    string number = "";
    for (int i = 0; i < s.length(); ++i)
    {
        number += s[i];

        if (s[i] == ' ' || i == (s.length() - 1))
        {
            numbers.push_back(stoi(number));
            number.clear();
        }
    }

    sort(numbers.begin(), numbers.end());

    answer += to_string(numbers[0]);
    answer += ' ';
    answer += to_string(numbers[numbers.size() - 1]);

    return answer;
}

bool CheckLine(bool* arr, int findCount, string currentWord)
{
    bool result = false;
    int checkCount = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i])
        {
            ++checkCount;
        }
    }

    // 각 줄에서 하나씩 찾고, 단어를 전부 찾았다면
    if (checkCount == 3 &&
        findCount == currentWord.length())
    {
        result = true;
    }

    return result;
}

vector<string> CardGame(vector<string> card, vector<string> word)
{
    vector<string> answer = {};

    // 한 단어당 vector를 전부 탐색해야함.
    for (int i = 0; i < word.size(); ++i)
    {
        string strCard;
        // 카드를 하나의 문자열로 변환
        for (int i = 0; i < card.size(); ++i)
        {
            strCard += card[i];
        }

        string currentWord = word[i];
        int findCount = 0;
        bool checkLine[3] = { false };

        for (int j = 0; j < currentWord.length(); ++j)
        {
            char findChar = currentWord[j];
            int pos = strCard.find(findChar);

            // 문자가 존재하지 않을 경우
            if (pos == -1)
            {
                cout << findChar;
                break;
            }
            else
            {
                // 찾았을 경우 해당 문자를 소문자로 바꿔줌(찾음 처리)
                strCard[pos] += 32;

                int line = pos / 8;
                checkLine[line] = true;
                ++findCount;
            }
        }

        if (CheckLine(checkLine, findCount, currentWord))
        {
            answer.push_back(currentWord);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back("-1");
    }

    return answer;

}
