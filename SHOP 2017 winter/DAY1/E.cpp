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
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 1000050;

int cnt[NMAX];
vector< pair<int, int> > mp[2];
//map< pair<int, int>, int> mp[2];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("anniversary.in", "r", stdin);
//    freopen("anniversary.out", "w", stdout);
#endif
    int ans[NMAX];
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i + 1 < n; i += 2) {
        mp[0].pb({min(a[i], a[i + 1]), max(a[i], a[i + 1])});
//        mp[0][{min(a[i], a[i + 1]), max(a[i], a[i + 1])}]++;
    }

    for (int i = 1; i + 1 < n; i += 2) {
        mp[1].pb({min(a[i], a[i + 1]), max(a[i], a[i + 1])});
//        mp[1][{min(a[i], a[i + 1]), max(a[i], a[i + 1])}]++;
    }

    fill(ans, ans + NMAX, 1000000);
    vector< pair<int, int> > srt;
    for (int i = 1; i <= k; i++) {
        srt.pb({cnt[i], i});
    }

    sort(srt.rbegin(), srt.rend());
    sort(all(mp[0]));
    sort(all(mp[1]));

    for (int i = 1; i <= k; i++) {

        int id1 = int(lower_bound(mp[0].begin(), mp[0].end(), make_pair(i, i)) - mp[0].begin());
        int id2 = int(lower_bound(mp[1].begin(), mp[1].end(), make_pair(i, i)) - mp[1].begin());

        if ((id1 < mp[0].size() && mp[0][id1] == make_pair(i, i)) || (id2 < mp[1].size() && mp[1][id2] == make_pair(i, i))) {
            ans[i] = min(ans[i], n - cnt[i]);
        }

        for (int j = 0; j < srt.size(); j++) {
            int v = srt[j].se;
            int u = i;
            if (v > u) swap(v, u);

            if (v == u) continue;
            int id = lower_bound(mp[0].begin(), mp[0].end(), make_pair(v, u)) - mp[0].begin();
            if (id == mp[0].size() || mp[0][id] != make_pair(v, u)) {
                ans[v] = min(ans[v], n - cnt[v] - cnt[u]);
                ans[u] = min(ans[u], n - cnt[v] - cnt[u]);
                break;
            }

            id = lower_bound(mp[1].begin(), mp[1].end(), make_pair(v, u)) - mp[1].begin();
            if (id == mp[1].size() || mp[1][id] != make_pair(v, u)) {
                ans[v] = min(ans[v], n - cnt[v] - cnt[u]);
                ans[u] = min(ans[u], n - cnt[v] - cnt[u]);
                break;
            }
        }
    }

//    for (int i = 0; i < srt.size(); i++) {
//        for (int j = i + 1; j < srt.size(); j++) {
//            int v = srt[i].se, u = srt[j].se;
//
//            if (mp[0][{min(v, u), max(v, u)}] == 0) {
//                ans[v] = min(ans[v], n - cnt[v] - cnt[u]);
//                ans[u] = min(ans[u], n - cnt[v] - cnt[u]);
//                break;
//            }
//
//            if (mp[1][{min(v, u), max(v, u)}] == 0) {
//                ans[v] = min(ans[v], n - cnt[v] - cnt[u]);
//                ans[u] = min(ans[u], n - cnt[v] - cnt[u]);
//                break;
//            }
//        }
//    }

//
//    for (int i = 1; i <= k; i++) {
//        for (int j = 0; j < 2; j++) {
//            g[j][i].pb(i);
//            for (auto t : g[j][i]) {
//                for (auto q : pos[t]) {
//                    upd(0, 0, n - 1, q, 0);
//                }
//            }
//            ans[i] = min(ans[i], n - cnt[i] - getans(0, 0, n - 1, 0, n - 1));
//            for (auto t : g[j][i]) {
//                for (auto q : pos[t]) {
//                    upd(0, 0, n - 1, q, cnt[t]);
//                }
//            }
//        }
//    }

    for (int i = 0; i + 1 < n; i += 2) {
        if (a[i] == a[i + 1]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
        } else {
            int v = a[i], u = a[i + 1];
            if (v > u) {
                swap(v, u);
            }
            int val = n - cnt[a[i]] - cnt[a[i + 1]] + int(upper_bound(mp[0].begin(), mp[0].end(), make_pair(v, u)) - lower_bound(mp[0].begin(), mp[0].end(), make_pair(v, u)));
            ans[a[i]] = min(ans[a[i]], val);
            ans[a[i + 1]] = min(ans[a[i + 1]], val);
        }
    }

    for (int i = 1; i + 1 < n; i += 2) {
        if (a[i] == a[i + 1]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
        } else {
            int v = a[i], u = a[i + 1];
            if (v > u) {
                swap(v, u);
            }
            int val = n - cnt[a[i]] - cnt[a[i + 1]] + int(upper_bound(mp[1].begin(), mp[1].end(), make_pair(v, u)) - lower_bound(mp[1].begin(), mp[1].end(), make_pair(v, u)));
            ans[a[i]] = min(ans[a[i]], val);
            ans[a[i + 1]] = min(ans[a[i + 1]], val);
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << ans[i] << endl;
    }
}