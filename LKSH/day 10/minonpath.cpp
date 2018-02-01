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


const int NMAX = 5 * 1e4;
vector< vector< pair<int, int> > > g;
pair<int, int> up[NMAX][25];
int timer = 1;
int tin[NMAX], tout[NMAX];

void dfs(int v, int p, int wes) {
    tin[v] = timer++;
    
    up[v][0] = {p, wes};
    for (int i = 1; i <= 20; i++) {
        up[v][i].fi = up[up[v][i - 1].fi][i - 1].fi;
        up[v][i].se = min(up[v][i - 1].se, up[up[v][i - 1].fi][i - 1].se);
    }
    
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i].fi, v, g[v][i].se);
    
    tout[v] = timer++;
}

bool is_ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int LCA(int a, int b) {
    if (is_ancestor(a, b))
        return INF;
    int ans = INF;
    for (int i = 20; i >= 0; i--) {
        if (!is_ancestor(up[a][i].fi, b)) {
            ans = min(ans, up[a][i].se);
            a = up[a][i].fi;
        }
    }
    return min(ans, up[a][0].se);
}

int main() {
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
#endif
    int n = readInt();
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int a = readInt(), w = readInt();
        a--;
        g[a].push_back({i, w});
    }
    dfs(0, 0, INF);
    int m = readInt();
    for (int i = 0; i < m; i++) {
        int a = readInt(), b = readInt();
        a--;
        b--;
        cout << min(LCA(a, b), LCA(b, a)) << endl;
    }
    return 0;
}