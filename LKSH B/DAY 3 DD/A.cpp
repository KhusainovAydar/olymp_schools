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
    Node *l, *r;
    int x, size, y;
    Node(int key) : l(NULL), r(NULL), size(1), x(key), y(rand()) {}
};

int getsize(Node * t) {
    if (t)
        return t->size;
    return 0;
}

void recalc(Node *t) {
    if (t) {
        t->size = getsize(t->l) + getsize(t->r) + 1;
    }
}

Node ** split(Node *t, int x) {
    if (!t) {
        return new Node * [2] {NULL, NULL};
    }
    int sizeleft = getsize(t->l);
    Node ** res;
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

Node * merge(Node *l, Node *r) {
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

Node * add(Node * t, int key) {
    Node ** a = split(t, key);
    a[0] = merge(a[0], new Node(key));
    Node * res = merge(a[0], a[1]);
    return res;
}

void out(Node * t) {
    if (!t)
        return;
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
    Node * t = NULL;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        t = add(t, i);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        auto k = split(t, r);
        auto a = split(k[0], l - 1);
        k[0] = merge(a[1], a[0]);
        t = merge(k[0], k[1]);
    }
    out(t);
}