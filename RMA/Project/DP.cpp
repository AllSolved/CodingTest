#include "DP.h"

void NormalBagpack()
{
    int N, K;
    int DP[101][100001];
    int W[101];
    int V[100001];

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= K; ++j)
        {
            if (j - W[i] >= 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    cout << DP[N][K];
}

void Pibo()
{
	int dp[46] = { 0 };

	int n, answer;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

}

int TheWayToSchool(int m, int n, vector<vector<int>> puddles)
{
    int dp[101][101] = {0};

    // 갈 수 없는 곳은 -1로 
    for (int i = 0; i < puddles.size(); ++i)
    {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int a = 0;
            int b = 0;

            if (dp[i][j] == -1)
                continue;

            if (dp[i - 1][j] != -1)
                a = dp[i - 1][j];

            if (dp[i][j - 1] != -1)
                b = dp[i][j - 1];

            dp[i][j] += (a + b) % 1000000007;
        }
    }

    return dp[n][m];
}
