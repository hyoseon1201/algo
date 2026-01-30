#include <bits/stdc++.h>

using namespace std;

int n;
int board[128][128];
int white = 0;
int blue = 0;

void solve(int y, int x, int size)
{
    int color = board[y][x];
    bool isSame = true;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (board[i][j] != color)
            {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame)
    {
        if (color == 0) white++;
        else blue++;
    }
    else
    {
        int nextSize = size / 2;
        solve(y, x, nextSize); // 왼쪽 위
        solve(y, x + nextSize, nextSize); // 오른쪽 위
        solve(y + nextSize, x, nextSize); // 왼쪽 아래
        solve(y + nextSize, x + nextSize, nextSize); // 오른쪽 아래
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(0, 0, n);

    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}