#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 100000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 5 * 1e3 + 5;

ll dp[NMAX][NMAX];

int main() {
	//ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("distance.in", "r", stdin); 
		freopen("distance.out", "w", stdout);
	#endif
	string a, b;
	cin >> a >> b;
	if (a.length() < b.length()) swap(a, b);
	for (int i = 0; i < NMAX; i++) {
		for (int j = 0; j < NMAX; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= b.size(); i++) {
		dp[0][i] = dp[0][i - 1] + 1;
	}
	for (int j = 1; j <= a.size(); j++) {
		dp[j][0] = dp[j - 1][0] + 1;
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			} else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	cout << dp[a.size()][b.size()];
}