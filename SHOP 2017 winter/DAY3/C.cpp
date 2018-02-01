#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 131072, K = 1000;

unsigned int f[NMAX];
vector<unsigned int> t[4 * NMAX];
unsigned int a, b;
unsigned int cur = 0;

unsigned int nextRand17() {
    cur = cur * a + b;
    return (cur >> 15);
}

unsigned int nextRand24() {
    cur = cur * a + b;
    return (cur >> 8);
}

vector<unsigned int> merge(vector<unsigned int> & A, vector<unsigned int> & B) {
    vector<unsigned int> mer;
    int pos1 = 0, pos2 = 0;
    int n = (int)A.size(), m = (int)B.size();
    while (pos1 < n && pos2 < m) {
        if (A[pos1] < B[pos2]) {
            mer.pb(A[pos1]);
            pos1++;
        } else {
            mer.pb(B[pos2]);
            pos2++;
        }
    }
    while (pos1 < n) {
        mer.pb(A[pos1]);
        pos1++;
    }
    while (pos2 < m) {
        mer.pb(B[pos2]);
        pos2++;
    }
    return mer;
}

void build(int v, int tl, int tr) {
    if (tl > tr) return;
    if (tl == tr) {
        t[v].pb(f[tl]);
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
}

unsigned int get(int v, int tl, int tr, unsigned int l, unsigned int r, unsigned int x, unsigned int y) {
    if (tl > tr || l > r || tl > r || l > tr) {
        return 0;
    }
    if (tl == l && tr == r) {
        return upper_bound(all(t[v]), y) - lower_bound(all(t[v]), x);
    }
    int tm = (tl + tr) >> 1;
    return get(2 * v + 1, tl, tm, l, min((unsigned int) tm, r), x, y) + get(2 * v + 2, tm + 1, tr, max(l, (unsigned int)tm + 1), r, x, y);
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("maxflow.in", "r", stdin);
//    freopen("subst3.out", "w", stdout);
#endif
    unsigned int q;
    cin >> q >> a >> b;
    for (int i = 0; i < NMAX; i++) {
        f[i] = nextRand24();
    }
//    for (int i = 0; i < NMAX / K + 1; i++) {
//        sqr[i] = NULL;
//        for (int j = i * K; j < min(NMAX, (i + 1) * K); j++) {
//            sqr[i] = add(sqr[i], new node(f[j]));
//        }
//    }
    build(0, 0, NMAX - 1);
    unsigned int ans = 0;
    unsigned int sym = 0;
    while (q--) {
        unsigned int l = nextRand17();
        unsigned int r = nextRand17();
        if (l > r) swap(l, r); // получили отрезок [l..r]
        unsigned int x = nextRand24();
        unsigned int y = nextRand24();
        if (x > y) swap(x, y); // получили отрезок [x..y]
        unsigned int cur1 = get(0, 0, NMAX - 1, l, r, x, y);
        b += cur1;
        ans += cur1;
    }
    cout << ans;
}