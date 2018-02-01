#include <bits/stdc++.h>
#define INF 1488228

using namespace std;


const int NMAX = 1488;
int dp[NMAX][NMAX];

string randstring() {
    int n = rand() % 10 + 1;

    if (n % 2 != 0) n++;

    string s = "";

    for (int i = 0; i < n; i++) {
        if (rand() % 2) s += '(';
        else s += ')';
    }
    return s;
}

int firans(string s) {
    int ans = 0, bal = 0;
    string a = s;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(') {
            bal++;
        } else bal--;
        if (bal < 0) {
            bal += 2;
            a[i] = '(';
            ans++;
        }
    }

    bal = 0;

    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == ')') {
            bal++;
        } else bal--;
        if (bal < 0) {
            bal += 2;
            a[i] = ')';
            ans++;
        }
    }

    return ans;
}

int secans(string s) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            dp[i][j] = INF;
        }
    }
    int n = s.length();
    for (int i = 1; i < n; i++) {
        int k = 0;
        if (s[i - 1] != '(') k++;
        if (s[i] != ')') k++;
        dp[i - 1][i] = k;
    }
    for (int len = 2; len <= n; len += 2) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            int k = dp[l + 1][r - 1];
            if (s[l] == ')') k++;
            if (s[r] == '(') k++;
            dp[l][r] = min(dp[l][r], k);
            for (int i = l+1; i <= r - 2; i += 2) {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    string r = randstring();
    int fi = firans(r), se = secans(r);
    for (int i = 1; i <= 4294967296; i++) {
        r = "";
        for (int j = 0; j < 32; j++) {
            if ((1 << j) & i)
                r += '(';
            else r += ')';
        }
        fi = firans(r);
        se = secans(r);
        cout << r << ' ' << fi << ' ' << se << endl;
        if (fi != se)
            return 0;
    }
}
