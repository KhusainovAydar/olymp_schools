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

const int NMAX = 200005;

int p[NMAX];
int w[NMAX];
int n, m;
int K;

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
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        p[i] = x;
    }
    p[0] = -1;

    for (int i = 1; i < n; i++) {
        cin >> w[i];
    }

    vector< pair<int, int> > vec(m);
    for (int i = 0; i < m; i++) {
        cin >> vec[i].fi >> vec[i].se;
    }

    K = 2000;
    for (int i = 0; i * i <= m; i++) {
        vector<bool> used((unsigned long) n, 0);
        vector<int> maxx((unsigned long) n, 0);
        vector<int> p2((unsigned long) n, -1);

        vector<int> nums;

        for (int j = K * i; j < min(m, (i + 1) * K); j++) {
            if (!used[vec[j].fi]) {
                maxx[vec[j].fi] = w[vec[j].fi];
                used[vec[j].fi] = 1;
                nums.pb(vec[j].fi);
            }
            if (p[vec[j].fi] != -1 && !used[p[vec[j].fi]]) {
                used[p[vec[j].fi]] = 1;
                maxx[p[vec[j].fi]] = w[p[vec[j].fi]];
                nums.pb(p[vec[j].fi]);
            }
            if (!used[vec[j].se]) {
                maxx[vec[j].se] = w[vec[j].se];
                used[vec[j].se] = 1;
                nums.pb(vec[j].se);
            }
            if (p[vec[j].se] != -1 && !used[p[vec[j].se]]) {
                used[p[vec[j].se]] = 1;
                maxx[p[vec[j].se]] = w[p[vec[j].se]];
                nums.pb(p[vec[j].se]);
            }
        }

        for (int j = 0; j < (int)nums.size(); j++) {
            int v = nums[j];
            while (p[v] != -1 && !used[p[v]]) {
                maxx[nums[j]] = max(maxx[nums[j]], w[v]);
                v = p[v];
            }
            if (p[v] != -1) {
                maxx[nums[j]] = max(maxx[nums[j]], w[v]);
                p2[nums[j]] = p[v];
            } else {
                p2[nums[j]] = -1;
                maxx[nums[j]] = max(maxx[nums[j]], w[v]);
            }
        }

        for (int j = K * i; j < min(m, (i + 1) * K); j++) {
            int u = vec[j].fi, v = vec[j].se;
            if (v == u) {
                cout << -1 << endl;
                continue;

            }
            bool ch = false;
            int maxans = maxx[vec[j].se];
            while (v != -1) {
                if (p2[v] == u) {
                    maxans = max(maxans, maxx[v]);
                    cout << maxans << endl;
                    ch = 1;
                    break;
                }
                maxans = max(maxans, maxx[v]);
                v = p2[v];
            }
            if (!ch) {
                v = vec[j].se;
                p2[u] = v;
                p[u] = v;
                maxx[u] = w[u];
            }
        }
    }
}