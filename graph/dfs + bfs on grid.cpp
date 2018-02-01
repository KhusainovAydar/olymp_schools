#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
    int x, y;
};

bool used[100][100];
char mas[151][151];
int n, m;

void dfs(Point a, char k) {
    used[a.x][a.y] = true;
    mas[a.x][a.y] = k;
    if (a.x + 1 < n && !used[a.x + 1][a.y] && mas[a.x + 1][a.y] != '.') {
        Point ax = a;
        ax.x++;
        dfs(ax, k);
    }
    if (a.x - 1 >= 0 && !used[a.x - 1][a.y] && mas[a.x - 1][a.y] != '.') {
        Point ax = a;
        ax.x--;
        dfs(ax, k);
    }
    if (a.y + 1 < m && !used[a.x][a.y + 1] && mas[a.x][a.y + 1] != '.') {
        Point ay = a;
        ay.y++;
        dfs(ay, k);
    }
    if (a.y - 1 >= 0 && !used[a.x][a.y - 1] && mas[a.x][a.y - 1] != '.') {
        Point ay = a;
        ay.y--;
        dfs(ay, k);
    }
}

int dist[100][100];

void bfs(Point a) {
    queue<Point> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            used[i][j] = false;
    }
    vector<vector<int>> d(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            d[i][j] = 0;
    }
    q.push(a);
    used[a.x][a.y] = true;
    d[a.x][a.y] = 0;
    dist[a.x][a.y] = 0;
    while (!q.empty()) {
        Point v = q.front();
        //cout << v.x << ' ' << v.y << endl;
        q.pop();
        if (mas[v.x][v.y] == 'B')
            continue;
        if (v.x + 1 < n && !used[v.x + 1][v.y] && mas[v.x + 1][v.y] != 'A') {
            Point p = v;
            p.x++;
            used[p.x][p.y] = true;
            d[p.x][p.y] = d[v.x][v.y] + 1;
            if (dist[p.x][p.y] != 0)
                dist[p.x][p.y] = min(dist[p.x][p.y], d[v.x][v.y] + 1);
            else
                dist[p.x][p.y] = d[v.x][v.y] + 1;
            if (mas[p.x][p.y] == 'B') {
            } else q.push(p);
        }
        if (v.x - 1 >= 0 && !used[v.x - 1][v.y] && mas[v.x - 1][v.y] != 'A') {
            Point p = v;
            p.x--;
            d[p.x][p.y] = d[v.x][v.y] + 1;
            used[p.x][p.y] = true;
            if (dist[p.x][p.y] != 0)
                dist[p.x][p.y] = min(dist[p.x][p.y], d[v.x][v.y] + 1);
            else
                dist[p.x][p.y] = d[v.x][v.y] + 1;
            if (mas[p.x][p.y] == 'B') {
            } else q.push(p);
        }
        if (v.y + 1 < m && !used[v.x][v.y + 1] && mas[v.x][v.y + 1] != 'A') {
            Point p = v;
            p.y++;
            d[p.x][p.y] = d[v.x][v.y] + 1;
            used[p.x][p.y] = true;
            if (dist[p.x][p.y] != 0)
                dist[p.x][p.y] = min(dist[p.x][p.y], d[v.x][v.y] + 1);
            else
                dist[p.x][p.y] = d[v.x][v.y] + 1;
            if (mas[p.x][p.y] == 'B') {
            } else q.push(p);
        }
        if (v.y - 1 >= 0 && !used[v.x ][v.y - 1] && mas[v.x][v.y - 1] != 'A') {
            Point p = v;
            p.y--;
            d[p.x][p.y] = d[v.x][v.y] + 1;
            used[p.x][p.y] = true;
            if (dist[p.x][p.y] != 0)
                dist[p.x][p.y] = min(dist[p.x][p.y], d[v.x][v.y] + 1);
            else
                dist[p.x][p.y] = d[v.x][v.y] + 1;
            if (mas[p.x][p.y] == 'B') {
            } else q.push(p);
        }
    }
}

 main() {
    freopen("pageant.in", "r", stdin); freopen("pageant.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        bool t = true;
        for (int j = 0; j < m; j++){
            if (mas[i][j] != '.') {
                Point kek;
                kek.x = i;
                kek.y = j;
                char k = 'A';
                dfs(kek, k);
                t = false;
                break;
            }
        }
        if (!t)
            break;
    }
    for (int i = 0; i < n; i++) {
        bool t = true;
        for (int j = 0; j < m; j++) {
            if (mas[i][j] != '.' && mas[i][j] != 'A') {
                Point kek;
                kek.x = i;
                kek.y = j;
                char k = 'B';
                dfs(kek, k);
                t = false;
                break;
            }
        }
        if (!t)
            break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mas[i][j] == 'A') {
                Point p;
                p.x = i; p.y = j;
                bfs(p);
            }
        }
    }
    int minn = 1488228;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mas[i][j] == 'B' && dist[i][j] != 0)
                minn = min(dist[i][j], minn);
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << minn - 1;
}
