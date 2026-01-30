#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    long long arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 3];
    }

    while (t--)
    {
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}