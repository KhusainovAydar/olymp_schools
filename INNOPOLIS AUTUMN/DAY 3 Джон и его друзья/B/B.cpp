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

typedef long long ll;

const int NMAX = 600;
int n;
int a[NMAX][NMAX];
bool used[NMAX][NMAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0;

bool ch(int x, int y) {
    return !used[x][y] && 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y, int val) {
    used[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ch(nx, ny) && abs(a[x][y] - a[nx][ny]) <= val) {
            dfs(nx, ny, val);
        }
    }
}

int main() {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int L = 0, R = 1000005;
    while (R - L > 1) {
        
        bool ans = false;
        int M = (L + R) >> 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                used[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!used[i][j]) {
                    cnt = 0;
                    dfs(i, j, M);
                    if (cnt * 2 >= n * n) {
                        ans = true;
                    }
                }
            }
        }
        if (ans) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R;
}