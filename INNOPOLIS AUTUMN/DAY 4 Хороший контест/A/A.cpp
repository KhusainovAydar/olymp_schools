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

const int alp = 26;
const int NMAX = 1e6 + 5;

int bor[NMAX][alp];
int p[NMAX];
int c[NMAX];
int flag[NMAX];
int ans[NMAX];
bool kek[NMAX];
int last = 1;

void add(string &s) {
    int cur = 0;
    for (auto i : s) {
        int sum = i - 'a';
        if (bor[cur][sum] == 0) {
            bor[cur][sum] = last;
            last++;
        }
        cur = bor[cur][sum];
    }
    flag[cur] = true;
}

string s;

bool ch(int id) {
    int node = 0;
    for (int i = id; i < (int)s.length(); i++) {
        int v = s[i] - 'a';
        if (i - id > 35) {
            return false;
        }
        if (bor[node][v] != 0) {
            node = bor[node][v];
            if (flag[node]) {
                kek[node] = 1;
            }
            continue;
        } else {
            return false;
        }
    }
    return false;
}

bool can(const string & S) {
    int node = 0;
    for (int i = 0; i < (int)S.length(); i++) {
        int v = S[i] - 'a';
        if (bor[node][v] != 0) {
            node = bor[node][v];
            continue;
        }
    }
    return kek[node];
}
int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("dictionary.in", "r", stdin);
    freopen("dictionary.out", "w", stdout);
#endif
    cin >> s;
    int n;
    cin >> n;
    vector< string > v(n);
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        v[i] = x;
        add(x);
    }
    for (int i = 0; i < (int)s.length(); i++) {
        ch(i);
    }
    for (int i = 0; i < n; i++) {
        if (v[i].size() > s.size()) {
            cout << "No" << endl;
            continue;
        }
        if (can(v[i])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}