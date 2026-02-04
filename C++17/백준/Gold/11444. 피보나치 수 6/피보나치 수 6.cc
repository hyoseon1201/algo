#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

struct Matrix {
    ll data[2][2];
    Matrix() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0;
    }
};

// 행렬 곱셈 함수
Matrix multiply(Matrix A, Matrix B) {
    Matrix res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res.data[i][j] = (res.data[i][j] + A.data[i][k] * B.data[k][j]) % MOD;
            }
        }
    }
    return res;
}

// 행렬 거듭제곱 함수 (분할 정복)
Matrix power(Matrix A, ll n) {
    Matrix res;
    // 단위 행렬로 초기화 (곱셈의 항등원)
    res.data[0][0] = 1; res.data[1][1] = 1;

    while (n > 0) {
        if (n % 2 == 1) res = multiply(res, A);
        A = multiply(A, A);
        n /= 2;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    Matrix base;
    base.data[0][0] = 1; base.data[0][1] = 1;
    base.data[1][0] = 1; base.data[1][1] = 0;

    Matrix ans = power(base, n);

    // 결과 행렬의 1행 2열 값이 F_n
    cout << ans.data[0][1] << "\n";

    return 0;
}