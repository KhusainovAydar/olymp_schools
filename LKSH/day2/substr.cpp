#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

struct Hash {
    vector<ll> h, step;
    ll p = 29;
    ll mod = 42424243;
    void init(const string & s) {
        int n = (int)s.length();
        h.resize(n), step.resize(n + 1);
        h[0] = s[0]; step[0] = 1;
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

struct Hash_table {
    vector <ll> H;
    int was;
    Hash_table() {
        H = vector <ll>(100000, -1);
        was = 0;
    }
    void rebuild() {
        vector <ll> C;
        for (auto i : H) {
            if (i > -1) {
                C.push_back(i);
            }
        }
        H.resize(H.size() * 2, -1);
        was = 0;
        for (auto i : C) {
            add(i);
        }
    }
    void add(ll h) {
        if (count(h)) {
            return;
        }
        ll x = h % (ll)H.size();
        while (H[x] != -1) {
            x++;
            x %= (ll)H.size();
        }
        H[x] = h;
        was++;
        if (was * 2 >= (ll)H.size()) {
            rebuild();
        }
    }
    bool count(ll h) {
        ll x = h % (ll)H.size();
        while (H[x] != -1) {
            if (H[x] == h) {
                return 1;
            }
            x++;
            x %= (ll)H.size();
        }
        return 0;
    }
    int sz() {
        return was;
    }
};

Hash_table one, two;

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("substr.in", "r", stdin);
    freopen("substr.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> a;
    vector<Hash> m(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
        m[i].init(s);
    }
    int l = 0, r = 1488228;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        one = Hash_table();
        two = Hash_table();
        for (int i = 0; i + mid < a[0].size(); i++) {
            one.add(m[0].get_hash(i, i + mid));
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + mid < a[i].size(); j++) {
                if (one.count(m[i].get_hash(j, j + mid))) {
                    two.add(m[i].get_hash(j, j + mid));
                }
            }
            one = two;
            two = Hash_table();
        }
        if (one.sz() == 0) r = mid;
        else l = mid;
    }
    one = Hash_table(); two = Hash_table();
    for (int i = 0; i + l < a[0].size(); i++) {
        one.add(m[0].get_hash(i, i + l));
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + l < a[i].size(); j++) {
            if (one.count(m[i].get_hash(j, j + l))) {
                two.add(m[i].get_hash(j, j + l));
            }
        }
        one = two;
        two = Hash_table();
    }
    for (int i = 0; i + l < a[0].size(); i++) {
        if (one.count(m[0].get_hash(i, i + l))) {
            for (int j = i; j <= i + l; j++) {
                cout << a[0][j];
            }
            return 0;
        }
    }
}