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

const int NMAX = (const int) (5e4 + 5), INF = 10000000;

struct Point {
    ll x, y;
    void init() {
        cin >> x >> y;
    }
    Point(ll X, ll Y) : x(X), y(Y) {}
};

struct Line {
    ll a, b, c;
    void init(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = (A.y - B.y) * A.x + (B.x - A.x) * A.y;
    }
};

struct segment {
    ll x[2], y[2];
    int num;
};

struct node {
    node *l, *r;
    int L, R;
    vector<segment> v;
    node() : l(NULL), r(NULL) {}
};

segment segments[NMAX];

vector<node *> a;

void build(node * t, int tl, int tr) {
    if (tl == tr) {
        if (a[tl]->L != a[tl]->R) {
            a[tl]->L++;
            a[tl]->R--;
        }
        t->L = a[tl]->L;
        t->R = a[tr]->R;
    } else {
        int tm = (tl + tr) >> 1;
        t->l = new node();
        t->r = new node();
        build(t->l, tl, tm);
        build(t->r, tm + 1, tr);
        t->L = t->l->L;
        t->R = t->r->R;
    }
}

void add(node * t, segment & seg) {
    if (!t || t->R < seg.x[0] || t->L > seg.x[1])
        return;
    if (t->L >= seg.x[0] && t->R <= seg.x[1]) {
//        cerr << "otr  " << seg.x[0] << ' ' << seg.x[1] << endl;
        t->v.pb(seg);
        return;
    }
    add(t->l, seg);
    add(t->r, seg);
}

int n;

ll X_mid;

bool cmp(segment a, segment b) {
    Line AB, BA;
    AB.init(Point(a.x[0], a.y[0]), Point(a.x[1], a.y[1]));
    BA.init(Point(b.x[0], b.y[0]), Point(b.x[1], b.y[1]));
    ll y[2];
    y[0] = -(AB.a * X_mid + AB.c) * BA.b;
    y[1] = -(BA.a * X_mid + BA.c) * AB.b;
    if (AB.b < 0 && BA.b < 0) {
        return y[0] < y[1];
    }
    if (AB.b < 0 || BA.b < 0) {
        return y[1] < y[0];
    }
    return y[0] < y[1];
}


bool check;


void build_all(node * t) {
    if (!t)
        return;
    X_mid = t->L;
    sort(t->v.begin(), t->v.end(), cmp);
//    if (t->v.size() && check) {
//        cerr << t->L << ' ' << t->R << endl;
//        for (auto q : t->v) {
//            cerr << q.num << ' ';
//        }
//        cerr << endl << endl;
//    }
    build_all(t->l);
    build_all(t->r);
}

unordered_set<int> ans;

void find_the_ans(node * t, segment & s) {
    if (!t || t->L > s.x[1] || t->R < s.x[0]) {
        return;
    }
    ll A = min(s.y[0], s.y[1]);
    ll B = max(s.y[0], s.y[1]);
    ll y[] = {A, B};
    int L = -1, R = (int) t->v.size() - 1;
    X_mid = s.x[0];
    while (R - L > 1) {
        int M = (L + R) >> 1;
        segment a = t->v[M];
        Line AB;
        Point p1(a.x[0], a.y[0]), p2(a.x[1], a.y[1]);
        AB.init(Point(a.x[0], a.y[0]), Point(a.x[1], a.y[1]));
        ll Y = -(AB.a * X_mid + AB.c);
        if (AB.b < 0) {
            if (Y <= y[0] * AB.b) {
                R = M;
            } else {
                L = M;
            }
        } else {
            if (Y >= y[0] * AB.b) {
                R = M;
            } else {
                L = M;
            }
        }
    }
    while (R < t->v.size() && R >= 0) {
        segment a = t->v[R];
        Line AB;
        Point p1(a.x[0], a.y[0]), p2(a.x[1], a.y[1]);
        AB.init(p1, p2);
        ll Y = -(AB.a * X_mid + AB.c);
        ll kek[2] = {y[0] * AB.b, y[1] * AB.b};
        if (AB.b < 0) {
            if (Y <= kek[0] && Y >= kek[1]) {
                ans.insert(t->v[R].num);
            }
        } else {
            if (Y >= kek[0] && Y <= kek[1]) {
                ans.insert(t->v[R].num);
            }
        }
        R++;
    }
    find_the_ans(t->l, s);
    find_the_ans(t->r, s);
}

node * tx = NULL;
node * ty = NULL;

