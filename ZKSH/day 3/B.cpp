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

const int NMAX = 1000004;
int used[NMAX];
int n, s;

void find_ans(int l, int r) {
    while (r - l > 1) {
        int m = (l + r) >> 1;
        int val;
        if (!used[m]) {
            cout << m << endl;
//            cnt++;
            cin >> val;
            used[m] = val;
        } else {
            val = used[m];
        }
        if (val == s) {
//            cout << "CNT " << cnt << endl;
            exit(0);
        }
        if (val > s) {
            r = m;
        } else {
            l = m;
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
    cin >> n >> s;
    int cnt = 0;
    cout << 1 << endl;
    cnt++;
    int x;
    cin >> x;
    used[1] = x;
    if (x == s) {
        return 0;
    }
    cout << n << endl;
    int y;
    cin >> y;
    used[n] = y;
    if (y == s) {
        return 0;
    }
    if (y > x) {
        find_ans(1, n);
    }
    int L = 1, R = n;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        int val;
        if (used[M]) {
            val = used[M];
        } else {
            cout << M << endl;
            cin >> val;
            used[M] = val;
        }
        if (val == s) {
            return 0;
        }
        if (s > x && val > x) {
            if (val > s) {
                R = M;
            } else {
                L = M;
            }
            continue;
        }
        if (s > x && val < x) {
            R = M;
            continue;
        }
        if (val > x && s < x) {
            L = M;
            continue;
        }
        if (s < x && val < x) {
            if (val > s) {
                R = M;
            } else {
                L = M;
            }
            continue;
        }
    }
}