#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

vector<int> a;
vector< vector<int> > t;
int n, m;

vector<int> MERGE(vector<int> A, vector<int> B) {
    vector<int> M((int)A.size() + (int)B.size());
    merge(A.begin(), A.end(), B.begin(), B.end(), M.begin());
    return M;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].push_back(a[tl]);
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        t[v] = MERGE(t[2 * v + 1], t[2 * v + 2]);
    }
}

int get_ans(int v, int tl, int tr, int x, int y, int l, int r) {
    if (tl == x && tr == y) {
        return int(upper_bound(t[v].begin(), t[v].end(), r) - lower_bound(t[v].begin(), t[v].end(), l));
    } else {
        if (x > y) return 0;
        int tm = (tl + tr) >> 1;
        return get_ans(2 * v + 1, tl, tm, x, min(tm, y), l, r) +
        get_ans(2 * v + 2, tm + 1, tr, max(x, tm + 1), y, l, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
#endif
    cin >> n >> m;
    a.resize(n);
    t.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        x--, y--;
        cout << get_ans(0, 0, n - 1, x, y, l, r) << endl;
    }
}