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

typedef long long ll;

vector< vector<int> > proc() {
    int n = (1 << 18) - 1;
    vector<int> a((unsigned long) (n / 2 + 1), 0), b((unsigned long) (n / 2));
    vector< vector<int> > v = *new vector< vector<int> > ((unsigned long) 18, vector<int> ((unsigned long) n));
    for (int i = 0; i < 18; i++) {
        a.resize(0);
        b.resize(0);
        for (int j = 0; j < n; j++) {
            if ((j >> i) & 1) {
                b.pb(j);
            } else {
                a.pb(j);
            }
        }
        for (int j = 0; j < (int)a.size(); j++) {
            v[i][j] = a[j];
        }
        for (int j = 0; j < (int)b.size(); j++) {
            v[i][j + a.size()] = b[j];
        }
    }
    //cerr << endl;
    return v;
}

vector<int> ans(vector< vector<int> > &v, int A, int n) {
    vector<int> anss = *new vector<int> ((unsigned long) n);
    int uk = 0;
    for (int i = 0; i < 31; i++, uk = (uk + 1) % 18) {
        vector<int> a((unsigned long) (0)), b((unsigned long) (0));
        for (int j = 0; j < v[uk].size(); j++) {
            if (v[uk][j] < n) {
                if (j < ((1 << 18) - 1) / 2 + 1) {
                    a.pb(v[uk][j]);
                } else {
                    b.pb(v[uk][j]);
                }
            }
        }
        if ((1 << uk) > n)
            uk = -1;
        if (a.size() % 2) {
            swap(a, b);
        }
        if ((A >> i) & 1) {
            for (auto j : b) {
                anss[j] += (1 << i);
            }
        } else {
            for (auto j : a) {
                anss[j] += (1 << i);
            }
        }
    }
    return anss;
}

void vd(int n, int A) {
    map<int, bool> mp;
    vector<int> a((unsigned long) n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = ((ll)rand() * (ll)rand() + rand()) % (1ll << (31));
        while (!x || mp[x]) x = (rand() * rand() + rand()) % (1 << (31));
        ans ^= x;
        a[i] = x;
        mp[x] = 1;
    }
    if (!mp[(A ^ ans)] && ans != A) {
        for (int i = 0; i < n - 1; i++) {
            cout << a[i] << ' ';
        }
        cout << (A ^ ans);
        exit(0);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#endif
    vector< vector<int> > v = proc();
    int n, A;
    cin >> n >> A;
    if (n == 1 && A == 0) {
        cout << -1;
        return 0;
    }
    if (n == 2 && A == 0) {
        cout << -1;
        return 0;
    }
    if (n == 2 && A == 2147483647) {
        cout << (A ^ 1) << " " << 1 << endl;
        return 0;
    }
    if (n == 2 && A != 0) {
        cout << 2147483647 << " "  << (A ^ 2147483647) << endl;
        return 0;
    }
    if (n < 1000) {
        for (int i = 0; i < 50; i++) {
            vd(n, A);
        }
        cout << -1;
        return 0;
    }
    int dxor = 0;
    int cur = 0;
    while (true) {
        vector<int> Ans;
        if (n & 1) {
            Ans = ans(v, A ^ dxor, n);
            for (auto &i : Ans) {
                i ^= dxor;
            }
        } else {
            Ans = ans(v, (A ^ ((1 << 31) - 1)), n - 1);
            for (auto &i : Ans) {
                i ^= dxor;
            }
            Ans.pb((1 << 31) - 1);
        }
        set<int> used(Ans.begin(), Ans.end());
        if (used.size() == n && !used.count(0)) {
            int k = 0;
            for (auto t : Ans) {
                k ^= t;
            }
            if (k == A) {
                for (auto t : Ans) {
                    cout << t << ' ';
                }
                return 0;
            }
        }
        dxor = (int) (((ll) rand() * 1000 + (ll) rand()) % (1 << (31)));
        cur++;
        if (cur == 35) {
            cout << -1;
            return 0;
        }
    }
}