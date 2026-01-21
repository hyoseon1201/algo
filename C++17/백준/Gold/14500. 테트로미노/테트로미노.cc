#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int board[501][501];
int result = 0;

int tetro[19][3][2] = 
{
    // 1
    { {0, 1}, {0, 2}, {0, 3} },
    { {1, 0}, {2, 0}, {3, 0} },

    // 2
    { {0, 1}, {1, 0}, {1, 1} },

    // 3
    { {1, 0}, {2, 0}, {2, 1} },
    { {1, 0}, {2, 0}, {2, -1}}, 
    { {0, 1}, {0, 2}, {1, 0} },
    { {0, 1}, {0, 2}, {1, 2} },
    { {0, 1}, {1, 1}, {2, 1} },
    { {0, 1}, {1, 0}, {2, 0} },
    { {1, 0}, {1, 1}, {1, 2} },
    { {1, 0}, {1, -1}, {1, -2}},

    // 4
    { {1, 0}, {1, 1}, {2, 1} },
    { {1, 0}, {1, -1}, {2, -1}},
    { {0, 1}, {1, 1}, {1, 2} },
    { {0, 1}, {-1, 1}, {-1, 2}},

    // 5
    { {0, 1}, {0, 2}, {1, 1} },
    { {0, 1}, {0, 2}, {-1, 1}},
    { {1, 0}, {2, 0}, {1, 1} },
    { {1, 0}, {2, 0}, {1, -1}}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 19; k++) 
            {
                int sum = board[i][j];
                bool possible = true;

                for (int l = 0; l < 3; l++) 
                {
                    int ny = i + tetro[k][l][0];
                    int nx = j + tetro[k][l][1];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) 
                    {
                        possible = false;
                        break;
                    }
                    sum += board[ny][nx];
                }

                if (possible) 
                {
                    result = max(result, sum);
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}