void build_segments(bool x) {
    set<ll> unical;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (x) {
                unical.insert(segments[i].x[j]);
            } else {
                unical.insert(segments[i].y[j]);
            }
        }
        segments[i].num = i + 1;
    }

    vector<ll> X;
    X.pb(-INF);
    for (auto t : unical) {
        X.pb(t);
    }

    a.clear();

    X.pb(INF);
    for (int i = 1; i < (int)X.size(); i++) {
        node * p = new node;
        p->L = X[i - 1];
        p->l = NULL;
        p->r = NULL;
        p->R = X[i];
        a.pb(p);
        if (X[i] == X.back()) continue;
        p = new node;
        p->L = X[i];
        p->l = NULL;
        p->r = NULL;
        p->R = X[i];
        a.pb(p);
    }
    if (x) {
        tx = new node();
        size_t sz = a.size();

        build(tx, 0, (int) (sz - 1));
        for (int i = 0; i < n; i++) {
            add(tx, segments[i]);
        }

        build_all(tx);
    } else {
        ty = new node();
        size_t sz = a.size();
//        for (auto t : a) {
//            cerr << '[' << t->L << ' ' << t->R << ']' << ' ';
//        }
        build(ty, 0, (int) (sz - 1));
        for (int i = 0; i < n; i++) {
            segment seg = segments[i];
            for (int j = 0; j < 2; j++) {
                swap(seg.x[j], seg.y[j]);
            }
            if (seg.x[0] > seg.x[1]) {
                swap(seg.x[0], seg.x[1]);
                swap(seg.y[0], seg.y[1]);
            }
            add(ty, seg);
        }
        check = 1;
        build_all(ty);
    }
}

vector< pair<int, int> > tree[16 * NMAX];

void build_tree(int v, int tl, int tr, const vector< vector< pair<int, int> > > & pos) {
    if (tl == tr) {
        for (auto t : pos[tl]) {
            tree[v].pb(t);
        }
        sort(tree[v].begin(), tree[v].end());
    } else {
        int tm = (tl + tr) >> 1;
        build_tree(2 * v + 1, tl, tm, pos);
        build_tree(2 * v + 2, tm + 1, tr, pos);
        int pos1 = 0, pos2 = 0;
        while (pos1 < tree[2 * v + 1].size() && pos2 < tree[2 * v + 2].size()) {
            if (tree[2 * v + 1][pos1] < tree[2 * v + 2][pos2]) {
                tree[v].pb(tree[2 * v + 1][pos1]);
                pos1++;
            } else {
                tree[v].pb(tree[2 * v + 2][pos2]);
                pos2++;
            }
        }
        while (pos1 < tree[2 * v + 1].size()) {
            tree[v].pb(tree[2 * v + 1][pos1]);
            pos1++;
        }
        while (pos2 < tree[2 * v + 2].size()) {
            tree[v].pb(tree[2 * v + 2][pos2]);
            pos2++;
        }
    }
}

void find_the_ans_in(int v, int tl, int tr, int l, int r, int ymin, int ymax) {
    if (l > r || l > tr || r < tl || tl > tr) return;
    if (tl == tr) {
        pair<int, int> sear = {ymin, 0};
        int id = int(lower_bound(tree[v].begin(), tree[v].end(), sear) - tree[v].begin());
        while (id < tree[v].size() && tree[v][id].fi >= ymin && tree[v][id].fi <= ymax) {
            ans.insert(tree[v][id].se);
            id++;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    find_the_ans_in(2 * v + 1, tl, tm, l, min(r, tm), ymin, ymax);
    find_the_ans_in(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, ymin, ymax);
}

int mp[2000050], pm[2000050];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("src.in", "r", stdin);
    freopen("src.out", "w", stdout);
#endif
    cin >> n;
    vector<ll> X;
    vector< vector< pair<int, int> > > pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> segments[i].x[j] >> segments[i].y[j];
            X.pb(segments[i].x[j]);
        }
        if (segments[i].x[0] > segments[i].x[1]) {
            swap(segments[i].x[0], segments[i].x[1]);
            swap(segments[i].y[0], segments[i].y[1]);
        }
        segments[i].num = i + 1;
    }

    int cur = 1;
    sort(X.begin(), X.end());
    for (auto i : X) {
        if (mp[i + 1000005]) {
            continue;
        }
        mp[i + 1000005] = cur;
        pm[cur] = i;
        cur++;
    }

    pos.resize((unsigned long) (cur + 5));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pos[mp[segments[i].x[j] + 1000005]].pb({segments[i].y[j], i + 1});
        }
    }

    build_tree(0, 0, cur - 1, pos);

    for (int i = 1; i >= 0; i--) {
        build_segments((bool) i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x[4], y[4];
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        segment seg[4];
        ans.clear();
        for (int j = 0; j < 2; j++) {
            for (int t = 0; t < 2; t++) {
                seg[j].x[t] = x[j];
                seg[j].y[t] = y[t];
            }
        }
        for (int j = 0; j < 2; j++) {
            for (int t = 0; t < 2; t++) {
                seg[2 + j].x[t] = y[j];
                seg[2 + j].y[t] = x[t];
            }
        }
        for (int j = 0; j < 2; j++) {
            find_the_ans(tx, seg[j]);
        }
        for (int j = 2; j < 3; j++) {
            find_the_ans(ty, seg[j]);
        }
        int L = -1, R = cur - 1;
        int xmin = min(x[0], x[1]), xmax = max(x[0], x[1]);
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (pm[M] >= xmin) {
                R = M;
            } else {
                L = M;
            }
        }
        xmin = R;
        L = 0, R = cur;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (pm[M] <= xmax) {
                L = M;
            } else {
                R = M;
            }
        }
        xmax = L;
        find_the_ans_in(0, 0, cur - 1, xmin, xmax, min(y[0], y[1]), max(y[0], y[1]));
        cout << ans.size() << ' ';
        for (auto t : ans) {
            cout << t << ' ';
        }
        cout << endl;
    }
    cerr << "KEK";
}