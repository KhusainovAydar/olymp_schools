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
    Node *l, *r, *fat;
    int num, x, y;
    Node(int key, int prior, int id) : l(NULL), r(NULL), num(id), x(key), fat(NULL), y(prior) {}
};

Node ** split(Node * t, int x) {
    if (!t)
        return new Node * [2] {NULL, NULL};
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
    return res;
}

Node * merge(Node *l, Node *r) {
    if (!l || !r) return l == NULL ? r : l;
    Node * res;
    if (l->y < r->y) {
        l->r = merge(l->r, r);
        res = l;
    } else {
        r->l = merge(l, r->l);
        res = r;
    }
    return res;
}

Node * add(Node * t, Node * p) {
    if (!t) {
        t = p;
        return t;
    }
    if (t->y > p->y) {
        auto k = split(t, p->x);
        p->l = k[0];
        p->r = k[1];
        t = p;
        return t;
    }
    if (t->x > p->x) {
        t->l = add(t->l, p);
    } else {
        t->r = add(t->r, p);
    }
    return t;
}

int num(Node * t) {
    if (t)
        return t->num;
    else
        return 0;
}

struct ANS {
    int pred, l, r;
};

ANS ans[50005];;

void out(Node * t) {
    if (!t) return;
    if (t->l) {
        int pred = t->num;
        int left = 0;
        if (t->l->l) {
            left = t->l->l->num;
        }
        int right = 0;
        if (t->l->r) {
            right = t->l->r->num;
        }
        ANS k;
        k.pred = pred;
        k.l = left;
        k.r = right;
        ans[t->l->num] = k;
        out(t->l);
    }
    if (t->r) {
        ANS k;
        k.pred = t->num;
        k.l = 0;
        if (t->r->l) {
            k.l = t->r->l->num;
        }
        k.r = 0;
        if (t->r->r) {
            k.r = t->r->r->num;
        }
        ans[t->r->num] = k;
        out(t->r);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    Node * t = NULL;
    vector< pair< pair<int, int>, int> > v;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({{a, b}, i + 1});
        //cout << a << ' ' << b << endl;
        //t = add(t, new Node(a, b, i + 1));
    }
    sort(v.begin(), v.end());
    Node * last = new Node(v[0].fi.fi, v[0].fi.se, v[0].se);
    for (int i = 1; i < n; i++) {
        Node * k = new Node(v[i].fi.fi, v[i].fi.se, v[i].se);
        if (k->y > last->y) {
            k->fat = last;
            last->r = k;
            last = last->r;
        } else {
            Node * cur = last;
            while (cur->fat && k->y < cur->y)
                cur = cur->fat;
            if (k->y < cur->y) {
                k->l = cur;
                last = k;
            } else {
                k->l = cur->r;
                k->r = NULL;
                k->fat = cur;
                last = k;
                cur->r = last;
            }
        }
    }
    while (last->fat)
        last = last->fat;
    t = last;
    printf("YES\n");
    ANS k;
    k.pred = 0;
    k.l = 0;
    k.r = 0;
    if (t->l)
        k.l = t->l->num;
    if (t->r)
        k.r = t->r->num;
    ans[t->num] = k;
    out(t);
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", ans[i].pred, ans[i].l, ans[i].r);
    }
}