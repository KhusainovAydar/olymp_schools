#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

vector<int> a;
int n;

struct Node {
    int val;
    int l, r;
};

vector<Node> t;

void build(int v, int tl, int tr) {
    if (tr - tl == 1) {
        t[v].val = a[tl];
        t[v].l = tl;
        t[v].r = tr;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm, tr);
        t[v].l = tl;
        t[v].r = tr;
        t[v].val = max(t[v * 2].val, t[2 * v + 1].val);
    }
}

void upd(int v, int pos, int val) {
    int tl = t[v].l;
    int tr = t[v].r;
    if (tr - tl == 1) {
        t[v].val = val;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm - 1) {
            upd(2 * v, pos, val);
        } else {
            upd(2 * v + 1, pos, val);
        }
        t[v].val = max(t[2 * v].val, t[2 * v + 1].val);
    }
}

int ans(int v, int l, int r) {
    int tl = t[v].l;
    int tr = t[v].r;
    if (l >= r) {
        return INT_MIN;
    }
    if (tl >= tr) return INT_MIN;
    if (tl == l && tr == r) {
        return t[v].val;
    }
    int tm = (tl + tr) >> 1;
    return max(ans(2 * v, l, min(r, tm)),
               ans(2 * v + 1, max(l, tm), r));
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #endif*/
    cin >> n;
    a.resize(n);
    t.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n);
    while (true) {
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if (c == '+') {
            upd(1, x - 1, y);
            cout << "OK" << endl;
        } else {
            cout << ans(1, x - 1, y) << endl;
        }
    }
}
