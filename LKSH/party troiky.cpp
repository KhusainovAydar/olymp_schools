#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;

const int NMAX = 1e5 + 10;

vector<pair<ll, ll>> z;
vector<long double> a, b;

ll tone[4 * NMAX], tsum[4 * NMAX];

void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        if (val == 1) {
            tone[v] = 1;
            tsum[v] = z[tl].fi;
        } else {
            tsum[v] = 0;
            tone[v] = 0;
        }
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) upd(2 * v + 1, tl, tm, pos, val);
        else upd(2 * v + 2, tm + 1, tr, pos, val);
        tone[v] = tone[2 * v + 1] + tone[2 * v + 2];
        tsum[v] = tsum[2 * v + 1] + tsum[2 * v + 2];
    }
}

int getind(int v, int tl, int tr, int k) {
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (tone[2 * v + 1] >= k) getind(2 * v + 1, tl, tm, k);
    else getind(2 * v + 2, tm + 1, tr, k - tone[2 * v + 1]);
}

ll getsum(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return tsum[v];
    if (l > r) return 0;

    int tm = (tl + tr) >> 1;
    return getsum(2 * v + 1, tl, tm, l, min(r, tm)) +
            getsum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

ll getone(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return tone[v];
    if (l > r) return 0;
    int tm = (tl + tr) >> 1;
    return getone(2 * v + 1, tl, tm, l, min(r, tm)) +
            getone(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

vector<vector<ll> > open(NMAX + 5), close(NMAX + 5);
vector<pair<ll, ll> > LR;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long double s;
    cin >> n >> s;
    vector<int> ans;
    if (s == 0) {
        ll lol = 0;
        for (int i = 0; i < n; i++) {
            int aa, bb, cc;
            cin >> aa >> bb >> cc;
            if (aa == 0) {
                ans.push_back(i + 1);
                lol += cc;
            }
        }
        cout << ans.size() << ' ' << lol << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        return 0;
    }
    LR.resize(n + 5);
    a.resize(n), b.resize(n), z.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> z[i].fi;
        z[i].se = i;
    }
    sort(z.rbegin(), z.rend());
    for (int i = 0; i < z.size(); i++) {
        //cout << z[i].fi << ' ';
        ll l;
        if (b[z[i].se] == 0) l = 0;
        else l = ceil((long double)(s) / (long double)(b[z[i].se])) - 1;
        if (l > n) {
            l = n + 1;
        }
        ll r;
        if (a[z[i].se] == 0) r = n + 1;
        else r = floor((long double)(s) / (long double)(a[z[i].se])) - 1;
        //r = max(r, l);
        if (r > n) {
            r = n + 1;
        }
        //cout << "L " << l << " R "<< r << endl;
        if (b[z[i].se] != 0) {
            LR[i] = {l, r};
            open[l].push_back(i);
        }
        if (a[z[i].se] != 0)
        close[r + 1].push_back(i);
    }
    //cout << endl;
    pair<ll, ll> maxx = {0, 0};
    for (int k = 0; k <= n; k++) {
        for (int i = 0; i < open[k].size(); i++) {
            upd(0, 0, n - 1, open[k][i], 1);
        }
        for (int i = 0; i < close[k].size(); i++) {
            upd(0, 0, n - 1, close[k][i], 0);
        }
        ll sum = getsum(0, 0, n - 1, 0, getind(0, 0, n - 1, k));
        int check = getone(0, 0, n - 1, 0, getind(0, 0, n - 1, k));
        //cout << sum << endl;
        if (maxx.fi < sum && check == k) {
            maxx.fi = sum;
            maxx.se = k;
        }
    }
    cout << maxx.se << ' '<< maxx.fi << endl;

    int k = maxx.se;
    int cnt = 0;
    for (int i = 0; i < z.size() && cnt < k; i++) {
        if (LR[i].fi <= k && LR[i].se >= k) {
            ans.push_back(z[i].se);
            cnt++;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << ' ';
    }
}
