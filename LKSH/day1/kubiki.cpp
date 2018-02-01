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

struct Hash {
    vector<ll> h, h2, step;
    ll p = 100003;
    ll mod = 1e9 + 9;
    void init(const vector<int> s) {
        int n = (int)s.size();
        h.resize(n), step.resize(n + 1);
        h2.resize(n);
        h2[0] = s[n - 1];
        h[0] = s[0]; step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i];
            h2[i] = h2[i - 1] * p + s[n - i - 1];
            if (h[i] >= mod) h[i] %= mod;
            if (h2[i] >= mod) h2[i] %= mod;
            step[i] = step[i - 1] * p;
            if (step[i] >= mod) step[i] %= mod;
        }
        step[n] = step[n - 1] * p;
        if (step[n] >= mod) step[n] %= mod;
    }
    ll get_hash_one(int l, int r) {
        ll ret = h[r] - (l ? (h[l - 1] * step[r - l + 1]) % mod : 0);
        if (ret < 0) ret += mod;
        return ret;
    }
    ll get_hash_two(int l, int r) {
        ll ret = h2[r] - (l ? (h2[l - 1] * step[r - l + 1]) % mod : 0);
        if (ret < 0) ret += mod;
        return ret;
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
        freopen("cubes.in", "r", stdin); 
        freopen("cubes.out", "w", stdout);
    #endif
    int n = getint(), m = getint();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = getint();
    }
    Hash ah;
    ah.init(a);
    vector<int> ans;
    for (int i = 1; i <= n / 2; i++) {
        ll h1 = ah.get_hash_one(0, i - 1);
        int sz = i - 1;
        ll h2 = ah.get_hash_two(n - 1 - i - sz, n - i - 1);
        if (h1 == h2) {
            ans.pb(n - i);
        }
    }
    ans.pb(n);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}   