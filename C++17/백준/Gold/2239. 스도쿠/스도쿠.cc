#include <bits/stdc++.h>

using namespace std;

int board[9][9];
bool rowVisited[9][10], colVisited[9][10], boxVisited[9][10];

void solve(int n)
{
    if (n == 81)
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) cout << board[i][j];
            cout << '\n';
        }
        exit(0);
    }

    int r = n / 9;
    int c = n % 9;

    if (board[r][c] != 0)
    {
        solve(n + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++) 
        {
            int boxIdx = (r / 3) * 3 + (c / 3);
            if (!rowVisited[r][i] && !colVisited[c][i] && !boxVisited[boxIdx][i]) 
            {
                board[r][c] = i;
                rowVisited[r][i] = colVisited[c][i] = boxVisited[boxIdx][i] = true;

                solve(n + 1);

                board[r][c] = 0;
                rowVisited[r][i] = colVisited[c][i] = boxVisited[boxIdx][i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) 
    {
        string rowStr; cin >> rowStr;

        for (int j = 0; j < 9; j++) 
        {
            board[i][j] = rowStr[j] - '0';
            if (board[i][j] != 0) 
            {
                int val = board[i][j];
                rowVisited[i][val] = true;
                colVisited[j][val] = true;
                boxVisited[(i / 3) * 3 + (j / 3)][val] = true;
            }
        }
    }
    solve(0);
    return 0;
}