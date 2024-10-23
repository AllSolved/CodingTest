#include "Graph.h"

vector<vector<int>> arr;
vector<int> answer;
vector<int> visited;

void FindCity_BFS(int start)
{
    queue<int> q;
    q.push(start);
    ++visited[start];

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();


        for (int i : arr[cur])
        {
            // �湮���� ���� ��忡 ���� �湮 �Ÿ� ���
            // (���� ����� �湮 �Ÿ� +1)
            if (visited[i] == -1)
            {
                visited[i] = visited[cur] + 1;
                q.push(i);
            }
        }
    }
}

void FindCity()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;
    arr.resize(N + 1);
    visited = vector<int>(N + 1, -1);


    // �ܹ��� �׷���
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        arr[s].push_back(e);
    }

    FindCity_BFS(X);

    for (int i = 0; i <= N; ++i)
    {
        // �ִ� �Ÿ�
        if (visited[i] == K)
        {
            answer.push_back(i);
        }
    }

    if (answer.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        sort(answer.begin(), answer.end());
        for (int i : answer)
        {
            cout << i << "\n";
        }
    }

}
