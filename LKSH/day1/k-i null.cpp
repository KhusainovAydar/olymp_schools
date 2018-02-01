#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 200005;

int a[NMAX], t[4 * NMAX];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (a[tl] == 0) {
            t[v] = 1;
        } else t[v] = 0;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

int _sum(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    }
    if (l > r) return 0;
    int tm = (tl + tr) >> 1;
    return _sum(2 * v + 1 , tl, tm, l, min(r, tm)) + 
            _sum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        if (val == 0) {
            t[v] = 1;
        } else {
            t[v] = 0;
        }
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            upd(2 * v + 1, tl, tm, pos, val);
        } else {
            upd(2 * v + 2, tm + 1, tr, pos, val);
        }
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

int getind(int v, int tl, int tr, int k) {
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (t[2 * v + 1] >= k) return getind(2 * v + 1, tl, tm, k);
    else return getind(2 * v + 2, tm + 1, tr, k - t[2 * v + 1]);
}


int n;

int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}

char get() {
    char c = getchar();
    while (c <= 32) c = getchar();
    return c;
}

int main() {
    //ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("kthzero.in", "r", stdin); 
        freopen("kthzero.out", "w", stdout);
    #endif
    int m;
    n = getint();
    for (int i = 0; i < n; i++) {
        a[i] = getint();
    }
    build(0, 0, n - 1);
    m = getint();
    for (int i = 0; i < m; i++) {
        char c = get();
        if (c == 'u') {
            int pos, val;
            pos = getint(); val = getint();
            upd(0, 0, n - 1, pos - 1, val);
        } else {
            int l = getint(), r = getint(), k = getint();
            if (_sum(0, 0, n - 1, l - 1, r - 1) < k) puts("-1");
            else {
                l--; 
                r--;
                if (l > 0) k += _sum(0, 0, n - 1, 0, l - 1);
                cout << getind(0, 0, n - 1, k) + 1 << endl; 
            }
        }
    }
}