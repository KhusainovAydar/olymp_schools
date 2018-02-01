#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;
const int INF = 234567896;
int n, m;
int dp[5000][5000];
int preff[5000];

vector<int> LCIS(vector<int> a, vector<int> b) {
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        int best = 0, ind = 0;
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j] && dp[i - 1][j] < best + 1) {
                dp[i][j] = best + 1;
                preff[j] = ind;
            }
            if (a[i] > b[j] && dp[i - 1][j] > best) {
                best = dp[i - 1][j];
                ind = j;
            }
        }
    }
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[n][pos] < dp[n][i]) {
            pos = i;
        }
    }
    vector<int> ans;
    while (pos != 0) {
        ans.push_back(b[pos]);
        pos = preff[pos];
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
}
