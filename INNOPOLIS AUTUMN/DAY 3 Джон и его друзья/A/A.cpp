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

int n;
const int NMAX = 1500;
vector<int> g[NMAX];
int ans;
bool used[NMAX];
bool bad;
bool dfs(int v) {
    used[v] = 1;
    bool ch = 1;
    for (auto t : g[v]) {
        if (used[t]) {
            return false;
        } else {
            ch = ch && dfs(t);
        }
    }
    return ch;
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("relay.in", "r", stdin);
    freopen("relay.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            continue;
        }
        x--;
        g[i].push_back(x);
    }
    int minn = 0;
    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof(used));
        minn += dfs(i);
    }
    cout << minn;
}