#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int arr[101][101];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = 987654321;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][k] + arr[k][j] < arr[i][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    int minVal = 987654321;
    int ans = 0;

    for (int i = 1; i <= n; i++) 
    {
        int sum = 0;
        for (int j = 1; j <= n; j++) 
        {
            sum += arr[i][j];
        }

        if (sum < minVal) 
        {
            minVal = sum;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}