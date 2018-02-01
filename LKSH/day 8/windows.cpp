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

struct Scan {
    int x, y1, y2, val;
    void init(int _x, int _y1, int _y2, int _val) {
        x = _x;
        y1 = _y1;
        y2 = _y2;
        val = _val;
    }
};

vector<ll> t, tmax;
bool cmp(Scan a, Scan b) {
    if (a.x == b.x) {
        return a.val < b.val;
    }
    return a.x < b.x;
}

void push(int v) {
    tmax[2 * v + 1] += t[v];
    tmax[2 * v + 2] += t[v];
    t[2 * v + 1] += t[v];
    t[2 * v + 2] += t[v];
    t[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (tl == l && tr == r) {
        tmax[v] += val;
        t[v] += val;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        add(2 * v + 1, tl, tm, l, min(tm, r), val);
        add(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val);
        tmax[v] = max(tmax[2 * v + 1], tmax[2 * v + 2]);
    }
}

ll Get(int v, int tl, int tr, int l = 0, int r = 2000000 - 1) {
    if (tl == l && tr == r) {
        return tmax[v];
    }
    int tm = (tl + tr) >> 1;
    push(v);
    return max(Get(2 * v + 1, tl, tm, l, min(tm, r)),
               Get(2 * v + 2, tm + 1, tr, max(l, tm + 1), r));
}

ll Id(int v, int tl, int tr, ll val) {
    if (tl == tr)
        return tl;
    else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (tmax[2 * v + 1] == val)
            return Id(2 * v + 1, tl, tm, val);
        else return Id(2 * v + 2, tm + 1, tr, val);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("windows.in", "r", stdin);
    freopen("windows.out", "w", stdout);
#endif*/
    int n;
    cin >> n;
    vector<Scan> a;
    t.resize(8000000, 0);
    tmax.resize(8000000, 0);
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Scan D;
        y1 += 1000000;
        y2 += 1000000;
        D.init(x1, y1, y2, 1);
        a.push_back(D);
        D.init(x2 + 1, y1, y2, -1);
        a.push_back(D);
    }
    sort(a.begin(), a.end(), cmp);
    //cout << "LOL";
    pair<ll, pair<ll, ll> > ans = {-1, {-1, -1}};
    for (int i = 0; i < (int)a.size(); i++) {
        add(0, 0, 2000000 - 1, a[i].y1, a[i].y2, a[i].val);
        ll res = Get(0, 0, 2000000 - 1);
        //cout << res << endl;
        if (res > ans.fi) {
            ans.fi = res;
            ans.se.fi = a[i].x;
            ans.se.se = Id(0, 0, 2000000 - 1, res);
        }
    }
    cout << ans.fi << endl;
    cout << ans.se.fi << ' ' << ans.se.se - 1000000;
}