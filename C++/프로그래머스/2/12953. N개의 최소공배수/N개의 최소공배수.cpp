#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) 
{
    return (a / gcd(a, b)) * b;
}

int lcmOfArray(const vector<int>& arr) 
{
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) 
    {
        result = lcm(result, arr[i]);
    }
    return result;
}

int solution(vector<int> arr) {
    int answer = 0;
    answer = lcmOfArray(arr);
    return answer;
}