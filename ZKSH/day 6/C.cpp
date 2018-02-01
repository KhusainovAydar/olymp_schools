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
//#if __APPLE__
//    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
//    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
//#else
//    //    freopen("flow2.in", "r", stdin);
////    freopen("flow2.out", "w", stdout);
//#endif
    int T;
    cin >> T;
    while (T--) {
        ll x;
        int k;
        cin >> x >> k;
        int cnt = 0;
        unordered_set<int> s;
        while (true) {
            bool ch = false;
            for (ll i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    cnt++;
                    x /= i;
                    s.insert(i);
                    ch = 1;
                    break;
                }
            }
            if (!ch) break;
        }
        if (x > 1) {
            s.insert(x);
            cnt++;
        }
        if (k > cnt) {
            cout << "NO" << endl;
            continue;
        }
        if (s.size() == 1) {
            if (k % 2 == 0) {
                if (cnt % 2 == 0) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                continue;
            } else {
                if (cnt % 2 == 0) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
                continue;
            }
        }
        if (k > cnt) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
