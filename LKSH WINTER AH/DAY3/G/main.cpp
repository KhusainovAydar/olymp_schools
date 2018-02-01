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
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;

const int NMAX = 1e5 + 50;
ll n, m, sum1;
int ans[NMAX], cnt[NMAX], List[NMAX];
queue< pair< pair<ll, ll>, ll> > st[NMAX];
vector<ll> a, pr, b[NMAX], pos, d[NMAX], vec[NMAX];

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("circular-cipher.in", "r", stdin);
    freopen("circular-cipher.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        b[i].resize((unsigned long) k);
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
            b[i][j]--;
            cnt[b[i][j]]++;
        }
    }
    for (int i = 0; i < m; i++) {
        int ss = 1;
        while (ss < cnt[i]) {
            ss *= 2;
        }
        d[i].assign(2 * ss, 1);
        vec[i].assign(2 * ss, 0);
        pos.push_back(ss);
    }
    for (int i = 0; i < n; i++) {
        ll k = b[i].size();
        a = b[i];
        for (int j = 0; j < k; j++) {
            while (!st[a[j]].empty()) {
                ll kk = d[a[j]][1];
                ll pp = vec[a[j]][1];
                if (List[a[j]] == i - 1 && pp % __gcd(kk, k) == j % __gcd(kk, k)) {
                    break;
                }
                int u = (int) st[a[j]].front().se;
                st[a[j]].pop();
                d[a[j]][u] = 1;
                vec[a[j]][u] = 0;
                while (u / 2 > 0) {
                    u /= 2;
                    ll aa, bb, x, y, kk;
                    aa = d[a[j]][2 * u], bb = d[a[j]][2 * u + 1];
                    x = 0, y = 0;
                    kk = gcd(aa, bb, x, y);
                    d[a[j]][u] = (aa / kk) * bb;
                    x *= ((vec[a[j]][2 * u + 1] - vec[a[j]][2 * u]) / kk);
                    x %= (d[a[j]][u] / d[a[j]][2 * u]);
                    vec[a[j]][u] = ((x * aa + vec[a[j]][2 * u]) % d[a[j]][u] + d[a[j]][u]) % d[a[j]][u];
                }
            }
            List[a[j]] = i;
            st[a[j]].push({ {k, j}, pos[a[j]]});
            d[a[j]][pos[a[j]]] = k;
            vec[a[j]][pos[a[j]]] = j;
            int u = pos[a[j]];
            while (u / 2 > 0) {
                u /= 2;
                ll aa, x, y, bb, kk;
                aa = d[a[j]][2 * u], bb = d[a[j]][2 * u + 1];
                x = 0, y = 0;
                kk = gcd(aa, bb, x, y);
                d[a[j]][u] = (aa / kk) * bb;
                x *= ((vec[a[j]][2 * u + 1] - vec[a[j]][2 * u]) / kk);
                x %= (d[a[j]][u] / d[a[j]][2 * u]);
                vec[a[j]][u] = ((x * aa + vec[a[j]][2 * u]) % d[a[j]][u] + d[a[j]][u]) % d[a[j]][u];
            }
            pos[a[j]]++;
            ans[a[j]] = max(ans[a[j]], (int)st[a[j]].size());
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}