#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Hash {
    vector<ll> h[2], step[2];
    ll p[2] = {259, 29}, mod[2] = {1000000009, 1000000007};
    
    ll getmod(ll x, int id) {
        if (x > mod[id]) {
            x %= mod[id];
        }
        while (x < 0) x += mod[id];
        return x;
    }
    
    inline void init(const string & s) {
        int n = (int)s.size();
        
        for (int i = 0; i < 2; i++) {
            h[i].resize((unsigned long) n);
            step[i].resize((unsigned long) (n + 1));
            h[i][0] = s[0];
            step[i][0] = 1;
        }
        
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < 2; i++) {
                h[i][j] = getmod(h[i][j - 1] * p[i] + s[j], i);
                step[i][j] = getmod(step[i][j - 1] * p[i], i);
            }
        }
        
        for (int i = 0; i < 2; i++) {
            step[i][n] = getmod(step[i][n - 1] * p[i], i);
        }
    }
    
    pair<ll, ll> get_hash(int l, int r) {
        ll ret[2];
        for (int i = 0; i < 2; i++) {
            ret[i] = getmod(h[i][r] - (l ? getmod(h[i][l - 1] * step[i][r - l + 1], i) : 0), i);
        }
        return {ret[0], ret[1]};
    };
};


int main() {

}
