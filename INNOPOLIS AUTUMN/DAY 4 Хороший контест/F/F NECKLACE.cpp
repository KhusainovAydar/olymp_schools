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

vector<int> prefix_function (const string &s) {
    int n = (int) s.length();
    vector<int> p (n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])  ++j;
        p[i] = j;
    }
    return p;
}

const int alp = 26;
const int NMAX = 1e4;

int dp[NMAX][1002];

string s, t;

vector< vector<int> > aut;

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);
#endif
    cin >> t;
    int n = (int)t.length();
    cin >> s;
    //s += '$';
    int m = (int)s.length();
    
    vector<int> p = prefix_function(s);
    aut.resize(m + 2, vector<int> (alp));
    for (int i = 0; i <= m; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (i > 0 && c != s[i]) {
                aut[i][c - 'a'] = aut[p[i - 1]][c - 'a'];
            } else {
                aut[i][c - 'a'] = i + (c == s[i]);
            }
        }
    }
    
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < 1002; j++) {
            dp[i][j] = 100000;
        }
    }
    //
    //    for (int i = 0; i < 26; i++) {
    //        cout << char(i + 'a') << ' ';
    //    }
    //    cout << endl;
    //
    //    for (int i = 0; i < m; i++) {
    //        cout << i << ": ";
    //        for (int j = 0; j < 26; j++) {
    //            cout << aut[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
    
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = aut[j][t[i] - 'a'];
            if (cur < m) {
                dp[i + 1][cur] = min(dp[i + 1][cur], dp[i][j]);
            }
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        }
    }
    
    //
    //    for (int i = 0; i < n; i++) {
    //        for (int j = 0; j <= m; j++) {
    //            cout << dp[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
    //
    int minn = 100000;
    for (int i = 0; i < m; i++) {
        minn = min(minn, dp[n][i]);
    }
    cout << minn;
}