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
    int n;
    cin >> n;
    vector<int> a(n), pr(n, 0), sf(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            pr[i] = __gcd(pr[i - 1], a[i]);
        } else {
            pr[i] = a[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            sf[i] = a[i];
        } else {
            sf[i] = __gcd(sf[i + 1], a[i]);
        }
    }
    int maxx = 0, id = 0;
    for (int i = 0; i < n; i++) {
        if (!i) {
            if (sf[i + 1] > maxx) {
                maxx = sf[i + 1];
                id = i + 1;
            }
        } else if (i == n - 1) {
            if (pr[n - 2] > maxx) {
                maxx = pr[n - 2];
                id = i + 1;
            }
        } else {
            if (__gcd(sf[i + 1], pr[i - 1]) > maxx) {
                maxx = __gcd(sf[i + 1], pr[i - 1]);
                id = i + 1;
            }
        }
    }
    cout << id << ' ' << maxx;
}
