#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input, segment;
    cin >> input;

    stringstream ss(input);
    vector<int> sums;

    while (getline(ss, segment, '-'))
    {
        int currentSum = 0;
        stringstream ssPlus(segment);
        string numStr;

        while (getline(ssPlus, numStr, '+'))
        {
            currentSum += stoi(numStr);
        }
        sums.push_back(currentSum);
    }

    int answer = sums[0];
    for (int i = 1; i < sums.size(); i++)
    {
        answer -= sums[i];
    }

    cout << answer << "\n";

    return 0;
}