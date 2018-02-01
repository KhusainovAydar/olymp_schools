#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef long long ll;

int main() {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("taxi.in", "r", stdin);
    freopen("taxi.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        res += abs(a[i] - b[i]);
    }
    a.push_back(m);
    b.push_back(0);
    n++;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        res += abs(a[i] - b[i]);
    }
    cout << res;
}