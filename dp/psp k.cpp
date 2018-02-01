#include <bits/stdc++.h>


using namespace std;

int n, p;

long long  dp[5000][5000];

string get (int n, int k) {
    int d = 0;
    string s = "";
    k++;
    for (int i = 0; i < 2 * n; i++){
        if (dp[2 * n - (i + 1)][d + 1] >= k) {
            s += '(';
            d++;
        } else {
            k -= dp[2 * n - (i + 1)][d + 1];
            s += ')';
            d--;
        }
    }
    return s;
}

int main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //freopen("parens.in", "r", stdin);freopen("parens.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    cin >> n >> p;
    dp[0][0] = 1;
    for (int i = 1; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    if (dp[2 * n][0] <= p) {
        cout << "N/A";
        return 0;
    }
    string s = get(n, p);
    cout << s;
    return 0;
}
