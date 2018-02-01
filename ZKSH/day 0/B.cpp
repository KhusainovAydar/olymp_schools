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

int n, m;
int cnt2, cnt1;
const int NMAX = 404;
int color[NMAX];
vector<int> g[NMAX];
bool used[NMAX];
bool dp[NMAX][NMAX][NMAX];

struct node {
    int start, cur1, cur2;
};

void dfs(int v) {
    used[v] = 1;
    for (auto t : g[v]) {
        if (color[v] == color[t]) {
            cout << "impossible";
            exit(0);
        }
        if (color[t] == 0) {
            color[t] = 3 - color[v];
            if (color[t] == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
            dfs(t);
        }
    }
}

vector< node > v;

string proc(int x, int pos1, int pos2) {
    memset(color, 0, sizeof(color));
    while (x > 0) {
        if (pos1 >= v[x - 1].cur1 && pos2 >= v[x - 1].cur2) {
            if (dp[x - 1][pos1 - v[x - 1].cur1][pos2 - v[x - 1].cur2]) {
                x--;
                color[v[x].start] = 1;
                dfs(v[x].start);
                pos1 -= v[x].cur1;
                pos2 -= v[x].cur2;
                continue;
            }
        }
        if (pos2 >= v[x - 1].cur1 && pos1 >= v[x - 1].cur2) {
            if (dp[x - 1][pos1 - v[x - 1].cur2][pos2 - v[x - 1].cur1]) {
                x--;
                color[v[x].start] = 2;
                dfs(v[x].start);
                pos1 -= v[x].cur2;
                pos2 -= v[x].cur1;
                continue;
            }
        }
        assert(false);
    }

    string s = "";
    for (int i = 0; i < n; i++) {
        if (color[i] == 1) {
            s += 'A';
        } else {
            s += 'B';
        }
    }

    return s;
}
int main() {
//    srand((unsigned ll)time(NULL));
//    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            cnt1 = 0, cnt2 = 0;
            color[i] = 1;
            cnt1 = 1;
            dfs(i);
            v.pb({i, cnt1, cnt2});
        }
    }
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }

    reverse(all(v));

    for (int i = 0; i < v.size(); i++) {
        for (int cur1 = 0; cur1 <= n; cur1++) {
            for (int cur2 = 0; cur2 <= n; cur2++) {
                if (!dp[i][cur1][cur2]) {
                    continue;
                }
                dp[i + 1][cur1 + v[i].cur1][cur2 + v[i].cur2] = 1;
                dp[i + 1][cur1 + v[i].cur2][cur2 + v[i].cur1] = 1;
            }
        }
    }

    int minn = NMAX;
    int x = (int)v.size();
    int pos1 = -1, pos2 = -1;

    vector<string> ss;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[x][i][j]) {
                minn = min(minn, abs(i - j));
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[x][i][j] && abs(i - j) == minn) {
                ss.pb(proc(x, i, j));
            }
        }
    }
    sort(ss.begin(), ss.end());
    cout << ss[0];
}