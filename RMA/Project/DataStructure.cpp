#include "DataStructure.h"

void TalkMiddle()
{
    int N;
    cin >> N;

    vector<int> v;
    int number;
    for (int i = 0; i < N; ++i)
    {
        cin >> number;
        v.push_back(number);
    }

    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

    for (int i = 0; i < N; ++i)
    {
        // 최대 힙의 크기는 항상 최소 힙과 같거나 1만큼 더 커야 함
        if (maxQ.size() > minQ.size())
        {
            minQ.push(v[i]);
        }
        else
        {
            maxQ.push(v[i]);
        }

        // 최소 힙의 모든 원소는 최대 힙의 모든 원소보다 항상 같거나 커야함
        if (!maxQ.empty() && !minQ.empty())
        {
            if (minQ.top() < maxQ.top())
            {
                int maxTemp = maxQ.top();
                int minTemp = minQ.top();

                maxQ.pop();
                maxQ.push(minTemp);

                minQ.pop();
                minQ.push(maxTemp);
            }
        }

        cout << maxQ.top() << '\n';
    }
}
