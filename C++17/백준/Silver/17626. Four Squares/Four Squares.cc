#include <bits/stdc++.h>

using namespace std;

int n;
int dp[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[50001];

    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        dp[i] = i;
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}