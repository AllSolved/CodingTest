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
        // �ִ� ���� ũ��� �׻� �ּ� ���� ���ų� 1��ŭ �� Ŀ�� ��
        if (maxQ.size() > minQ.size())
        {
            minQ.push(v[i]);
        }
        else
        {
            maxQ.push(v[i]);
        }

        // �ּ� ���� ��� ���Ҵ� �ִ� ���� ��� ���Һ��� �׻� ���ų� Ŀ����
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
