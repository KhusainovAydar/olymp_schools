#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll sum = 0;

vector<int> cnt;
void dfs(const vector< vector<int> > & gr, const vector<ll> & Cost, int v) {
    sum += Cost[v];
    for (auto t : gr[v]) {
        cnt[t]--;
    }
    for (auto t : gr[v]) {
        if (cnt[t] == 0) {
            dfs(gr, Cost, t);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll c;
        cin >> n >> c;
        vector< vector<int> > g, gr;
        g.clear(), gr.clear();
        cnt.clear();
        g.resize(n); gr.resize(n);
        vector<ll> Cost((unsigned long) n, 0);
        cnt.resize(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> Cost[i];
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                g[i].pb(x);
                gr[x].pb(i);
            }
        }
        int ans = -1;
        ll minn = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                cnt[j] = (int)g[j].size();
            }
            queue<int> q;
            q.push(i);
            while (q.size()) {
                int v = q.front();
                sum += Cost[v];
                q.pop();
                for (auto t : gr[v]) {
                    cnt[t]--;
                }
                for (auto t : gr[v]) {
                    if (cnt[t] <= 0) {
                        q.push(t);
                    }
                }
            }
            if (sum >= c) {
                if (sum - c <= minn) {
                    minn = sum - c;
                    ans = i;
                }
            }
        }
        cout << ans << endl;
    }
}