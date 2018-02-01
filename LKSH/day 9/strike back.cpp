#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

struct Treap {
    Treap *l, *r;
    int x, y, size;
    Treap(int x) : l(NULL), r(NULL), x(x), y(rand()), size(1) {}
};

int get_size(Treap * t) {
    return t ? t->size : 0;
}

void recalc(Treap * t) {
    if (t) {
        t->size = get_size(t->l) + get_size(t->r) + 1;
    }
}

Treap ** split(Treap *t, int x) {
    if (!t)
        return new Treap *[2] {0, 0};
    Treap ** res;
    if (x <= t->x) {
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

Treap * merge(Treap *l, Treap *r) {
    if (!l || !r)
        return l ? l : r;
    Treap * res;
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

Treap * add(Treap * t, Treap * it) {
    if (t == NULL)
    {
        t = it;
        recalc(t);
        return t;
    }
    if (t->y < it->y)
    {
        auto k = split(t, it->x);
        it->l = k[0];
        it->r = k[1];
        t = it;
        recalc(t);
        return t;
    }
    if (t->x < it->x || (t->x == it->x && rand() % 2))
        t->r = add(t->r, it);
    else
        t->l = add(t->l, it);
    recalc(t);
    return t;
}

Treap * remove(Treap *t, int x) {
    if (t == NULL)
    {
        assert(false);
        recalc(t);
        return t;
    }
    if (t->x == x)
    {
        t = merge(t->l, t->r);
        recalc(t);
        return t;
    }
    if (t->x > x)
    {
        t->l = remove(t->l, x);
        recalc(t);
        return t;
    }
    else
    {
        t->r = remove(t->r, x);
        recalc(t);
        return t;
    }
}

void out(Treap *t) {
    if (!t)
        return;
    out(t->l);
    cout << t->x << " ";
    out(t->r);
}

vector<int> a;
vector<Treap *> t;
int n, m;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = NULL;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        t[v] = NULL;
    }
}

void ins(int v, int tl, int tr, int k, int pos) {
    if (tl > tr) return;
    if (tl == tr) {
        t[v] = add(t[v], new Treap(k));
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        ins(2 * v + 1, tl, tm, k, pos);
    } else {
        ins(2 * v + 2, tm + 1, tr, k, pos);
    }
    t[v] = add(t[v], new Treap(k));
}

void ers(int v, int tl, int tr, int k, int pos) {
    if (tl == tr) {
        t[v] = remove(t[v], k);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        ers(2 * v + 1, tl, tm, k, pos);
    } else {
        ers(2 * v + 2, tm + 1, tr, k, pos);
    }
    t[v] = remove(t[v], k);
}

int get_ans(int v, int tl, int tr, int x, int y, int l, int r) {
    if (tl > y || tr < x)
        return 0;
    if (tl >= x && tr <= y) {
        Treap ** raz = split(t[v], l);
        Treap * one = raz[0];
        raz = split(raz[1], r + 1);
        Treap * two = raz[0];
        Treap * three = raz[1];
        int ans;
        if (two == NULL) ans = 0;
        else ans = two->size;
        one = merge(one, two);
        t[v] = merge(one, three);
        return ans;
    } else {
        int tm = (tl + tr) >> 1;
        return get_ans(2 * v + 1, tl, tm, x, y, l, r) +
        get_ans(2 * v + 2, tm + 1, tr, x, y, l, r);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("permutation2.in", "r", stdin);
    freopen("permutation2.out", "w", stdout);
#endif
    int m;
    int n;
    cin >> n >> m;
    a.resize(n);
    t.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    for (int i = 0; i < n; i++) {
        ins(0, 0, n - 1, a[i], i);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int A, B, C, D;
        if (s == "GET") {
            cin >> A >> B >> C >> D;
            cout << get_ans(0, 0, n - 1, A - 1, B - 1, C, D) << endl;
        } else {
            cin >> A >> B;
            ers(0, 0, n - 1, a[A - 1], A - 1);
            ins(0, 0, n - 1 , B, A - 1);
            a[A - 1] = B;
        }
    }
}