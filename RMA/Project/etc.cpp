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


int Fibo(int n)
{
    int answer = 0;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);

    for (int i = 2; i <= n; ++i)
    {
        int sum = v[i - 1] + v[i - 2];
        v.push_back(sum % 1234567);
    }

    return v[n];
}

void SumNumber5()
{
    int N;
    cin >> N;

    int sum = 1;
    int count = 1;

    int start = 1;
    int end = 1;

    while (end != N)
    {
        if (sum > N)
        {
            sum -= start;
            ++start;
        }

        else if (sum < N)
        {
            ++end;
            sum += end;
        }

        else
        {
            ++end;
            sum += end;
            ++count;
        }

    }

    cout << count;
}

void Jumong()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N, 0);


    for (int i = 0; i < N; ++i)
    {
        scanf_s("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = N - 1;
    int result = 0;

    while (start < end)
    {
        int sum = v[start] + v[end];
        if (sum > M)
        {
            --end;
        }

        else if (sum == M)
        {
            ++result;
            ++start;
            --end;
        }

        else
        {
            ++start;
        }
    }

    printf("%d", result);

}

void GoodNumber()
{
    int N;
    cin >> N;

    vector<int> v(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        long target = v[i];
        int start = 0;
        int end = N - 1;
        while (start < end)
        {
            long sum = v[start] + v[end];

            if (sum == target)
            {
                if (start != i && end != i)
                {
                    ++answer;
                    break;
                }

                else if (start == i) { ++start; }
                else if (end == i) { --end; }
            }

            else if (sum < target)
            {
                ++start;
            }
            else
            {
                --end;
            }
        }
    }

    cout << answer;
}

void FindMinValue()
{
    int N, L;
    scanf_s("%d","%d", &N, &L);

    deque<pair<int, int>> dq;
    for (int i = 0; i < N; ++i)
    {
        int value = 0;
        scanf_s("%d", &value);
        pair<int, int> node = make_pair(i, value);

        // 가장 끝에 있는 값이 들어온 value보다 클 경우
        while (!dq.empty() && dq.back().second > value)
        {
            dq.pop_back();
        }

        dq.push_back(node);

        // index가 범위를 벗어날 경우
        if (dq.front().first <= i - L)
        {
            dq.pop_front();
        }

        printf("%d", dq.front().second, " ");
    }

}
