#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1e5 + 5;

int p[NMAX];

int get_dsu(int v) {
    return (v == p[v]) ? v : (p[v] = get_dsu(p[v]));
}

void unite(int a, int b) {
    a = get_dsu(a);
    b = get_dsu(b);
    if (rand() % 1)
        swap(a, b);
    if (a != b) {
        p[a] = b;
    }
}

int n, m;

void verybad(int q) {
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << "NO" << endl;
    }
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
    /*#if __APPLE__
     freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
     freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
     #else
     freopen("trie.in", "r", stdin);
     freopen("trie.out", "w", stdout);
     #endif*/
    int quest;
    cin >> n >> m >> quest;
    vector< pair<int, pair<int, int> > > g;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g.push_back({c, {a, b}});
    }
    int cost = 0;
    vector< pair<int, int> > res;
    sort(g.begin(), g.end());
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a = g[i].se.fi, b = g[i].se.se, l = g[i].fi;
        if (get_dsu(a) != get_dsu(b)) {
            cost += l;
            res.push_back({a, b});
            unite(a, b);
        }
    }
    int black1 = cost;
    cost = 0;
    res.clear();
    sort(g.rbegin(), g.rend());
    for (int i = 1; i < n; i++) {
        if (get_dsu(i) != get_dsu(i - 1)) {
            verybad(quest);
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a = g[i].se.fi, b = g[i].se.se, l = g[i].fi;
        if (get_dsu(a) != get_dsu(b)) {
            cost += l;
            res.push_back({a, b});
            unite(a, b);
        }
    }
    int black2 = cost;
    for (int i = 1; i < n; i++) {
        if (get_dsu(i) != get_dsu(i - 1)) {
            verybad(quest);
            return 0;
        }
    }
    for (int i = 0; i < quest; i++) {
        int a;
        cin >> a;
        if (n - a - 1 >= black1 && n - a - 1 <= black2) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
}