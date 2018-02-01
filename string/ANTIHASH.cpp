#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

typedef long long ll;
typedef long double dbl;

inline ll mul( ll a, ll b, ll mod ) {
    ll k = (dbl)a * b / mod;
    ll r = a * b - k * mod;
    while (r < 0) r += mod;
    while (r >= mod) r -= mod;
    return r;
}

struct tree {
    ll val;
    tree *l, *r;

    tree( ll _val, tree *_l, tree *_r ) : val(_val), l(_l), r(_r) { }
};

typedef tree * ptree;

struct TreeComp
{
    bool operator () ( const ptree &a, const ptree &b ) {
        return a->val < b->val;
    }
};

const int N = 10000;

int an;
tree *a[N];
char s[N + 1], t[N + 1];

void result( tree *a, int f ) {
    if (!a->r) {
        int i = (int)(a->l);
        (f ? s : t)[N - i - 1]++;
        return;
    }
    int swap = (a->l->val < a->r->val);
    result(a->l, f ^ swap);
    result(a->r, f ^ swap ^ 1);
}

int main() {
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("servers.in", "r", stdin); 
        freopen("servers.out", "w", stdout);
    #endif
    ll p, q;
    cin >> p >> q;

    ll f = 1;
    forn(i, N)
    a[an++] = new tree(f, (tree *)i, 0), f = mul(f, p, q);
    while (an) {
        sort(a, a + an, TreeComp());
        if (a[0]->val == 0) {
            forn(i, N)
            s[i] = t[i] = 'a';
            result(a[0], 0);
            puts(s);
            puts(t);
            return 0;
        }
        forn(i, an / 2)
            a[i] = new tree(abs(a[2 * i]->val - a[2 * i + 1]->val), a[2 * i], a[2 * i + 1]);
        an /= 2;
    }
    puts("Impossible");
    return 0;
}
