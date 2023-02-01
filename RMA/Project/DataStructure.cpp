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

vector<int> DoublePriorityQueue(vector<string> operations)
{
    priority_queue<int> q;
    vector<int> answer;

    for (int i = 0; i < 2; ++i)
    {
        answer.push_back(0);
    }

    for (int i = 0; i < operations.size(); ++i)
    {
        string str = operations[i];;
        if (str.find("I") != string::npos)
        {
            string sCut = str.substr(str.find(' ') + 1);
            int number = stoi(sCut);
            q.push(number);
        }

        else
        {
            if (q.empty())
                continue;

            else
            {
                if (str.find("D 1") != string::npos)
                {
                    q.pop();
                }

                else
                {
                    priority_queue<int> tempQ;
                    while (q.size() != 1)
                    {
                        tempQ.push(q.top());
                        q.pop();
                    }

                    q.swap(tempQ);
                }
            }
        }


    }

    if (!q.empty())
    {
        answer[0] = q.top();
        q.pop();

        while (q.size() != 1)
        {
            q.pop();
        }

        answer[1] = q.top();
    }

    for (int i = 0; i < 2; ++i)
    {
        cout << answer[i] << ' ';
    }

    return answer;
}

vector<int> DoublePriorityQueue2(vector<string> operations)
{
    vector<int> answer;
    multiset<int> table;

    for (int i = 0; i < 2; ++i)
        answer.push_back(0);

    for (int i = 0; i < operations.size(); ++i)
    {
        string str = operations[i];

        if (str.find("I") != string::npos)
        {
            string sCut = str.substr(str.find(' ') + 1);
            int number = stoi(sCut);
            table.insert(number);
        }

        else if (str.find("D 1") != string::npos)
        {
            if (table.size() != 0)
                table.erase(--table.end());
        }

        else
        {
            if (table.size() != 0)
                table.erase(table.begin());
        }
    }

    if (table.size() != 0)
    {
        answer[0] = *(--table.end());
        answer[1] = *(table.begin());
    }

    return answer;
}
