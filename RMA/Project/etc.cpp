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
