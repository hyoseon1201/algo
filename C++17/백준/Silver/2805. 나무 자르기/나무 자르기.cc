#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
vector<long long> trees;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    long long max_h = 0;
    for (int i = 0; i < n; i++)
    {
        long long h;
        cin >> h;
        trees.push_back(h);
        if (h > max_h)
        {
            max_h = h;
        }
    }

    long long start = 0;
    long long end = max_h;
    long long result = 0;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (trees[i] > mid)
            {
                sum += (trees[i] - mid);
            }
        }

        if (sum >= m)
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}