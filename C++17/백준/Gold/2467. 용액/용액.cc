#include <bits/stdc++.h>

using namespace std;

int N;
int minSum = 2000000001;

int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    pair<int, int> answer;
    int left = 0;
    int right = N - 1;

    while (left < right)
    {
        int curSum = arr[left] + arr[right];

        if (abs(curSum) < minSum)
        {
            minSum = abs(curSum);
            answer = { arr[left], arr[right] };
        }

        if (curSum > 0)
        {
            right--;
        }
        else if (curSum < 0)
        {
            left++;
        }
        else
        {
            break;
        }
    }

    cout << answer.first << " " << answer.second << "\n";

    return 0;
}
