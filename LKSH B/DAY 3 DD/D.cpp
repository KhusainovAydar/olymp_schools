#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 10000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)

using namespace std;

typedef long long ll;

struct Node {
    Node *l, *r;
    ll x, y, sum;
    Node(ll key) : l(NULL), r(NULL), x(key), sum(key), y(rand()) {}
};

ll sum(Node * t) {
    if (t)
        return t->sum;
    else
        return 0;
}

void recalc(Node * t) {
    if (t)
        t->sum = sum(t->l) + sum(t->r) + t->x;
}

Node * merge(Node * l, Node * r) {
    if (!l || !r)
        return l == NULL ? r : l;
    Node * res;
    recalc(l);
    recalc(r);
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        recalc(l->r);
        res = l;
    } else {
        r->l = merge(l, r->l);
        recalc(r->l);
        res = r;
    }
    recalc(res);
    return res;
}

Node ** split(Node * t, ll x) {
    if (!t)
        return new Node * [2] {NULL, NULL};
    recalc(t);
    Node ** res;
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

Node * add(Node * t, Node * p) {
    if (!t) {
        t = p;
        return t;
    }
    recalc(t);
    recalc(p);
    if (t->y < p->y) {
        auto k = split(t, p->x);
        p->l = k[0];
        p->r = k[1];
        t = p;
        recalc(t);
        return t;
    }
    if (t->x >= p->x) {
        t->l = add(t->l, p);
        recalc(t->l);
    } else {
        t->r = add(t->r, p);
        recalc(t->r);
    }
    recalc(t);
    return t;
}

ll ans(Node *t, int l, int r) {
    recalc(t);
    auto a = split(t, l);
    auto b = split(a[1], r + 1);
    ll kek = sum(b[0]);
    t = merge(a[0], merge(b[0], b[1]));
    recalc(t);
    return kek;
}

bool find(Node * t, ll x) {
    if (!t) return false;
    if (t->x == x) {
        return true;
    }
    if (t->x > x) {
        return find(t->l, x);
    } else {
        return find(t->r, x);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
#endif
    int n;
    cin >> n;
    ll z = -1;
    Node * t = NULL;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            ll x;
            cin >> x;
            if (z != -1) {
                x += z;
                x %= 1000000000;
                z = -1;
            }
            if (!find(t, x)) {
                t = add(t, new Node(x));
                //cout << "+" << x << endl;
            }
        } else {
            int l, r;
            cin >> l >> r;
            z = ans(t, l, r);
            cout << z << endl;
        }
    }
}