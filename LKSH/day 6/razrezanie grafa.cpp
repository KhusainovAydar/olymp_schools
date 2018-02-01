#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

inline string get_str() {
    char c = getchar();
    while (c < 31) c = getchar();
    string s = "";
    while (c >= 32) {
        s += c;
        c = getchar();
    }
    return s;
}

inline int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}


const int NMAX = 1e5 + 5;
int par[NMAX], rang[NMAX];

void make_set(int v) {
    par[v] = v;
    rang[v] = 0;
}

int find_set(int v) {
    return (v == par[v]) ? v : (par[v] = find_set(par[v]));
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b]) swap(a, b);
        par[b] = a;
        if (rang[a] == rang[b])
            rang[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("cutting.in", "r", stdin);
    freopen("cutting.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }
    vector< pair<string, pair<int, int> > > v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i].fi >> v[i].se.fi >> v[i].se.se;
    }
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    reverse(v.begin(), v.end());
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        //cout << v[i].fi << ' ' << v[i].se.fi << ' ' << v[i].se.se << endl;
        if (v[i].fi == "ask") {
            if (find_set(v[i].se.fi) == find_set(v[i].se.se)) {
                ans.pb("YES");
            } else ans.pb("NO");
        } else {
            union_sets(v[i].se.fi, v[i].se.se);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}