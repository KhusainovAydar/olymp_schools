#include <bits/stdc++.h>

using namespace std;

int dp[1488][19937];

const int mod = 1e9 + 7;

int main() {
    //freopen("fixedsum.in", "r", stdin); freopen("fixedsum.out", "w", stdout);
    int n, sum;
    cin >> n >> sum;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            for (int c = 0; c <= 9; c++) {
                if (j - c >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - c]) % mod;
            }
        }
    }
    cout << dp[n][sum];
}
