#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

}
