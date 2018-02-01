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

struct Treap {
    Treap *l, *r;
    int size;
    int x, y;
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
    int size_left = get_size(t->l);
    Treap ** res;
    if (size_left >= x) {
        res = split(t->l, x);
        t->l = res[1];
        res[1] = t;
    }
    else {
        res = split(t->r, x - size_left - 1);
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

Treap * add(Treap * t, int key) {
    Treap ** a = split(t, key);
    a[0] = merge(a[0], new Treap(key));
    Treap * res = merge(a[0], a[1]);
    return res;
}

Treap * remove(Treap *t, int x) {
    Treap ** a = split(t, x);
    Treap ** b = split(a[0], x - 1);
    Treap * res = merge(b[0], a[1]);
    return res;
}

void out(Treap *t) {
    if (!t)
        return;
    out(t->l);
    cout << t->x << " ";
    out(t->r);
}

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("movetofront.in", "r", stdin);
    freopen("movetofront.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    Treap * a = NULL;
    for (int i = 1; i <= n; i++) {
        a = add(a, i);
    }
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        left--;
        Treap *A, *B, *C;
        auto tmp = split(a, right);
        A = tmp[0];
        C = tmp[1];
        tmp = split(A, left);
        A = tmp[0];
        B = tmp[1];
        a = merge(B, A);
        a = merge(a, C);
    }
    out(a);
}