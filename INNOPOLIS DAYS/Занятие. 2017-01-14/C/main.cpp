#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define rand() ((rand() << 16) + rand())
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//#define MIN -2147483648
//#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 3000050;

vector< pair<int, int> > bor[NMAX];
int dp[2][NMAX];
bool term[NMAX];
int last = 1;

void add(const string & s) {
    int v = 0;
    for (auto i : s) {
        int c = i - 'a';
        for (int j = 0; j < bor[v].size(); j++) {
            if (bor[v][j].fi == c) {
                v = bor[v][j].se;
                c = -1;
                break;
            }
        }
        if (c >= 0) {
            bor[v].pb({c, last});
            v = last;
            last++;
        }
    }
    term[v] = 1;
}

void dfs(int v) {
    for (int i = 0; i < bor[v].size(); i++) {
        dfs(bor[v][i].se);
    }
    int cnt = 0;
    int maxx = 0;
    int maxx2 = 0;
    for (int i = 0; i < bor[v].size(); i++) {
        int u = bor[v][i].se;
        cnt += term[u];
        if (dp[0][u] * term[u] >= maxx) {
            maxx2 = maxx ;
            maxx = dp[0][u] * term[u];
        } else {
            maxx2 = max(maxx2, dp[0][u] * term[u]);
        }
    }
    int val = max(0, max(0, maxx - 1) + max(0, maxx2 - 1)) + cnt + term[v];
    dp[1][v] = val;
    dp[0][v] = max(0, max(0, maxx - 1)) + cnt + term[v];
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cout.precision(20);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
//    freopen("sweets.in", "r", stdin);
//    freopen("sweets.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        add(s);
    }
    dfs(0);
    int maxx = 0;
    for (int i = 0; i < last; i++) {
        maxx = max(maxx, max(dp[0][i], dp[1][i]));
    }
//    for (int i = 0; i < last; i++) {
//        cout << dp[i] << endl;
//    }
//    cout << endl;
    cout << maxx;
}

