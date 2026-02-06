#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int C, N;

int dp[1101];

int main()
{
	cin >> C >> N;

	fill(dp, dp + 1101, INF);
	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		int cost, guest;
		cin >> cost >> guest;

		for (int j = guest; j <= C + 100; j++)
		{
			if (dp[j - guest] != INF)
			{
				dp[j] = min(dp[j], dp[j - guest] + cost);
			}
		}
	}

	int minWeight = INF;
	for (int i = C; i <= C + 100; i++)
	{
		minWeight = min(minWeight, dp[i]);
	}

	cout << minWeight << "\n";

	return 0;
}