#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

int n;
vector< vector<int> > g;
const int NMAX = 250;

int back[NMAX];
bool used[NMAX];

bool find_chain(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (back[to] == -1 || find_chain(back[to])) {
            back[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);
#endif
    cin >> n;
    string s;
    cin >> s;
    g.resize(n + s.length() + 2);
    int sz = (int)s.length();
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < 6; j++) {
            for (int y = 0; y < sz; y++) {
                if (a[j] == s[y]) {
                    g[i].push_back(y);
                }
            }
        }
    }
    fill(back, back + NMAX, -1);
    fill(used, used + NMAX, 0);
    for (int i = 0; i < n; i++) {
        if (find_chain(i))
            fill(used, used + NMAX, 0);
    }
    for (int i = 0; i < sz; i++) {
        if (back[i] == -1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < sz; i++) {
        cout << back[i] + 1 << ' ';
    }
}