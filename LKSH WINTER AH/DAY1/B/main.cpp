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

using namespace std;

typedef long long ll;

const int NMAX = 10005;

bool dp[5005][NMAX];
int pref[5005][NMAX];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("round.in", "r", stdin);
    freopen("round.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a((unsigned long) n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector< pair<ll, ll> > b((unsigned long) n);
    for (int i = 0; i < n; i++) {
        ll x = a[i] * m;
        ll d = x / sum;
        if (x % sum != 0) {
            b[i] = {d, d + 1};
        } else {
            b[i] = {d, d};
        }
    }
    dp[0][0] = 1;
//    for (int i = 0; i < n; i++) {
//        cerr << b[i].fi << ' ' << b[i].se << endl;
//    }
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (dp[i][j]) {
                int x1 = (int) b[i].fi;
                int x2 = (int) b[i].se;
                if (j + x1 <= m) {
                    dp[i + 1][j + x1] = 1;
                    pref[i + 1][j + x1] = x1;
                }
                if (j + x2 <= m) {
                    dp[i + 1][j + x2] = 1;
                    pref[i + 1][j + x2] = x2;
                }
            }
        }
    }
    vector<int> ans;
    int x = n, y = m;
    if (!dp[x][y]) {
        assert(false);
    }
    while (x > 0 || y > 0) {
        ans.pb(pref[x][y]);
        y -= pref[x][y];
        x--;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}