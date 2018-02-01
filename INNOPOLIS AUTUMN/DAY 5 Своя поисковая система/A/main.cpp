#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define pb push_back
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 10001;
string s;
signed short int f[NMAX][NMAX];
ll sum = 0;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("keepcounted.in", "r", stdin);
    freopen("keepcounted.out", "w", stdout);
#endif
    cin >> s;
    s = '$' + s;
    for (int i = 1; i < (int)s.length(); i++) {
        for (int j = 1; j < (int)s.length(); j++) {
            if (s[i] == s[j] && i != j) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = 0;
            }
        }
    }
    int n = (int)s.length();
    sum = 1;
    cout << sum << endl;
    for (int i = 2; i < (int)s.length(); i++) {
        signed short int maxx = 0;
        for (int j = 1; j < i; j++) {
            maxx = max(maxx, f[j][i]);
        }
        sum += i - maxx;
        cout << sum << endl;
    }
}