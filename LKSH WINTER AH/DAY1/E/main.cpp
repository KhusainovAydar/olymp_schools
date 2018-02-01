#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef unsigned long long ll;

struct Hash {
    vector<ll> h, step;
    ll p = 259;
    inline void init(const string & s) {
        int n = (int)s.size();
        h.resize((unsigned long) n); step.resize((unsigned long) (n + 1));
        h[0] = (unsigned long long int) s[0];
        step[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * p + s[i];
            step[i] = step[i - 1] * p;
        }
        step[n] = step[n - 1] * p;
    }
    ll get_hash(int l, int r) {
        return h[r] - (l ? h[l - 1] * step[r - l + 1] : 0);
    }
};

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("stragain.in", "r", stdin);
    freopen("stragain.out", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    Hash ah, bh;
    ah.init(a);
    bh.init(b);
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            vector<ll> A(3);
            int sz[3];
            sz[0] = i + 1;
            sz[1] = (j - (i + 1) + 1);
            sz[2] = ((n - 1) - (j + 1) + 1);
            A[0] = bh.get_hash(0, i);
            A[1] = bh.get_hash(i + 1, j);
            A[2] = bh.get_hash(j + 1, n - 1);
            vector<int> perm(3);
            for (int y = 0; y < 3; y++) {
                perm[y] = y;
            }
            do {
                int x = 0;
                x = 0;
                if (A[perm[0]] == ah.get_hash(x, x + sz[perm[0]] - 1)) {
                    x += sz[perm[0]];
                    if (A[perm[1]] == ah.get_hash(x, x + sz[perm[1]] - 1)) {
                        x += sz[perm[1]];
                        if (A[perm[2]] == ah.get_hash(x, x + sz[perm[2]] - 1)) {
                            cout << "YES" << endl;
                            for (int q = 0; q < 3; q++) {
                                if (perm[q] == 0) {
                                    for (int out = 0; out <= i; out++) {
                                        cout << b[out];
                                    }
                                    cout << endl;
                                }
                                if (perm[q] == 1) {
                                    for (int out = i + 1; out <= j; out++) {
                                        cout << b[out];
                                    }
                                    cout << endl;
                                }
                                if (perm[q] == 2) {
                                    for (int out = j + 1; out < n; out++) {
                                        cout << b[out];
                                    }
                                    cout << endl;
                                }
                            }
                            return 0;
                        }
                    }
                }
//                for (int q = 0; q < 3; q++) {
//                    if (perm[q] == 0) {
//                        for (int out = 0; out <= i; out++) {
//                            cerr << b[out];
//                        }
//                        cerr << endl;
//                    }
//                    if (perm[q] == 1) {
//                        for (int out = i + 1; out <= j; out++) {
//                            cerr << b[out];
//                        }
//                        cerr << endl;
//                    }
//                    if (perm[q] == 2) {
//                        for (int out = j + 1; out < n; out++) {
//                            cerr << b[out];
//                        }
//                        cerr << endl;
//                    }
//                }
//                cerr << endl;
            } while (next_permutation(perm.begin(), perm.end()));
        }
    }
    cout << "NO";
}