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

const int K = 31, MIN = -1000000009;

struct node {
    node *r, *d;
    int x, lev;
    node(int key, int level) : x(key), lev(level), r(NULL), d(NULL) {}
};

node * level[K];

void build() {
    for (int i = K - 1; i >= 0; i--) {
        level[i] = new node(MIN, i);
        if (i < K - 1) {
            level[i + 1]->d = level[i];
        }
    }
}

bool find(node * t, int key) {
    if (t->x == key) {
        return true;
    }
    if (t->r && t->r->x <= key) {
        return find(t->r, key);
    }
    if (t->lev == 0) {
        return false;
    }
    return find(t->d, key);
}


void push(stack<node * > & st, node * t, int key) {
    if (t->r && t->r->x < key) {
        return push(st, t->r, key);
    }
    st.push(t);
    if (t->d) {
        return push(st, t->d, key);
    }
}

void add(int key) {
    stack<node * > st;
    node * t = level[K - 1];
    push(st, t, key);
    node * last = NULL;
    while (st.size()) {
        node * t = st.top();
        st.pop();
        if (t->lev > 0 && !(rand() & 1)) {
            return;
        }
        node * p = new node(key, t->lev);
        p->r = t->r;
        t->r = p;
        if (t->lev > 0) {
            p->d = last;
        }
        last = p;
    }
}

void del(int key) {
    stack<node *> st;
    push(st, level[K - 1], key);
    node * last = NULL;
    while (st.size()) {
        node * t = st.top();
        st.pop();
        node * p = t->r;
        if (p) {
            t->r = p->r;
            delete p;
        }
    }
}

int main() {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("skiplist.in", "r", stdin);
    freopen("skiplist.out", "w", stdout);
#endif
    string s;
    build();
    int x;

    while (cin >> s >> x) {
        if (s == "insert") {
            if (!find(level[K - 1], x)) {
                add(x);
            }
        } else if (s == "exists"){
            if (find(level[K - 1], x)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (s == "delete") {
            if (find(level[K - 1], x)) {
                del(x);
            }
        }
    }
}