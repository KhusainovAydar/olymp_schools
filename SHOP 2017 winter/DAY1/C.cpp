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
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector< vector<int> > a;
int n, m;

bool ch1(int val, int x, int y) {
    bool used[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            used[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (abs(a[0][i] - x) <= val) {
            used[0][i] = 1;
        } else {
            break;
        }
    }


    if (!used[0][0]) {
        return false;
    }


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1 && j == m - 1) {
                break;
            }
            if (used[i - 1][j] && abs(a[i][j] - x) <= val) {
                used[i][j] = 1;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j]) {
                if (abs(a[i][j] - y) > val) {
                    return false;
                }
            } else {
                if (abs(a[i][j] - x) > val) {
                    return false;
                }
            }
        }
    }

    if (used[n - 1][m - 1]) {
        return false;
    }
    return true;
}

bool ch2(int val, int x, int y) {
    bool used[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            used[i][j] = 0;
        }
    }


    for (int i = m - 1; i >= 0; i--) {
        if (abs(a[0][i] - x) <= val) {
            used[0][i] = 1;
        } else {
            break;
        }
    }


    if (!used[0][m - 1]) {
        return false;
    }

    for (int i = 1; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == 0) {
                break;
            }
            if (used[i - 1][j] && abs(a[i][j] - x) <= val) {
                used[i][j] = 1;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j]) {
                if (abs(a[i][j] - y) > val) {
                    return false;
                }
            } else {
                if (abs(a[i][j] - x) > val) {
                    return false;
                }
            }
        }
    }

    if (used[n - 1][0]) {
        return false;
    }

    return true;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("substr3.in", "r", stdin);
//    freopen("subst3.out", "w", stdout);
#endif
    cin >> n >> m;
    vector<int> srt;
    int minn = 1000000050, maxx = 0;
    a.resize(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            minn = min(minn, a[i][j]);
            maxx = max(maxx, a[i][j]);
        }
    }


    int L = -1, R = 1000000000;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (ch1(M, minn, maxx) || ch1(M, maxx, minn) || ch2(M, minn, maxx) || ch2(M, maxx, minn)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R;
}