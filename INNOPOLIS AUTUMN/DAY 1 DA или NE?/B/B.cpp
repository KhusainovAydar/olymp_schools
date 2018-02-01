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
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //        freopen("magic.in", "r", stdin);
    //        freopen("magic.out", "w", stdout);
#endif
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    string s;
    cin >> s;
    queue<int> id;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '#') {
            id.push(i);
        }
    }
    x--;
    vector< string > v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        sort(v[i].begin(), v[i].end());
    }
    vector<int> ans;
    while (x > 0) {
        ans.push_back(x % k);
        x /= k;
    }
    reverse(ans.begin(), ans.end());
    int e = 0;
    while (id.size() > ans.size()) {
        int q = id.front();
        s[q] = v[e][0];
        //cout << 0 << ' ';
        e++;
        id.pop();
    }
    for (int i = 0; i < ans.size(); i++) {
        int q = id.front();
        s[q] = v[e][ans[i]];
        //cout << ans[i] << ' ';
        e++;
        id.pop();
    }
    cout << s;
    
}