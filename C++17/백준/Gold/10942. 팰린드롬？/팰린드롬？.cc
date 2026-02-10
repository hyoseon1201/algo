#include <bits/stdc++.h>

using namespace std;

int arr[2001];
bool isPalindrome[2001][2001];

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        isPalindrome[i][i] = true;
    }

    for (int i = 1; i < N; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            isPalindrome[i][i + 1] = true;
        }
    }

    for (int len = 2; len < N; len++)
    {
        for (int start = 1; start <= N - len; start++)
        {
            int end = start + len;
            if (arr[start] == arr[end] && isPalindrome[start + 1][end - 1])
            {
                isPalindrome[start][end] = true;
            }
        }
    }

    cin >> M;

    while (M--)
    {
        int S, E;
        cin >> S >> E;
        cout << isPalindrome[S][E] << "\n";
    }

    return 0;
}