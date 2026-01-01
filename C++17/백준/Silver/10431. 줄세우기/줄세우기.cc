#include <bits/stdc++.h>

using namespace std;

int p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p;

    while (p--)
    {
        int t;
        int result = 0;
        cin >> t;

        vector<int> arr(20);

        for (int i = 0; i < 20; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[i])
                {
                    result++;
                }
            }
        }

        cout << t << " " << result << "\n";
    }

    return 0;
}