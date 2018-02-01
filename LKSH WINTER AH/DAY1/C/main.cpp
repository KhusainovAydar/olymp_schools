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

using namespace std;

typedef long long ll;

struct Node {
    Node *l, *r;
    int x, y, size;
    Node(int key) : l(NULL), r(NULL), size(1), x(key), y(rand()) {}
};

int getsize(Node * t) {
    return t ? t->size : 0;
}

void recalc(Node * t) {
    if (!t) return;
    t->size = getsize(t->l) + getsize(t->r) + 1;
}

Node ** split(Node * t, int x) {
    if (!t) {
        return new Node * [2] {NULL, NULL};
    }
    Node ** res;
    if (x < t->x) {
        res = split(t->l, x);
        t->l = res[1];
        res[1] = t;
    } else {
        res = split(t->r, x);
        t->r = res[0];
        res[0] = t;
    }
    recalc(res[0]);
    recalc(res[1]);
    return res;
}

Node * merge(Node *l, Node * r) {
    if (!l || !r)
        return l ? l : r;
    Node * res;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        res = l;
    } else {
        r->l = merge(l, r->l);
        res = r;
    }
    recalc(res);
    return res;
}

Node * add(Node * t, Node * p) {
    if (!t) {
        t = p;
        recalc(t);
        return t;
    }
    if (p->y > t->y) {
        auto k = split(t, p->x);
        p->l = k[0];
        p->r = k[1];
        recalc(p);
        t = p;
        recalc(t);
        return t;
    }
    if (p->x < t->x) {
        t->l = add(t->l, p);
    } else {
        t->r = add(t->r, p);
    }
    recalc(t);
    return t;
}

Node * del(Node * t, int x) {
    if (!t)
        return t;
    if (t->x == x) {
        t = merge(t->l, t->r);
        return t;
    }
    if (x < t->x) {
        t->l = del(t->l, x);
    } else {
        t->r = del(t->r, x);
    }
    recalc(t);
    return t;
}


int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("chords.in", "r", stdin);
    freopen("chords.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector< pair<int, int> > a((unsigned long) n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) {
            swap(a[i].fi, a[i].se);
        }
    }
    sort(a.begin(), a.end());
    int last = 1;
    ll ans = 0;
    Node *t = NULL;
    for (int i = 0; i < n; i++) {
        for (int j = last; j <= a[i].fi; j++) {
            t = del(t, j);
        }
        auto k = split(t, a[i].se);
        ans += getsize(k[0]);
        t = merge(k[0], k[1]);
        t = add(t, new Node(a[i].se));
        last = a[i].fi;
    }
    cerr << ans << endl;
    cout << ans;
}