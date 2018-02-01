#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 150;

bool used[NMAX][NMAX];

bool ch(int x, int y) {
    return 1 <= x && x < NMAX && 1 <= y && y < NMAX;
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        used[x][y] = 1;
        for (int i = 1; i <= n; i++) {
            if (ch(x + i, y + i)) {
                used[x + i][y + i] = 1;
            }
            if (ch(x + i, y - i)) {
                used[x + i][y - i] = 1;
            }
            if (ch(x - i, y + i)) {
                used[x - i][y + i] = 1;
            }
            if (ch(x - i, y - i)) {
                used[x - i][y - i] = 1;
            }
            if (ch(x + i, y)) {
                used[x + i][y] = 1;
            }
            if (ch(x - i, y)) {
                used[x - i][y] = 1;
            }
            if (ch(x, y + i)) {
                used[x][y + i] = 1;
            }
            if (ch(x, y - i)) {
                used[x][y - i] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!used[i][j]) {
                ans++;
            }
        }
    }
    cout << ans;
}
