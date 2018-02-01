#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
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

const int NMAX = 1000005;

int n;
int t[4 * NMAX], a[NMAX], pos[4 * NMAX];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        pos[v] = tl;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        if (t[2 * v + 1] > t[2 * v + 2]) {
            t[v] = t[2 * v + 1];
            pos[v] = pos[2 * v + 1];
        } else {
            t[v] = t[2 * v + 2];
            pos[v] = pos[2 * v + 2];
        }
    }
}

pair<int, int> maxx(int v, int tl, int tr, int l, int r) {
    if (tl > tr || l > tr || tl > r || l > r) {
        return make_pair(0, 0);
    }
    if (tl == l && tr == r) {
        return {t[v], pos[v]};
    }
    int tm = (tl + tr) >> 1;
    return max(maxx(2 * v + 1, tl, tm, l, min(tm, r)), maxx(2 * v + 2, tm + 1, tr, max(tm + 1, l), r));
}

int proc(int l, int r) {
    if (l > r) return 0;
    pair<int, int> zap = maxx(0, 0, n - 1, l, r);
    int pos = zap.se;
    return min(proc(l, pos - 1), proc(pos + 1, r)) + 1;
}

int main() {
//    srand((unsigned ll)time(NULL));
//    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    cout << proc(0, n - 1);
}