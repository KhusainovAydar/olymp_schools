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
    int x, size, y;
    Node(int key) : l(NULL), r(NULL), x(key), size(1), y(rand()) {}
};

int get_size(Node *t) {
    return t ? t->size : 0;
}

void recalc(Node *t) {
    if (t)
        t->size = get_size(t->l) + get_size(t->r) + 1;
}

Node ** split(Node * t, int x) {
    if (!t)
        return new Node *[2] {NULL, NULL};
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
    if (!l || !r) return l == NULL ? r : l;
    Node * res;
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

Node * add(Node * t, Node *p) {
    if (!t) {
        t = p;
        return t;
    }
    if (t->y < p->y) {
        auto k = split(t, p->x);
        p->l = k[0];
        p->r = k[1];
        t = p;
        recalc(t);
        return t;
    }
    if (t->x < p->x || (t->x == p->x && rand() % 2)) {
        t->r = add(t->r, p);
        recalc(t->r);
    } else {
        t->l = add(t->l, p);
        recalc(t->l);
    }
    recalc(t);
    return t;
}

Node * remove(Node *t, int x) {
    if (!t) return t;
    if (t->x == x) {
        t = merge(t->l, t->r);
        recalc(t);
        return t;
    }
    if (x < t->x) {
        t->l = remove(t->l, x);
        recalc(t->l);
    } else {
        t->r = remove(t->r, x);
        recalc(t->r);
    }
    recalc(t);
    return t;
}

bool check(Node * t, int x) {
    if (!t) return false;
    if (t->x == x) return true;
    if (x < t->x) {
        return check(t->l, x);
    } else {
        return check(t->r, x);
    }
}

int kth(Node *t, int k) {
    if (!t) return -1;
    int size_left = get_size(t->l);
    if (size_left > k - 1) {
        return kth(t->l, k);
    }
    if (size_left == k - 1) {
        return t->x;
    }
    return kth(t->r, k - size_left - 1);
}

int next(Node * t, int x) {
    if (!t) return INT_MAX;
    if (x < t->x) {
        return min(t->x, next(t->l, x));
    } else {
        return next(t->r, x);
    }
}

int prev(Node *t, int x) {
    if (!t) return INT_MIN;
    if (x < t->x) {
        return prev(t->l, x);
    } else {
        return max(t->x, prev(t->r, x));
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
    freopen("bst2.in", "r", stdin);
    freopen("bst2.out", "w", stdout);
#endif
    string s;
    int x;
    Node * t = NULL;
    while (cin >> s >> x) {
        if (s == "insert") {
            if (!check(t, x))
                t = add(t, new Node(x));
        } else if (s == "delete") {
            if (check(t, x)) {
                t = remove(t, x);
            }
        } else if (s == "exists") {
            cout << boolalpha << check(t, x) << endl;
        } else if (s == "kth") {
            int ans = kth(t, x);
            if (ans == -1) {
                cout << "none" << endl;
            } else {
                cout << ans << endl;
            }
        } else if (s == "next") {
            int ans = next(t, x);
            if (ans == INT_MAX) {
                cout << "none";
            } else {
                cout << ans;
            }
            cout << endl;
        } else if (s == "prev") {
            int ans = prev(t, x);
            if (ans == INT_MIN) {
                cout << "none";
            } else {
                cout << ans;
            }
            cout << endl;
        }
    }
}