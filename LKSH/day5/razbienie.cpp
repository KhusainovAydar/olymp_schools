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

const int NMAX = 20005;
vector< vector<int> > g;
int cnt[NMAX];
inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);

/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = (int)fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
    if (x < 0)
        writeChar('-'), x = -x;
    
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord(const char *s) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

bitset<NMAX> w[NMAX];
vector<int> ans;

void dfs(int v) {
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (w[v][to]) {
            w[v][to] = false;
            w[to][v] = false;
            cnt[v]--;
            cnt[to]--;
            dfs(to);
            break;
        }
    }
    ans.push_back(v);
}

int main() {
    //ios_base::sync_with_stdio(false);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("paths.in", "r", stdin);
    freopen("paths.out", "w", stdout);
#endif
    int n = readInt(), m = readInt();
    g.resize(n);
    vector< vector<int> > ANS;
    for (int i = 0; i < m; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
        w[a][b] = true;
        w[b][a] = true;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] % 2 == 1) {
            ans.clear();
            dfs(i);
            ANS.push_back(ans);
        }
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) {
            ans.clear();
            dfs(i);
            ANS.push_back(ans);
        }
    }
    writeInt(ANS.size());
    writeChar(endl);
    for (int i = 0; i < ANS.size(); i++) {
        for (int j = 0; j < ANS[i].size(); j++) {
            writeInt(ANS[i][j] + 1);
            writeChar(' ');
        }
        writeChar(endl);
    }
}