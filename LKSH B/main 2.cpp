#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define INF 2000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct Node {
    Node *l, *r;
    int x, y, size;
    Node(int k) : x(k), y(rand()), size(1), l(NULL), r(NULL) {}
};

int size(Node * t) {
    return t ? t->size : 0;
}

void recalc(Node * t) {
    if (!t) return;
    t->size = size(t->l) + size(t->r) + 1;
}

Node ** split(Node *t, int x) {
    if (!t) {
        return new Node * [2] {NULL, NULL};
    }
    Node ** res;
    int sizeleft = size(t->l);
    if (x <= sizeleft) {
        res = split(t->l, x);
        t->l = res[1];
        res[1] = t;
    } else {
        res = split(t->r, x - sizeleft - 1);
        t->r = res[0];
        res[0] = t;
    }
    recalc(res[0]);
    recalc(res[1]);
    return res;
}

Node * merge(Node * l, Node * r) {
    if (!l || !r) {
        return l ? l : r;
    }
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

Node * add(Node * t, Node * p, int x) {
    if (!t) {
        t = p;
        return t;
    }
    if (p->y > t->y) {
        auto k = split(t, x);
        p->l = k[0];
        p->r = k[1];
        t = p;
        recalc(t);
        return t;
    }
    int sizeleft = size(t->l);
    if (x <= sizeleft) {
        t->l = add(t->l, p, x);
        recalc(t->l);
    } else {
        t->r = add(t->r, p, x - sizeleft - 1);
        recalc(t->r);
    }
    recalc(t);
    return t;
}

Node * proc(Node * t, int l, int r) {
    auto k = split(t, r);
    auto a = split(k[0], l - 1);
    k[0] = merge(a[1], a[0]);
    t = merge(k[0], k[1]);
    return t;
}

void out(Node * t) {
    if (!t) return;
    out(t->l);
    cout << t->x << ' ';
    out(t->r);
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("movetofront.in", "r", stdin);
    freopen("movetofront.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    Node * t = NULL;
    for (int i = 0; i < n; i++) {
        int x = i + 1;
        t = add(t, new Node(x), i + 1);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        t = proc(t, l, r);
    }
    out(t);
}