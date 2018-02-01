#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 513;
set<string> nnames[NMAX];

void proc(set<string> s, vector<int> num) {
    for (auto t : num) {
        vector<string> del;
        for (auto &k : nnames[t]) {
            string f = k;
            if (s.find(f) == s.end()) {
                del.pb(f);
            }
        }
        for (int i = 0; i < del.size(); i++) {
            nnames[t].erase(del[i]);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
//    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
//    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << "?" << endl;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            nnames[j].insert(s);
        }
    }

    for (int i = 0; i < 15; i++) {
        vector<int> zap;
        for (int j = 1; j <= n; j++) {
            if (((j >> i) & 1)) {
                zap.pb(j);
            }
        }
        if (zap.size() == 0) continue;
        cout << "?" << endl;
        cout << zap.size() << endl;
        for (int j = 0; j < zap.size(); j++) {
            cout << zap[j] << ' ';
        }
        cout << endl;
        int x;
        cin >> x;
        set<string> s;
        for (int j = 0; j < x; j++) {
            string p;
            cin >> p;
            s.insert(p);
        }
        proc(s, zap);
    }
    for (int it = 1; it <= 10; it++)
    for (int i = 1; i <= n; i++) {
        if (nnames[i].size() == 1) {
            for (int j = 1; j <= n; j++) {
                if (j == i) {
                    continue;
                }
                if (nnames[j].size() && nnames[j].find(*nnames[i].begin()) != nnames[j].end()) {
                    nnames[j].erase(*nnames[i].begin());
                }
            }
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        if (nnames[i].size())
            cout << *nnames[i].begin() << ' ';
    }
}