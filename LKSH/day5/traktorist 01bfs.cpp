#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1001;

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool mas[NMAX][NMAX];
int dist[9][NMAX][NMAX];

int n, m;
struct fise {
    int C, X, Y;
};

int x1, y1, x2, y2;

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.')
                mas[n - i - 1][j] = true;
            else mas[n - i - 1][j] = false;
        }
    }
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    for (int c = 0; c < 8; c++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[c][i][j] = -1;
            }
        }
    }
    deque<fise> q;
    for (int i = 0; i < 8; i++) {
        q.push_back({i, x1, y1});
        dist[i][x1][y1] = 1;
    }
    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        int val = q.front().C;
        q.pop_front();
        for (int i = 0; i < 8; i++) {
            if (i == val) {
                int nx = x + dx[val];
                int ny = y + dy[val];
                int nd = dist[val][x][y];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || !mas[nx][ny]) continue;
                if (dist[val][nx][ny] == -1 || dist[val][nx][ny] > nd) {
                    dist[val][nx][ny] = nd;
                    q.push_front({val, nx, ny});
                }
            } else {
                int nx = x;
                int ny = y;
                int nd = dist[val][x][y] + 1;
                if (dist[i][nx][ny] == -1) {
                    dist[i][nx][ny] = nd;
                    q.push_back({i, nx, ny});
                }
            }
        }
    }
    int nd = INT_MAX - 1;
    for (int c = 0; c < 8; c++) {
        nd = min(nd, dist[c][x2][y2]);
    }
    cout << nd;
}