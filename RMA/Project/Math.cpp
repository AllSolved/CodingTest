#include "Math.h"

// 유클리드 호제법
vector<int> AdditionOfFractions(int denum1, int num1, int denum2, int num2)
{
    vector<int> answer;

    // 1. 공통 분모를 구함 (최소 공배수)
    int Min = min(num1, num2);
    int Max = max(num1, num2);

    int denominator = Max;
    while (denominator % Min != 0)
    {
        denominator += Max;
    }
    int molecule = denum1 * (denominator / num1) + denum2 * (denominator / num2);

    // 2. 최대 공약수를 구해서 나눔
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

long long N, K, A, B, half;
long long mod = 1000000007;

long long solve(int x)
{
    if (x == 0) return 1;

    if (x % 2 == 1) return B * solve(x - 1) % mod;
    else
    {
        half = solve(x / 2);
        return half * half % mod;
    }
}

void BinomialCoefficient()
{
    cin >> N >> K;
	A = 1;
	// A = N*(N-1)* .... *(N-K+1)
	for (int i = N; i >= N - K + 1; i--) A = (A * i) % mod;

	// B = K!
	B = 1;
	for (int i = 1; i <= K; i++) B = (B * i) % mod;

	// B = (K!)^(p-2)
	B = solve(mod - 2);

	cout << A * B % mod;
}


void DistributedProcessing()
{
    int T,a,b,answer;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        answer = 1;
        cin >> a >> b;

        for (int j = 0; i < b; ++j)
        {
            answer = (answer * a) % 10;
        }

        answer = answer == 0 ? 10 : answer;
        cout << answer << '\n';
    }
}

int Binary(int number)
{
    int count = 0;
    while (number != 0)
    {
        if (number % 2 == 1) // 나머지가 1
            ++count;

        number /= 2;
    }

    return count;
}


int NextBigNumber(int n)
{
    // for문 한번까지는 시간 복잡도가 괜찮다
    // 1씩 증가시켜가며 1의 갯수를 비교

    int answer = 0;

    int count = Binary(n);

    for (int i = n + 1; i < 1000000; ++i)
    {
        if (Binary(i) == count)
            return i;
    }

    return answer;
}

int JumpAndTeleport(int n)
{
	int cnt = 0;

	while (n > 0)
	{
		if (n % 2 == 0)
			n /= 2;
		else
		{
			--n;
			++cnt;
		}
	}
	return cnt;
}

int ZOAC4()
{
	int h, w, n, m;
	cin >> h;
	cin >> w;
	cin >> n;
	cin >> m;

	int answer = 0;
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			++answer;
			j += n;
		}

		i += m;
	}

	cout << answer;
	return 0;
}

void SumAverage()
{
    int N, M = 0;
    cin >> N;

    priority_queue<int> pq;
    int score;
    for (int i = 0; i < N; ++i)
    {
        cin >> score;
        pq.push(score);
    }

    M = pq.top();
    double result = 0;
    while (!pq.empty())
    {
        result += pq.top();
        pq.pop();
    }
    cout << result * 100 / M / N;
}

int sum[1025][1025] = { 0 };
void SumRange5()
{
    int N, M = { 0 };
    cin >> N >> M;


    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            // 수 입력 받기
            int num = 0;
            cin >> num;
            sum[x][y] = sum[x][y - 1] + sum[x - 1][y] - sum[x - 1][y - 1] + num;
        }
    }

    cout << "\n";
    cout << "구간합";
    cout << "\n";

    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            cout << sum[x][y] << " ";
        }

        cout << "\n";
    }

    cout << "\n";
    cout << "정답";
    cout << "\n";

    // 답 도출
    for (int i = 0; i < M; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        cout << answer << "\n";
    }

}