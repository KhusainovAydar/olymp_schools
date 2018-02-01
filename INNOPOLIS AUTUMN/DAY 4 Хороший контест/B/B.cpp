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

typedef unsigned long long ll;

struct Hash {
    vector<ll> h, step;
    ll p = 29;
    ll mod = 42424243;
    void init (const string & s) {
        int n = (int)s.length();
        h.resize(n), step.resize(n + 1);
        h[0] = s[0]; step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i];
            //if (h[i] >= mod) h[i] %= mod;
            step[i] = step[i - 1] * p;
            //if (step[i] >= mod) step[i] %= mod;
        }
        step[n] = step[n - 1] * p;
        //if (step[n] >= mod) step[n] %= mod;
    }
    ll get_hash(int l, int r) {
        ll ret = h[r] - (l ? (h[l - 1] * step[r - l + 1]) : 0);
        //if (ret < 0) ret += mod;
        return ret;
    }
};

vector<int> prefix_function (const string & s) {
    int n = (int) s.length();
    vector<int> p (n);
    for (int i = 1; i < n; ++i) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])  ++j;
        p[i] = j;
    }
    return p;
}




int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
#endif
    string s;
    cin >> s;
    vector<int> ans = prefix_function(s);
    for (auto t : ans) {
        cout << t << ' ';
    }
    //    string s;
    //    cin >> s;
    //    Hash sh;
    //    sh.init(s);
    //    int n;
    //    cin >> n;
    //    for (int i = 0; i < n; i++) {
    //        string x;
    //        Hash mem;
    //        cin >> x;
    //        mem.init(x);
    //        if (x.size() > s.size()) {
    //            cout << "No" << endl;
    //            continue;
    //        }
    //        int sz = (int)x.size();
    //        bool ans = 0;
    //        for (int j = 0; j <= (int)s.length() - (int)x.size(); j++) {
    //            if (sh.get_hash(j, j + sz - 1) == mem.get_hash(0, sz - 1)) {
    //                ans = 1;
    //                break;
    //            }
    //        }
    //        if (ans) {
    //            cout << "Yes" << endl;
    //        } else {
    //            cout << "No" << endl;
    //        }
    //    }
}