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
    freopen("invnim.in", "r", stdin);
    freopen("invnim.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int ans = 0;
    int ch = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 1) {
            ch++;
        }
        ans ^= x;
    }
    if (ch == 0) {
        if (n % 2 == 0) {
            cout << "FIRST";
        } else {
            cout << "SECOND";
        }
        return 0;
    }
    if (ans == 0) {
        cout << "SECOND";
    } else {
        cout << "FIRST";
    }
}