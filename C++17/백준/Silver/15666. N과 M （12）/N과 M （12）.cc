#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> input;
int result[10];

void solve(int startIdx, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = startIdx; i < input.size(); i++)
    {
        result[depth] = input[i];
        solve(i, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    sort(temp.begin(), temp.end());

    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    input = temp;

    solve(0, 0);

    return 0;
}