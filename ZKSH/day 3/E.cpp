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

const int NMAX = 1000050;
const int K = 61;

ll p[NMAX];
int par[NMAX];
int go[K][NMAX];
int n, k;
ll m;

ll dist(int i, int j) {
    return abs(p[i] - p[j]);
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("pencils.in", "r", stdin);
//    freopen("pencils.out", "w", stdout);
#endif
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int pos1 = 0, pos2 = k;
    for (int i = 0; i < n; i++) {
        while (pos2 + 1 < n && dist(pos2 + 1, i) < dist(pos1, i)) pos2++, pos1++;
        if (dist(pos1, i) < dist(pos2, i)) {
            par[i] = pos2;
        } else {
            par[i] = pos1;
        }
    }
    for (int i = 0; i < n; i++) {
        go[0][i] = par[i];
    }
    for (int i = 1; i < K; i++) {
        for (int j = 0; j < n; j++) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }
//    for (int i = 0; i < n; i++) {
//        cout << par[i] << ' ';
//    }
//    cout << endl;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        int v = i;
        for (ll j = K - 1; j >= 0; j--) {
            if (sum + (1ll << j) <= m) {
                sum += (1ll << j);
                v = go[j][v];
            }
        }
        cout << v + 1 << ' ';
    }
}