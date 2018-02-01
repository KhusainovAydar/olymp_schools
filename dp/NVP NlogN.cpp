#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;
const int NMAX = 1e5;
const int INF = 1e9;

int n, len;
int pref[NMAX];
int pos[NMAX];

void findLIS(vector<int> a) {
    vector<int> dp(n + 1, INF);
    pos[0] = -1;
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (a[i] < dp[j] && a[i] > dp[j - 1]) {
            dp[j] = a[i];
            pos[j] = i;
            pref[i] = pos[j - 1];
            len = max(len, j);
        }
    }

    vector<int> ans;
    int p = pos[len];
    while (p != -1) {
        ans.push_back(a[p]);
        p = pref[p];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

}
