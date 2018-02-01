#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1e5;

const int alp = 26;
int trie[NMAX][alp];
int auv[NMAX][alp];
int p[NMAX];
int c[NMAX];
int suf[NMAX];
ll flag[NMAX];
int dp[NMAX];
int timer;
int last = 1;

vector< vector< pair<int, char> > > g;

void init(string & s) {
    int cur = 0;
    for (auto t : s) {
        int ch = t - 'a';
        if (trie[cur][ch] == 0) {
            trie[cur][ch] = last;
            p[last] = cur;
            c[last] = ch;
            last++;
        }
        cur = trie[cur][ch];
    }
    ++flag[cur];
}

void build() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        //cout << v << endl;
        q.pop();
        int pred = p[v];
        if (pred != 0) {
            suf[v] = auv[suf[pred]][c[v]];
        }
        if (v != 0) {
            flag[v] += flag[suf[v]];
        }
        for (int i = 0; i < alp; i++) {
            if (trie[v][i] != 0) {
                auv[v][i] = trie[v][i];
                q.push(auv[v][i]);
            } else {
                auv[v][i] = auv[suf[v]][i];
            }
        }
    }
}

void outkek() {
    for (int i = 0; i < last; i++) {
        cout << i << ": ";
        for (int j = 0; j < 2; j++) {
            cout << trie[i][j] << ' ';
        }
        cout << "SUF ";
        cout << suf[i] << ' ';
        if (flag[i]) cout << "TERM " << flag[i];
        cout << endl;
    }
}

ll cnt = 0;

void dfs(int v, int u) {
    if (u != 0)
        cnt += flag[u];
    //cout << v + 1 << ' ' << u << ' ' << trie[u][0] << ' ' << trie[u][1] << endl;
    int p = u;
    for (int i = 0; i < g[v].size(); i++) {
        int ch = g[v][i].se - (int)'a';
        int to = g[v][i].fi;
        p = auv[u][ch];
        dfs(to, p);
    }
}

int main() {
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("trie.in", "r", stdin);
    freopen("trie.out", "w", stdout);
#endif
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int V;
            char C;
            cin >> V >> C;
            g[i].push_back({V - 1, C});
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        init(s);
    }
    dfs(0, 0);
    //outkek();
    /*cout << endl;
     for (int i = 0; i < last; i++) {
     cout << flag[i] << ' ';
     }
     cout << endl;
     for (int i = 0; i < last; i++) {
     cout << i << ' ';
     }*/
    build();
    /*cout << endl;
     for (int i = 0; i < last; i++) {
     cout << flag[i] << ' ';
     }
     cout << endl;*/
    dfs(0, 0);
    cout << cnt << endl;
    
    //outkek();
}