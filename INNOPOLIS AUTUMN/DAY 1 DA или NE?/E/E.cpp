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

ll A = 13, B = 19, X = 223, Y = 239, Z = 97, MOD = 1e9 + 993;

ll myrand(){
    ll C = (A * X + B * Y + Z) % MOD;
    A = B;
    B = C;
    return A;
}

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

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

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
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

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

const int NMAX = 1e6 + 6;

struct HASH{
    size_t operator()(const pair<ll, ll> & x) const {
        return hash<ll> () (((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

unordered_map< pair<ll, ll>, ll, HASH> mp;

vector<int> a;
ll h[NMAX], h2[NMAX];

int par[NMAX], rang[NMAX];
ll val[NMAX], val2[NMAX];
ll Hash[NMAX], Hash2[NMAX], sz[NMAX];

int cnt = 0, cur = 0;
int ans = 0;
inline void make_set(int v) {
    par[v] = v;
    rang[v] = 0;
    val[v] = h[a[v]];
    val2[v] = h2[a[v]];
    sz[v] = 1;
}

int find_set(int v) {
    return (v == par[v]) ? v : (par[v] = find_set(par[v]));
}

inline void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) {
        if (rang[x] < rang[y]) swap(x, y);
        if (Hash[x] == val[x] && Hash2[x] == val2[x]) {
            cur--;
        } else {
            ll w = mp[{Hash[x] - val[x], Hash2[x] - val2[x]}];
            ans -= sz[x] * w;
            mp[{val[x] - Hash[x], val2[x] - Hash2[x]}] -= sz[x];
        }
        if (Hash[y] == val[y] && Hash2[y] == val2[y]) {
            cur--;
        } else {
            ll w = mp[{Hash[y] - val[y], Hash2[y] - val2[y]}];
            ans -= sz[y] * w;
            mp[{val[y] - Hash[y], val2[y] - Hash2[y]}] -= sz[y];
        }
        par[y] = x;
        val[x] += val[y];
        val2[x] += val2[y];
        Hash2[x] += Hash2[y];
        Hash[x] += Hash[y];
        sz[x] += sz[y];
        cnt--;
        if (Hash[x] == val[x] && Hash2[x] == val2[x]) {
            cur++;
        } else {
            ll w = mp[{Hash[x] - val[x], Hash2[x] - val2[x]}];
            ans += sz[x] * w;
            mp[{val[x] - Hash[x], val2[x] - Hash2[x]}] += sz[x];
        }
        if (rang[x] == rang[y])
            rang[x]++;
    }
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //        freopen("magic.in", "r", stdin);
    //        freopen("magic.out", "w", stdout);
#endif
    int n = readInt(), q = readInt();
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    for (int i = 0; i < NMAX; i++) {
        h[i] = myrand();
        h2[i] = myrand();
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        Hash[i] = h[b[i]];
        Hash2[i] = h2[b[i]];
    }
    
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    for (int i = 0; i < n; i++) {
        if (Hash[i] != val[i] || Hash2[i] != val2[i]) {
            ll x = mp[{Hash[i] - val[i], Hash2[i] - val2[i]}];
            ans += sz[i] * x;
            mp[{val[i] - Hash[i], val2[i] - Hash2[i]}] += sz[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            cur++;
        }
        cnt++;
    }
    //    cout << ans << endl;
    //    int ans2 = 0;
    //
    //    for (int i = 0; i < n; i++) {
    //        for (int j = i + 1; j < n; j++) {
    //            if (find_set(i) == find_set(j))
    //                continue;
    //            int id1 = find_set(i);
    //            int id2 = find_set(j);
    //            if (Hash[id1] != val[id1] && Hash[id2] != val[id2]) {
    //                if (Hash[id1] - val[id1] == val[id2] - Hash[id2]) {
    //                    ans2++;
    //                }
    //            }
    //        }
    //    }
    //    cout << ans2 << endl;
    while (q--) {
        int t;
        t = readInt();
        if (t == 1) {
            int x = readInt(), y = readInt();
            x--, y--;
            int id1 = find_set(x);
            int id2 = find_set(y);
            if (Hash[id1] == val[id1] && Hash2[id1] == val2[id1]) {
                cur--;
            } else {
                ll w = mp[{Hash[id1] - val[id1], Hash2[id1] - val2[id1]}];
                ans -= sz[id1] * w;
                mp[{val[id1] - Hash[id1], val2[id1] - Hash2[id1]}] -= sz[id1];
            }
            if (Hash[id2] == val[id2] && Hash2[id2] == val2[id2]) {
                cur--;
            } else {
                ll w = mp[{Hash[id2] - val[id2], Hash2[id2] - val2[id2]}];
                ans -= sz[id2] * w;
                mp[{val[id2] - Hash[id2], val2[id2] - Hash2[id2]}] -= sz[id2];
            }
            
            val[id1] -= h[a[x]];
            val[id1] += h[a[y]];
            
            val2[id1] -= h2[a[x]];
            val2[id1] += h2[a[y]];
            
            val[id2] -= h[a[y]];
            val[id2] += h[a[x]];
            
            val2[id2] -= h2[a[y]];
            val2[id2] += h2[a[x]];
            swap(a[x], a[y]);
            if (Hash[id1] == val[id1] && Hash2[id1] == val2[id1]) {
                cur++;
            } else {
                ll w = mp[{Hash[id1] - val[id1], Hash2[id1] - val2[id1]}];
                ans += sz[id1] * w;
                mp[{val[id1] - Hash[id1], val2[id1] - Hash2[id1]}] += sz[id1];
            }
            if (Hash[id2] == val[id2] && Hash2[id2] == val2[id2]) {
                cur++;
            } else {
                ll w = mp[{Hash[id2] - val[id2], Hash2[id2] - val2[id2]}];
                ans += sz[id2] * w;
                mp[{val[id2] - Hash[id2], val2[id2] - Hash2[id2]}] += sz[id2];
            }
        }
        if (t == 2) {
            int x, y;
            x = readInt(), y = readInt();
            x--, y--;
            union_sets(x, y);
        }
        if (t == 3) {
            if (cnt == cur) {
                writeChar('D');
                writeChar('A');
                writeChar(endl);
            } else {
                writeChar('N');
                writeChar('E');
                writeChar(endl);
            }
        }
        if (t == 4) {
            writeInt(ans);
            writeChar(endl);
            //            int ans2 = 0;
            //
            //            for (int i = 0; i < n; i++) {
            //                for (int j = i + 1; j < n; j++) {
            //                    if (find_set(i) == find_set(j))
            //                        continue;
            //                    int id1 = find_set(i);
            //                    int id2 = find_set(j);
            //                    if (Hash[id1] != val[id1] && Hash[id2] != val[id2]) {
            //                        if (Hash[id1] - val[id1] == val[id2] - Hash[id2]) {
            //                            ans2++;
            //                        }
            //                    }
            //                }
            //            }
            //            cout << ans2 << endl;
        }
    }
}