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
    int L, R;
    node() : x(0), l(NULL), r(NULL), L(0), R(0) {}
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
    t->L = 0;
    sort(t->suff.rbegin(), t->suff.rend());
    t->R = 0;
}

set<int> ans;
bool bad[NMAX];

void quest(int x, node * t) {
    if (x == t->x) {
        for (auto i : t->pref) {
            if (!bad[i.se])
                ans.insert(i.se);
            bad[i.se] = 1;
        }
        t->pref.clear();
        t->L = 0, t->R = 0;
        t->suff.clear();
        return;
    }
    if (x > t->x) {
        for (int i = t->R; i < t->suff.size(); i++) {
            auto k = t->suff[i];
            t->R = i;
            if (k.fi >= x && !bad[k.se]) {
                ans.insert(k.se);
                bad[k.se] = 1;
            } else if (k.fi < x) {
                break;
            }
        }
        if (t->r)
            quest(x, t->r);
    } else {
        for (int i = t->L; i < t->pref.size(); i++) {
            auto k = t->pref[i];
            t->L = i;
            if (k.fi <= x && !bad[k.se]) {
                ans.insert(k.se);
                bad[k.se] = 1;
            } else if (k.fi > x) {
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
    freopen("ufo.in", "r", stdin);
    freopen("ufo.out", "w", stdout);
#endif
    cin >> n;
    node * t = new node();
    vector<segment> v((unsigned long) n);
    for (int i = 0; i < n; i++) {
        int lol;
        cin >> v[i].l >> v[i].r >> lol;
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