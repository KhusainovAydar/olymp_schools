#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define rand() ((rand() << 16) + rand())
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//#define MIN -2147483648
//#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 2e5 + 50, K = 505;

bool used[NMAX][K];

int dp[NMAX][K];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cout.precision(20);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    //    freopen("sweets.in", "r", stdin);
    //    freopen("sweets.out", "w", stdout);
#endif
    int n, x;
    cin >> n;
    used[NMAX / 2][0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        for (int rz = 0; rz < NMAX; rz++) {
            if (used[rz][i]) {
                used[rz + x][i + 1] = 1;
                used[rz - x][i + 1] = 1;
                used[rz][i + 1] = 1;
                
                if (rz + x < NMAX) {
                    dp[rz + x][i + 1] = max(dp[rz + x][i + 1], dp[rz][i] + x);
                }
                
                if (rz - x >= 0) {
                    dp[rz - x][i + 1] = max(dp[rz - x][i + 1], dp[rz][i] + x);
                }
                
                dp[rz][i + 1] = max(dp[rz][i + 1], dp[rz][i]);
            }
        }
    }
    cout << sum - dp[NMAX / 2][n] / 2;
}