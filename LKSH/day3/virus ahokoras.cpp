#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int maxn = 1e5;

inline string get_str() {
    char c = getchar();
    while (c < 31) c = getchar();
    string s = "";
    while (c >= 32) {
        s += c;
        c = getchar();
    }
    return s;
}

int bor[maxn][2];
int suf[maxn][2];
int auv[maxn];
int p[maxn];
int c[maxn];
int flag[maxn];
int last = 1;

void add(string &s) {
    int cur = 0;
    for (auto i : s) {
        int sum = i - '0';
        if (bor[cur][sum] == 0) {
            bor[cur][sum] = last;
            p[last] = cur;
            c[last] = sum;
            last++;
        }
        cur = bor[cur][sum];
    }
    flag[cur] = true;
}


void buld() {
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int nxt = q.front();
        q.pop();
        if (p[nxt] != 0)
            auv[nxt] = suf[auv[p[nxt]]][c[nxt]];
        if (!flag[nxt])
            flag[nxt] = flag[auv[nxt]];
        for (int i = 0; i < 2; i++) {
            if (bor[nxt][i] != 0) {
                suf[nxt][i] = bor[nxt][i];
                q.push(bor[nxt][i]);
            } else {
                suf[nxt][i] = suf[auv[nxt]][i];
            }
        }
    }
}

void outkek() {
    for (int i = 0; i < last; i++) {
        cout << i << ": ";
        for (int j = 0; j < 2; j++) {
            cout << p[i] << '=' << bor[i][j] << ' ';
        }
        cout << "SUF ";
        cout << auv[i] << ' ';
        if (flag[i]) cout << "TERM";
        cout << endl;
    }
}

enum clr{WHITE, GRAY, BLACK};
clr used[maxn];

bool dfs(int v) {
    if (flag[v]) return false;
    if (used[v] != WHITE) return used[v] == GRAY;
    used[v] = GRAY;
    bool ans = false;
    for (int i = 0; i < 2; i++) {
        ans = ans || dfs(suf[v][i]);
    }
    used[v] = BLACK;
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/joj/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/joj/output.txt", "w", stdout);
#else
    freopen("virus.in", "r", stdin);
    freopen("virus.out", "w", stdout);
#endif
    for (int i = 0; i < maxn; i++) used[i] = WHITE;
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        s = get_str();
        add(s);
    }
    buld();
    if (dfs(0))
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;
}