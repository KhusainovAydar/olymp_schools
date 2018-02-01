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

int minnx, minny;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return max(abs(a.fi - minnx), abs(a.se - minny)) < max(abs(b.fi - minnx), abs(b.se - minny));
}

ll dist(pair<int, int> p) {
    ll ans = max(abs(p.fi - minnx), abs(p.se - minny));
    return ans;
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
        cin >> n;
        ll ans = LLONG_MAX;
        vector< pair<int, int> > a(n);
        vector<int> minX(n + 1, INT_MAX), maxX(n + 1, INT_MIN), minY(n + 1, INT_MAX), maxY(n + 1, INT_MIN);
        minnx = INT_MAX, minny = INT_MAX;
        int XX[] = {INT_MAX, INT_MIN}, YY[] = {INT_MAX, INT_MIN};
        for (int i = 0; i < n; i++) {
            cin >> a[i].fi >> a[i].se;
            XX[0] = min(XX[0], a[i].fi);
            XX[1] = max(XX[1], a[i].fi);
            YY[0] = min(YY[0], a[i].se);
            YY[1] = max(YY[1], a[i].se);
        }

        minnx = XX[0], minny = YY[0];
        sort(a.begin(), a.end(), cmp);

        for (int i = n - 1; i >= 0; i--) {
            minX[i] = min(minX[i + 1], a[i].fi);
            maxX[i] = max(maxX[i + 1], a[i].fi);
            minY[i] = min(minY[i + 1], a[i].se);
            maxY[i] = max(maxY[i + 1], a[i].se);
        }
        ll tek = 0;
        for (int i = 0; i < n; i++) {
            if (dist(a[i]) <= tek) {
                continue;
            }
            ll xmin = minX[i], xmax = maxX[i];
            ll ymin = minY[i], ymax = maxY[i];
            ans = min(ans, tek * tek + max(xmax - xmin, ymax - ymin) * max(xmax - xmin, ymax - ymin));
            tek = dist(a[i]);
        }

        //---------------------

        minnx = XX[1];
        minny = YY[0];
        sort(a.begin(), a.end(), cmp);

        for (int i = n - 1; i >= 0; i--) {
            minX[i] = min(minX[i + 1], a[i].fi);
            maxX[i] = max(maxX[i + 1], a[i].fi);
            minY[i] = min(minY[i + 1], a[i].se);
            maxY[i] = max(maxY[i + 1], a[i].se);
        }

        tek = 0;
        for (int i = 0; i < n; i++) {
            if (dist(a[i]) <= tek) {
                continue;
            }
            ll xmin = minX[i], xmax = maxX[i];
            ll ymin = minY[i], ymax = maxY[i];
            ans = min(ans, tek * tek + max(xmax - xmin, ymax - ymin) * max(xmax - xmin, ymax - ymin));
            tek = dist(a[i]);
        }



        //---------------------

        minnx = XX[0];
        minny = YY[1];


        sort(a.begin(), a.end(), cmp);

        for (int i = n - 1; i >= 0; i--) {
            minX[i] = min(minX[i + 1], a[i].fi);
            maxX[i] = max(maxX[i + 1], a[i].fi);
            minY[i] = min(minY[i + 1], a[i].se);
            maxY[i] = max(maxY[i + 1], a[i].se);
        }

        tek = 0;
        for (int i = 0; i < n; i++) {
            if (dist(a[i]) <= tek) {
                continue;
            }
            ll xmin = minX[i], xmax = maxX[i];
            ll ymin = minY[i], ymax = maxY[i];
            ans = min(ans, tek * tek + max(xmax - xmin, ymax - ymin) * max(xmax - xmin, ymax - ymin));
            tek = dist(a[i]);
        }


        //---------------------


        minnx = XX[1], minny = YY[1];

        sort(a.begin(), a.end(), cmp);

        for (int i = n - 1; i >= 0; i--) {
            minX[i] = min(minX[i + 1], a[i].fi);
            maxX[i] = max(maxX[i + 1], a[i].fi);
            minY[i] = min(minY[i + 1], a[i].se);
            maxY[i] = max(maxY[i + 1], a[i].se);
        }

        tek = 0;
        for (int i = 0; i < n; i++) {
            if (dist(a[i]) <= tek) {
                continue;
            }
            ll xmin = minX[i], xmax = maxX[i];
            ll ymin = minY[i], ymax = maxY[i];
            ans = min(ans, tek * tek + max(xmax - xmin, ymax - ymin) * max(xmax - xmin, ymax - ymin));
            tek = dist(a[i]);
        }

        cout << ans << endl;
    }
}