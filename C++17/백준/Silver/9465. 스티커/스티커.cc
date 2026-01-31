#include <bits/stdc++.h>

using namespace std;

int t;

int arr[2][100001];
int dp[2][100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }

        // dp 시작
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];

        if (n >= 2)
        {
            dp[0][2] = arr[1][1] + arr[0][2];
            dp[1][2] = arr[0][1] + arr[1][2];
        }

        for (int i = 3; i <= n; i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }

    return 0;
}