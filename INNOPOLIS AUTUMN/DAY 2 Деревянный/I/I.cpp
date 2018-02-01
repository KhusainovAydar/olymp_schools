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

const int NMAX = 1e5 + 5;

const int K = 20;

int go[K][NMAX];
int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    
#endif
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x[i + 1];
    }
    int D;
    cin >> D;
    for (int i = 1; i <= n; i++) {
        int val = x[i] + D;
        int L = 0, R = n;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (i + M > n) {
                R = M;
                continue;
            }
            if (x[i + M] <= val) {
                L = M;
            } else {
                R = M;
            }
        }
        go[0][i] = i + L;
    }
    
    for (int i = 1; i < K; i++) {
        for (int j = 1; j <= n; j++) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int ans = 0;
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        for (int i = K - 1; i >= 0; i--) {
            if (go[i][a] < b) {
                ans += (1 << i);
                a = go[i][a];
            }
        }
        ans += (a != b);
        cout << ans << endl;
    }
}