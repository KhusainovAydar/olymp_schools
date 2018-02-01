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

int k;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.fi / k == b.fi / k) {
        return a.se < b.se;
    } else {
        return (a.fi / k) < (b.fi / k);
    }
}

map< pair<int, int>, ll> ans;
int cnt[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    k = sqrt(n);
    while (k * k < n) k++;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector< pair<int, int> > z;
    vector< pair<int, int> > out;
    for (int i = 0; i < m; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        z.push_back({A, B});
        out.push_back({A, B});
    }
    sort(z.begin(), z.end(), cmp);
    ll l = 0, r = 0, sum = 0;
    for (int i = 0; i < (int)z.size(); i++) {
        if (ans[{z[i].fi, z[i].se}] != 0) continue;
        if (z[i].fi / k == z[i].se / k) {
            unordered_map<int, int> CNT;
            CNT.clear();
            int ANS = 0;
            for (int j = z[i].fi; j <= z[i].se; j++) {
                int minus = CNT[a[j]] * CNT[a[j]] * a[j];
                ++CNT[a[j]];
                ANS += CNT[a[j]] * CNT[a[j]] * a[j] - minus;
            }
            ans[{z[i].fi, z[i].se}] = ANS;
            continue;
        }
        if ((z[i].fi / k + 1) * k == l) {
            while (r <= z[i].se) {
                int minus = cnt[a[r]] * cnt[a[r]] * a[r];
                ++cnt[a[r]];
                sum += cnt[a[r]] * cnt[a[r]] * a[r] - minus;
                r++;
            }
            for (int j = z[i].fi; j < l; j++) {
                int minus = cnt[a[j]] * cnt[a[j]] * a[j];
                ++cnt[a[j]];
                sum += cnt[a[j]] * cnt[a[j]] * a[j] - minus;
            }
            ans[{z[i].fi, z[i].se}] = sum;
            for (int j = z[i].fi; j < l; j++) {
                int minus = cnt[a[j]] * cnt[a[j]] * a[j];
                cnt[a[j]] = max(0, cnt[a[j]] - 1);
                sum += cnt[a[j]] * cnt[a[j]] * a[j] - minus;
            }
        } else {
            l = (z[i].fi / k + 1) * k;
            r = l;
            sum = 0;
            memset(cnt, 0, sizeof(cnt));
            while (r <= z[i].se) {
                int minus = cnt[a[r]] * cnt[a[r]] * a[r];
                ++cnt[a[r]];
                sum += cnt[a[r]] * cnt[a[r]] * a[r] - minus;
                r++;
            }
            for (int j = z[i].fi; j < l; j++) {
                int minus = cnt[a[j]] * cnt[a[j]] * a[j];
                ++cnt[a[j]];
                sum += cnt[a[j]] * cnt[a[j]] * a[j] - minus;
            }
            ans[{z[i].fi, z[i].se}] = sum;
            for (int j = z[i].fi; j < l; j++) {
                int minus = cnt[a[j]] * cnt[a[j]] * a[j];
                cnt[a[j]] = max(0, cnt[a[j]] - 1);
                sum += cnt[a[j]] * cnt[a[j]] * a[j] - minus;
            }
        }
    }
    for (int i = 0; i < (int)out.size(); i++) {
        cout << ans[{out[i].fi, out[i].se}] << endl;
    }
}