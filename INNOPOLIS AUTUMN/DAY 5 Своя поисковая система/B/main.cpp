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

const int NMAX = 5001;
string s;
int f[NMAX][NMAX], l[NMAX][NMAX];
ll sum = 0;

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //    freopen("keepcounted.in", "r", stdin);
    //    freopen("keepcounted.out", "w", stdout);
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
    
    for (int i = 1; i < n; i++) {
        int d = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (f[i][j] > d) {
                for (int g = d + 1; g <= f[i][j]; g++) {
                    l[j - g + 1][i]--;
                }
                d = f[i][j];
            }
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j < n - 1; j++) {
            l[i][j + 1] += l[i][j];
        }
    }
    for (int i = n - 1; i > 1; i--) {
        for (int j = 1; j < n; j++) {
            l[i - 1][j] += l[i][j];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int len = (R - L + 1);
        cout << (len * (len + 1)) / 2 + l[L][R] << endl;
    }
}