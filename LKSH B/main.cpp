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

using namespace std;

typedef long long ll;

struct Node {
    Node *l, *r;
    int pref, suf, x, y, all;
    int sum;
    Node (int key) : l(NULL), r(NULL), x(key), y(rand()), sum(max(key, 0)), all(key), pref(key), suf(key){}
};

int pref(Node *t) {
    if (t) {
        return t->pref;
    } else {
        return -100000;
    }
}

int all(Node *t) {
    if (t) {
        return t->all;
    } else {
        return 0;
    }
}

int sum(Node *t) {
    if (t) {
        return t->sum;
    } else {
        return 0;
    }
}

int suf(Node *t) {
    if (t) {
        return t->suf;
    } else {
        return -100000;
    }
}

void recalc(Node *t) {
    if (!t) {
        return;
    }
    t->pref = max(all(t->l) + pref(t->r) + t->x, pref(t->l));
    t->suf = max(suf(t->r), all(t->r) + suf(t->l) + t->x);
    t->sum = max({sum(t->l), suf(t->l) + pref(t->r) + t->x, sum(t->r)});
    t->all = all(t->l) + all(t->r) + t->x;
}

Node ** split(Node *t, int x) {
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

Node * merge(Node *l, Node *r) {
    if (!l || !r)
        return l == NULL ? r : l;
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

Node * add(Node *t, Node *p) {
    if (!t) {
        t = p;
        return t;
    }
    if (p->y > t->y) {
        auto k = split(t, p->x);
        p->l = k[0];
        p->r = k[1];
        t = p;
        return t;
    }
    if (p->x < t->x) {
        t->l = add(t->l, p);
        recalc(t->l);
    } else {
        t->r = add(t->r, p);
        recalc(t->r);
    }
    return t;
}

Node * remove(Node *t, int x) {
    if (!t) {
        assert(false);
        return t;
    }
    if (x < t->x) {
        t->l = remove(t->l, x);
        recalc(t);
    } else {
        t->r = remove(t->r, x);
    }
    return t;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#if __APPLE__
//    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
//    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
//#else
//    freopen("log.in", "r", stdin);
//    freopen("log.out", "w", stdout);
//#endif
    Node * t = NULL;
    char c;
    int n;
    while (cin >> c >> n) {
        if (c == '+') {
            t = add(t, new Node(n));
            cout << "OK" << endl;
        } else if (c == '-') {
            t = remove(t, n);
            cout << "OK" << endl;
        } else if (c == '?') {
            cout << t->sum << endl;
        }
    }
}