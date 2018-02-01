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
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
using namespace std;

typedef long long ll;

vector<ll> tmin, push;
vector<ll> check;

void Push(int v) {
    if (push[v] == MIN) return;
    if (push[2 * v + 1] < push[v] || push[2 * v + 1] == MIN) push[2 * v + 1] = push[v];
    if (push[2 * v + 2] < push[v] || push[2 * v + 2] == MIN) push[2 * v + 2] = push[v];
    push[v] = MIN;
}

void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (tl == l && tr == r) {
        //Push(v);
        push[v] = val;
        //tmin[v] = min((push[2 * v + 1] == MAX ? tmin[2 * v + 1] : push[2 * v + 1]), (push[2 * v + 2] == MAX ? tmin[2 * v + 2] : push[2 * v + 2]));
    } else {
        int tm = (tl + tr) >> 1;
        Push(v);
        upd(2 * v + 1, tl, tm, l, min(tm, r), val);
        upd(2 * v + 2, tm + 1, tr, max(tm + 1, l), r, val);
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tmin[v] = push[v];
    } else {
        int tm = (tl + tr) >> 1;
        Push(v);
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        tmin[v] = min(tmin[2 * v + 1], tmin[2 * v + 2]);
    }
}

void buildcheck(int v, int tl, int tr, vector<ll> &a) {
    if (tl == tr) {
        check[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        buildcheck(2 * v + 1, tl, tm, a);
        buildcheck(2 * v + 2, tm + 1, tr, a);
        check[v] = min(check[2 * v + 1], check[2 * v + 2]);
    }
}

ll mincheck(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return check[v];
    }
    if (l > r) return MAX;
    int tm = (tl + tr) >> 1;
    return min(mincheck(2 * v + 1, tl, tm, l, min(r, tm)), mincheck(2 * v + 2, tm + 1, tr, max(tm + 1, l), r));
}

ll value(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return tmin[v];
    int tm = (tl + tr) >> 1;
    if (pos <= tm) return value(2 * v + 1, tl, tm, pos);
    else return value(2 * v + 2, tm + 1, tr, pos);
}

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
#endif*/
    int n, m;
    cin >> n >> m;
    tmin.resize(4 * n, MIN);
    push.resize(4 * n, MIN);
    vector< pair<int, pair<int, int> > > zap;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        //upd(0, 0, n - 1, a, b, c);
        zap.push_back({c, {a, b}});
    }
    sort(zap.begin(), zap.end());
    for (int i = 0; i < m; i++) {
        int a = zap[i].se.fi;
        int b = zap[i].se.se;
        int c = zap[i].fi;
        //cout << a << ' ' << b << ' ' << c << endl;
        upd(0, 0, n - 1, a, b, c);
    }
    vector<ll> a;
    build(0, 0, n - 1);
    for (int i = 0; i < n; i++) {
        a.push_back(value(0, 0, n - 1, i));
    }
    check.resize(4 * n, MAX);
    buildcheck(0, 0, n - 1, a);
    for (int i = 0; i < m; i++) {
        if (mincheck(0, 0, n - 1, zap[i].se.fi, zap[i].se.se) != zap[i].fi) {
            cout << "inconsistent";
            return 0;
        }
    }
    cout << "consistent" << endl;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == MAX) cout << 2147483647 << ' ';
        else cout << a[i] << ' ';
    }
}