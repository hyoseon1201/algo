#include <bits/stdc++.h>

using namespace std;

int n;
char gameType;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> gameType;

    set<string> players;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        players.insert(name);
    }

    int divisor = 1;

    if (gameType == 'Y')
    {
        divisor = 1;
    }
    else if (gameType == 'F')
    {
        divisor = 2;
    }
    else if (gameType == 'O')
    {
        divisor = 3;
    }

    cout << players.size() / divisor;

    return 0;
}