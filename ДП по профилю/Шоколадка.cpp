#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 4;

bool can[(1 << NMAX)][(1 << NMAX)], used[(1 << NMAX)][(1 << NMAX)];

int sum[34][(1 << NMAX)];

bool check(int mask1, int mask2) {
    if (used[mask1][mask2])
        return can[mask1][mask2];
    bool ch = 1;
    for (int i = 0; i < 3; i++) {
        if (((mask1 >> i) & 1) == ((mask2 >> i) & 1))
            ch = false;
    }
    can[mask1][mask2] = ch;
    used[mask1][mask2] = 1;
    for (int y = 0; y < 3; y++) {
        if (!((mask1 >> y) & 1) && !((mask1 >> (y + 1)) & 1) && (y + 1 < 3))
            ch |= check(mask1 | (1 << y) | (1 << (y + 1)), mask2);
    }
    can[mask1][mask2] = ch;
    return ch;
}

int main() {
    for (int i = 0; i < (1 << 3); i++) {
        for (int j = 0; j < (1 << 3); j++) {
            can[i][j] = check(i, j);
        }
    }
    int n;
    cin >> n;
    sum[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << 3); j++) {
            for (int y = 0; y < (1 << 3); y++) {
                sum[i][j] += sum[i - 1][y] * can[y][j];
            }
        }
    }
    int ans = 0;
    ans = sum[n][0];
    cout << ans;
}