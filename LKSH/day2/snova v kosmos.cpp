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
        pos = 0, len = fread(buf, 1, buf_size, stdin);
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

/** Example */

struct Hash {
    vector< vector<ll> > h;
    vector<ll> step1, step2;
    ll p1 = 31, p2 = 239, mod = 42424243;
    ll get_mod(ll a) {
        //a = a % mod;
        //if (a < 0)
        //    a += mod;
        return a;
    }
    void init(const vector< vector<char> > &m) {
        unsigned long N = m.size();
        unsigned long M = m[0].size();
        h.resize(N, vector<ll> (M));
        step1.resize(N + 1);
        step2.resize(M + 1);
        step1[0] = 1;
        step2[0] = 1;
        int c = m[0][0] - 'A';
        h[0][0] = c;
        for (int i = 1; i <= N; i++) {
            step1[i] = step1[i - 1] * p1;
            //if (step1[i] >= mod) step1[i] %= mod;
        }
        for (int i = 1; i <= M; i++) {
            step2[i] = step2[i - 1] * p2;
            //if (step2[i] >= mod) step2[i] %= mod;
        }
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (x == 0 && y == 0) continue;
                c = m[x][y] - 'A';
                h[x][y] = get_mod((x ? (h[x - 1][y] * p1) : 0) + (y ? (h[x][y - 1] * p2) : 0) - ((x > 0 && y > 0) ? h[x - 1][y - 1] * p1 * p2 : 0) + c);
            }
        }
    }
    ll get_hash(int x, int y, int xx, int yy) {
        ll ret = get_mod(h[xx][yy] - (y ? (h[xx][y - 1] * step2[yy - y + 1]) : 0)
                         - (x ? (h[x - 1][yy] * step1[xx - x + 1]) : 0) + ((x > 0 && y > 0) ? (h[x - 1][y - 1] * step1[xx - x + 1] * step2[yy - y + 1]) : 0));
        return ret;
    }
};

int main() {
    //ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
/*#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
#endif*/
    int n, m;
    n = readInt();
    m = readInt();
    vector< vector<char> > mas(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mas[i][j] = readChar();
        }
    }
    Hash kek;
    kek.init(mas);
    set<int> siz;
    int le = 0;
    for (int sz = 1; sz <= m; sz++) {
        bool check = true;
        int i = 0;
        for (i = 0; i + sz - 1 < m; i += sz) {
            ll h1 = kek.get_hash(le, 0, le, sz - 1);
            ll h2 = kek.get_hash(le, i, le, i + sz - 1);
            if (h1 != h2) {
                check = false;
                break;
            }
        }
        if (i < m && check) {
            ll h1 = kek.get_hash(le, 0, le, m - 1 - i);
            ll h2 = kek.get_hash(le, i, le, m - 1);
            if (h1 != h2) {
                check = false;
            }
        }
        if (check) {
            siz.insert(sz);
        }
    }
    for (le = 1; le < n; le++) {
        for (int sz = 1; sz <= m; sz++) {
            bool check = true;
            int i = 0;
            for (i = 0; i + sz - 1 < m; i += sz) {
                ll h1 = kek.get_hash(le, 0, le, sz - 1);
                ll h2 = kek.get_hash(le, i, le, i + sz - 1);
                if (h1 != h2) {
                    check = false;
                    break;
                }
            }
            if (i < m) {
                ll h1 = kek.get_hash(le, 0, le, m - 1 - i);
                ll h2 = kek.get_hash(le, i, le, m - 1);
                if (h1 != h2) {
                    check = false;
                }
            }
            if (!check && siz.find(sz) != siz.end()) {
                siz.erase(sz);
            }
        }
    }
    int sz = *siz.begin();
    for (int val = 0; val < n - 1; val++) {
        for (int sdvig = 0; sdvig < m; sdvig++) {
            int p1x = n - val - 2;
            int p1y = m - sdvig - 1;
            ll h1 = kek.get_hash(0, 0, p1x, p1y);
            int p2x = val + 1;
            int p2y = sdvig;
            ll h2 = kek.get_hash(p2x, p2y, n - 1, m - 1);
            if (p2x > p1x + 1 || p2y > p1y + 1) break;
            if (h1 == h2) {
                writeInt(val + 1);
                writeChar(' ');
                writeInt(sz);
                writeChar(' ');
                writeInt(sdvig);
                return 0;
            }
        }
    }
    writeInt(n + 1);
    writeChar(' ');
    writeInt(sz);
    writeChar(' ');
    writeInt(0);
}