#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

struct HASH {
    vector<ll> h, step;
    ll p = 259;
    ll mod = 1e9 + 9;
    void init(const string & s) {
        int n = (int)s.length();
        h.resize(n), step.resize(n + 1);
        h[0] = s[0] - 'a'; step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i] - 'a';
            if (h[i] >= mod) h[i] %= mod;
            step[i] = step[i - 1] * p;
            if (step[i] >= mod) step[i] %= mod;
        }
        step[n] = step[n - 1] * p;
        if (step[n] >= mod) step[n] %= mod;
    }
    ll get_hash(int l, int r) {
        ll ret = h[r] - (l ? (h[l - 1] * step[r - l + 1]) % mod : 0);
        if (ret < 0) ret += mod;
        return ret;
    }
};

struct Hash {
    ll p = 259, p2 = 227, mod1 = 1e9 + 9, mod2 = 42424243;
    vector<ll> h1, h2, step1, step2;

    inline void init(const string & s) {
        int n = (int)s.length();
        h1.resize(n);
        step1.resize(n + 1);
        h2.resize(n);
        step2.resize(n + 1);
        h1[0] = s[0] - 'a';
        h2[0] = s[0] - 'a';
        step1[0] = 1;
        step2[0] = 1;

        for (int i = 1; i < n; i++) {
            h1[i] = h1[i - 1] * p + s[i] - 'a';
            h2[i] = h2[i - 1] * p2 + s[i] - 'a';
            if (h1[i] >= mod1) h1[i] %= mod1;
            if (h2[i] >= mod2) h2[i] %= mod2;
            step1[i] = step1[i - 1] * p;
            step2[i] = step2[i - 1] * p;
            if (step1[i] >= mod1) step1[i] %= mod1;
            if (step2[i] >= mod2) step2[i] %= mod2;
        }
        step1[n] = step1[n - 1] * p;
        step2[n] = step2[n - 1] * p2;
        if (step1[n] >= mod1) step1[n] %= mod1;
        if (step2[n] >= mod2) step2[n] %= mod2;
    }

    pair<ll, ll> get_hash(int l, int r) {
        ll ret1 = h1[r] - (l ? (h1[l - 1] * step1[r - l + 1]) % mod1 : 0);
        if (ret1 < 0) ret1 += mod1;

        ll ret2 = h2[r] - (l ? (h2[l - 1] * step2[r - l + 1]) % mod2 : 0);
        if (ret2 < 0) ret2 += mod2;
        
        return {ret1, ret2};
    }
};

inline int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}

inline char get() {
    char c = getchar();
    while (c <= 32) c = getchar();
    return c;
}

inline string getstr() {
    string ans = "";
    char c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) {
        ans += c;
        c = getchar();
    }
    return ans;
}

map< pair<ll, ll>, pair<int, int> > mp;

string gen() {
    int n = 10;
    string a = "";
    for (int i = 0; i < n; i++) {
        a += char(rand() % 26 + 'a');
    }
    return a;
}

string stupid(string s) {
    string a = s + s;
    vector<string> v;
    for (int i = 0; i < s.length(); i++) {
        string kek = "";
        for (int j = i; j < i + s.length(); j++) {
            kek += a[j];
        }
        v.pb(kek);
    }
    sort(v.begin(), v.end());
    return v[0];
}

int main() {
    //ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("cyclic-shift.in", "r", stdin); 
        freopen("cyclic-shift.out", "w", stdout);
    #endif
    int cnt = 0;
    cout.flush();
    //for (int test = 0; test < 7; test++) {
        string s = getstr();
        string a = s + s;
        Hash ah, sh;
        pair<int, int> ans = {0, (int)s.length() - 1};
        ah.init(a); sh.init(s);
        int n = (int)s.length();
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            if (a[ans.fi] != a[i]) {
                if (a[i] < a[ans.fi]) {
                    ans.fi = i;
                    ans.se = i + n - 1;
                }
                continue;
            }
            while (r - l > 1) {
                int m = (l + r) >> 1;
                pair<ll, ll> afi = ah.get_hash(i, i + m);
                pair<ll, ll> ase = ah.get_hash(ans.fi, ans.fi + m);
                if (afi.fi == ase.fi && ase.se == ase.se) {
                    l = m;
                } else r = m;
            }
            if (a[i + l + 1] != a[ans.fi + l + 1]) {
                if (a[ans.fi + l + 1] > a[i + l + 1]) {
                    ans.fi = i;
                    ans.se = i + n - 1;
                }
            }
        }
        string answer = "";
        for (int i = ans.fi; i <= ans.se; i++) {
            answer += a[i];
        }
        cout << answer << endl;
    //}
    //cout << cnt;
}       