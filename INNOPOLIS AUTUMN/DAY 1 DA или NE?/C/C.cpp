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
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //        freopen("magic.in", "r", stdin);
    //        freopen("magic.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int pos1 = 0, pos2 = n - 1;
    ll sum1 = 0, sum2 = 0;
    while (pos1 < pos2) {
        if (a[pos1] == a[pos2]) {
            pos1++;
            pos2--;
            continue;
        }
        sum1 = a[pos1];
        sum2 = a[pos2];
        bool ch = false;
        while (pos1 < pos2 && sum1 < sum2) {
            pos1++;
            sum1 += a[pos1];
            cnt++;
            ch = 1;
        }
        if (ch) {
            a[pos1] = sum1;
            a[pos2] = sum2;
            continue;
        }
        while (pos1 < pos2 && sum1 > sum2) {
            pos2--;
            sum2 += a[pos2];
            cnt++;
        }
        a[pos1] = sum1;
        a[pos2] = sum2;
    }
    cout << cnt;
}