#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define INT_MAX 100000000

using namespace std;

typedef long long ll;

struct Node {
    int v;
    int tl, tr;
    int val, d;
    int num;
    bool ch;
};

const int NMAX = 8000005;
Node t[NMAX];

void build(int v, int tl, int tr) {
    if (tl >= tr) return;
    if (tr - tl == 1) {
        t[v].v = v;
        t[v].tl = tl;
        t[v].tr = tr;
        t[v].d = 0;
        t[v].num = tl;
        t[v].val = 0;
        t[v].ch = 0;
        return;
    }
    t[v].num = tl;
    t[v].ch = false;
    t[v].v = v;
    t[v].d = 0;
    t[v].val = 0;
    int tm = (tl + tr) >> 1;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm, tr);
    t[v].tl = t[2 * v].tl;
    t[v].tr = t[2 * v + 1].tr;
}

int val(int node) {
    if (t[node].ch == true) {
        return t[node].d;
    }
    return t[node].val;
}

void recalc(int node) {
    if (val(node * 2) <= val(node * 2 + 1)) {
        t[node].val = val(node * 2), t[node].num = t[node * 2].num;
    } else {
        t[node].val = val(node * 2 + 1), t[node].num = t[node * 2 + 1].num;
    }
}

void push(int node) {
    if (t[node].ch) {
        t[node * 2].d = max(val(t[node * 2].v), t[node].d);
        t[node * 2 + 1].d = max(val(t[node * 2 + 1].v), t[node].d);
        t[node * 2].ch = 1;
        t[node * 2 + 1].ch = 1;
        t[node].ch = false;
    }
}

void upd(int node, int a, int b, int kek) {
    int l = t[node].tl;
    int r = t[node].tr;
    if (a >= b) return;
    if (l == a && r == b) {
        t[node].d = max(val(node), kek);
        t[node].ch = true;
        return;
    }
    push(node);
    int tm = (l + r) >> 1;
    if (l < tm) {
        upd(2 * node, a, min(b, tm), kek);
    }
    if (r >= tm) {
        upd(2 * node + 1, max(a, tm), b, kek);
    }
    recalc(node);
    //t[node].val = min(val(node * 2), val(node * 2 + 1));
}

pair<int, int> get(int node, int a, int b) {
    int l = t[node].tl;
    int r = t[node].tr;
    if (l >= b || r <= a || a >= b) {
        return {INT_MAX, INT_MAX};
    }
    if (a == l && r == b) {
        return {val(node), t[node].num};
    }
    push(node);
    int tm = (l + r) >> 1;
    pair<int, int> ans = {INT_MAX, INT_MAX};
    if (l < tm) {
        auto p = get(node * 2, a, min(b, tm));
        ans = min(ans, p);
    }
    if (r >= tm) {
        auto p = get(node * 2 + 1, max(tm, a), b);
        ans = min(ans, p);
    }
    recalc(node);
    return ans;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("greatwall.in", "r", stdin);
    freopen("greatwall.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    build(1, 0, n);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "defend") {
            int l, r, val;
            cin >> l >> r >> val;
            upd(1, l - 1, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            pair<int, int> ans = get(1, l - 1, r);
            cout << ans.fi << ' ' << ans.se + 1 << endl;
            //cout << ans << endl;
        }
    }
}