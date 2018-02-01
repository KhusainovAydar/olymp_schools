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

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("centroid.in", "r", stdin);
//    freopen("centroid.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector< vector< pair<int, int> > > ans;
    if (n % 2) {
        for (int i = 1; i <= n; i++) {
            int j = 1;
            vector< pair<int, int> > push;
            while (j <= n) {
                if (i > j) {
                    push.pb({i, j});
                }
                i--;
                j++;
                if (i == 0) {
                    i = n;
                }
            }
            ans.pb(push);
        }
        cout << ans.size() << endl;
        for (auto t : ans) {
            cout << t.size() << ' ';
            for (auto i : t) {
                cout << i.fi << '-' << i.se << ' ';
            }
            cout << endl;
        }
    } else {
        n--;
        bool used[n + 5];
        for (int i = 1; i <= n; i++) {
            int j = 1;
            memset(used, 0, sizeof(used));
            vector< pair<int, int> > push;
            while (j <= n) {
                if (i > j) {
                    push.pb({i, j});
                    used[i] = 1;
                    used[j] = 1;
                }
                i--;
                j++;
                if (i == 0) {
                    i = n;
                }
            }
            for (j = 1; j <= n; j++) {
                if (!used[j]) {
                    push.pb({n + 1, j});
                    break;
                }
            }
            ans.pb(push);
        }
        cout << ans.size() << endl;
        for (auto t : ans) {
            cout << t.size() << ' ';
            for (auto i : t) {
                cout << i.fi << '-' << i.se << ' ';
            }
            cout << endl;
        }
    }
}