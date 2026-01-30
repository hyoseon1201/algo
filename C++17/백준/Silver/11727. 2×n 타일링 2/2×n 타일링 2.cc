#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1001];

    cin >> n;

    arr[1] = 1;
    arr[2] = 3;

    for (int i = 3; i <= 1000; i++)
    {
        arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
    }

    cout << arr[n] << "\n";

    return 0;
}