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

map<int, int> mp;

int get(int x) {
    if (mp[x]) {
        return mp[x];
    }
    if (x == 1) {
        return 0;
    }
    set<int> mex;
    mex.insert(0);
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int a = i;
            int b = x / i;
            if (a % 2) {
                mex.insert(get(b));
            }
            if (b % 2) {
                mex.insert(get(a));
            }
        }
    }
    for (int i = 0; i <= x; i++) {
        if (mex.find(i) == mex.end()) {
            return i;
        }
    }
}
int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("ufo.in", "r", stdin);
//    freopen("ufo.out", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    if (((get(a)) ^ (get(b))) == 0) {
        cout << "Second";
    } else {
        cout << "First";
    }
}