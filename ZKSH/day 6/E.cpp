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

const int NMAX = 1000005;

int S[NMAX], G[NMAX], cnt[NMAX];
int prefminS[NMAX], prefminG[NMAX];

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
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == 'S') {
                S[j]++;
            } else {
                G[j]++;
            }
        }
        cnt[s.size() - 1]++;
    }
    prefminS[0] = S[0];
    prefminG[0] = G[0];
    for (int i = 1; i < NMAX; i++) {
        prefminS[i] = min(prefminS[i - 1], S[i]);
        prefminG[i] = min(prefminG[i - 1], G[i]);
    }

    int minusS = 0, minusG = 0;
    ll ans = 0;
    for (int i = NMAX - 1; i >= 0; i--) {
        if (!cnt[i]) continue;
            int cur = min(prefminS[i] - minusS, cnt[i]);
            cnt[i] -= cur;
            minusS += cur;
            ans += cur;
            cur = min(prefminG[i] - minusG, cnt[i]);
            cnt[i] -= cur;
            minusG += cur;
            ans += cur;
    }
    cout << ans;
}
