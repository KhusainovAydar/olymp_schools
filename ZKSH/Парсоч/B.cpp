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

const int NMAX = 505;

int g[NMAX][NMAX];
vector<bool> used;
vector<int> mt;
int n;

bool try_kuhn(int v, int val) {
    if (used[v]) return false;
    used[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[v][i] > val) continue;
        if (mt[i] == -1 || try_kuhn(mt[i], val)) {
            mt[i] = v;
            return true;
        }
    }
    return false;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    used.resize(n + 1, 0);
    mt.resize(n + 1, 0);
    int L = -1000007, R = 1000007;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        fill(mt.begin(), mt.end(), -1);
        for (int i = 1; i <= n; i++) {
            fill(used.begin(), used.end(), 0);
            try_kuhn(i, M);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mt[i] != -1) {
                cnt++;
            }
        }
        if (cnt == n) {
            R = M;
        } else {
            L = M;
        }
    }
    int M = R;
    fill(mt.begin(), mt.end(), -1);
    for (int i = 1; i <= n; i++) {
        fill(used.begin(), used.end(), 0);
        try_kuhn(i, M);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mt[i] != -1) {
            cnt++;
        }
    }
    cout << R << endl;
    for (int i = 1; i <= n; i++) {
        cout << mt[i] << ' ' << i << endl;
    }
}