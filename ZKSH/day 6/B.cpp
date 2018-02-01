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

const int NMAX = 1004;

int dx[] = {1, -1};
char Cans[NMAX][NMAX];

void out(int n, int m) {
    for (int pos1 = 1; pos1 <= n; pos1++) {
        for (int pos2 = 1; pos2 <= m; pos2++) {
            cout << Cans[pos1][pos2];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int xval = n * m;
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= xval; i++) {
        cnt++;
        xval -= i;
        ans.pb(i);
        if (i >= xval) {
            ans[ans.size() - 1] += xval;
            break;
        }
    }
    cout << cnt << endl;

    char C = 'A';
    int x = 1, y = 1;
    int d = 0;
    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << endl;
        cnt = ans[i];
        int X = x, Y = y;
        int cd = d;
        vector<bool> used(26, 0);
        for (int j = 0; j < ans[i]; j++) {
            if (Cans[Y][X - 1]) {
                used[Cans[Y][X - 1] - 'A'] = 1;
            }
            if (Cans[Y - 1][X]) {
                used[Cans[Y - 1][X] - 'A'] = 1;
            }
            if (Cans[Y][X + 1]) {
                used[Cans[Y][X + 1] - 'A'] = 1;
            }
            if (X == 1 && dx[cd] == -1) {
                Y++;
                cd = 1 - cd;
            } else if (X == m && dx[cd] == 1) {
                Y++;
                cd = 1 - cd;
            } else {
                X += dx[cd];
            }
        }
        for (int j = 0; j < 26; j++) {
            if (!used[j]) {
                C = char(j + 'A');
                break;
            }
        }
        X = x, Y = y;
        cd = d;
        for (int j = 0; j < ans[i]; j++) {
            Cans[Y][X] = C;
            if (X == 1 && dx[cd] == -1) {
                Y++;
                cd = 1 - cd;
            } else if (X == m && dx[cd] == 1) {
                Y++;
                cd = 1 - cd;
            } else {
                X += dx[cd];
            }
        }
        x = X, y = Y, d = cd;
//        out(n, m);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << Cans[i][j];
        }
        cout << endl;
    }
}
