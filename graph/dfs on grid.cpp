#include <bits/stdc++.h>

using namespace std;

int n, m;

char mas[100][100];

bool alfa[26];

bool used[100][100];

struct Point {
    int x, y;
};

void End (bool b) {
    if (b)
        cout << "Yes";
    else
        cout << "No";
    exit(0);
}

void dfs (Point v, Point pred) {
    used[v.x][v.y] = true;
    if (v.x + 1 != pred.x && v.x + 1 < n && mas[v.x][v.y] == mas[v.x + 1][v.y]) {
        if (used[v.x + 1][v.y]) {
            End(true);
            return ;
        }
        Point to = v;
        to.x++;
        dfs(to, v);
    }
    if (v.x - 1 != pred.x && v.x - 1 >= 0 && mas[v.x][v.y] == mas[v.x - 1][v.y]) {
        if (used[v.x - 1][v.y]) {
            End(true);
            return ;
        }
        Point to = v;
        to.x--;
        dfs(to, v);
    }
    if (v.y + 1 != pred.y && v.y + 1 < m && mas[v.x][v.y] == mas[v.x][v.y + 1]) {
        if (used[v.x][v.y + 1]) {
            End(true);
            return ;
        }
        Point to = v;
        to.y++;
        dfs(to, v);
    }
    if (v.y - 1 != pred.y && v.y - 1 >= 0 && mas[v.x][v.y] == mas[v.x][v.y - 1]) {
        if (used[v.x ][v.y - 1]) {
            End(true);
            return ;
        }
        Point to = v;
        to.y--;
        dfs(to, v);
    }
}


 main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //freopen("tangent.in", "r", stdin);freopen("tangent.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Point s;
            s.x = i;
            s.y = j;
            for (int y = 0; y < n; y++) {
                for (int u = 0; u < m; u++)
                    used[y][u] = false;
            }
            dfs(s, s);
        }
    }
    End(false);

}
