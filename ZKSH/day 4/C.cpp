#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
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

const int MaskMAX = (1 << 20);
const int NMAX = 21;
const int INF = 1000000000;

int edges[MaskMAX], dp[MaskMAX], par[MaskMAX];
bool used[MaskMAX];
vector<int> g[NMAX];
int nmask;
int n, m;

void build() {
    for (int i = 0; i < nmask; i++) {
        int mask1 = i, mask2 = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                for (int p = 0; p < g[j].size(); p++) {
                    int to = g[j][p];
                    mask2 |= (1 << to);
                }
            }
        }
        edges[mask1] = mask2;
    }
    for (int i = 0; i < nmask; i++) {
        dp[i] = INF;
    }
    dp[(1 << n) - 1] = 0;
}


int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    cin >> n >> m;
    nmask = (1 << n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
    }
    build();
    queue<int> q;
    q.push(nmask - 1);
    used[nmask - 1] = 1;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if ((v >> i) & 1) {
                int mask1 = v, mask2 = (v ^ (1 << i));
                int go = edges[mask2];
                if (dp[mask1] + 1 < dp[go] && !used[go]) {
                    used[go] = 1;
                    dp[go] = dp[mask1] + 1;
                    par[go] = mask1;
                    q.push(go);
                }
            }
        }
    }

    if (dp[0] == INF) {
        cout << "No solution";
        return 0;
    }

    int mask = 0;
    nmask = (1 << n) - 1;
    vector<int> ans;
    while (mask != nmask) {
        int pr = par[mask];
        for (int i = 0; i < n; i++) {
            if ((pr >> i) & 1) {
                int go = (pr ^ (1 << i));
                if (edges[go] == mask && dp[mask] == dp[pr] + 1) {
                    ans.pb(i + 1);
                    break;
                }
            }
        }
        mask = pr;
    }
    cout << dp[0] << endl;

    reverse(all(ans));
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
