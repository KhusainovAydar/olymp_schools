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
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;

const int NMAX = 200005;

struct node {
    node *l, *r;
    int x;
    vector< pair<int, int> > pref, suff;
    node() : x(0), l(NULL), r(NULL) {}
};

struct segment {
    int l, r;
    int num;
};

pair<int, int> Seg[NMAX];
int n;

void proc(vector<segment> & v, node * t) {
    vector<int> a;
    for (auto i : v) {
        a.pb(i.l);
        a.pb(i.r);
    }
    nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
    int id = (int) (a.size() / 2);
    t->x = a[id];
    vector<segment> left, right;
    for (auto i : v) {
        if (i.r < a[id]) {
            left.pb(i);
        }
        if (i.l > a[id]) {
            right.pb(i);
        }
        if (a[id] >= i.l && a[id] <= i.r) {
            t->pref.pb({i.l, i.num});
            t->suff.pb({i.r, i.num});
        }
    }
    if (left.size()) {
        node * pl = new node();
        proc(left, pl);
        t->l = pl;
    }
    if (right.size()) {
        node * pr = new node();
        proc(right, pr);
        t->r = pr;
    }
    sort(t->pref.begin(), t->pref.end());
    sort(t->suff.rbegin(), t->suff.rend());
}

set<int> ans;

void quest(int x, node * t) {
    if (x == t->x) {
        for (auto i : t->pref) {
            ans.insert(i.se);
        }
        return;
    }
    if (x > t->x) {
        for (auto i : t->suff) {
            if (i.fi >= x) {
                ans.insert(i.se);
            } else {
                break;
            }
        }
        if (t->r)
            quest(x, t->r);
    } else {
        for (auto i : t->pref) {
            if (i.fi <= x) {
                ans.insert(i.se);
            } else {
                break;
            }
        }
        if (t->l)
            quest(x, t->l);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("interval.in", "r", stdin);
    freopen("interval.out", "w", stdout);
#endif
    cin >> n;
    node * t = new node();
    vector<segment> v((unsigned long) n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].num = i + 1;
    }
    proc(v, t);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        ans.clear();
        quest(x, t);
        cout << ans.size() << ' ';
        for (auto a : ans) {
            cout << a << ' ';
        }
        cout << endl;
    }
}