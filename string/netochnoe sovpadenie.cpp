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


struct Hash {
    ll p = 259, mod = 42424243;
    vector<ll> h, step;
    inline void init(const string & s) {
        int n = (int)s.length();
        h.resize(n);
        step.resize(n + 1);
        h[0] = s[0];
        step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i];
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

int main() {
    //ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("inexact-matching.in", "r", stdin); 
        freopen("inexact-matching.out", "w", stdout);
    #endif
    string p, s;
    cin >> p >> s;
    Hash ph, sh;
    ph.init(p); 
    sh.init(s);
    int szp = (int)p.size();
    int szs = (int)s.size();
    //cout << szs << endl;
    vector<int> ans;
    for (int i = 0; i <= (int)s.size() - (int)p.size(); i++) {
        int l = 0, r = szp;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (ph.get_hash(0, m - 1) == sh.get_hash(i, i + m - 1)) {
                l = m;
            } else r = m;
        }
        if (l >= szp - 1) {
            ans.pb(i);
            continue;
        }
        //cout << l << ' ' << r << endl;
        if (ph.get_hash(l + 1, szp - 1) == sh.get_hash(i + l + 1, i + szp - 1)) {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << ' ';
    }
}   