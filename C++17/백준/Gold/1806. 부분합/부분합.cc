#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int curSum = 0;
	int ans = 100001;

	while (true)
	{
		if (curSum >= S)
		{
			ans = min(ans, end - start);
			curSum -= arr[start++];
		}
		else if (end == N)
		{
			break;
		}
		else
		{
			curSum += arr[end++];
		}
	}

	if (ans == 100001) 
	{
		cout << 0 << "\n";
	}
	else 
	{
		cout << ans << "\n";
	}

	return 0;
}