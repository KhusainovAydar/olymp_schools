#include <bits/stdc++.h>

using namespace std;

int n, m;

char mas[2000][2000];

bool used[2000][2000];

struct Point {
    int x, y;
};

Point q[4000000];
int head, sz;

Point start, finish;

void bfs() {
    q[sz++] = start;
    vector<vector<bool> > used(n, vector<bool> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            used[i][j] = false;
        }
    }
    vector<vector<Point> > p (n, vector<Point> (m));
    Point e; e.x = -1; e.y = -1;
    p[start.x][start.y] = e;
    used[start.x][start.y] = true;
    while (sz > head) {
        Point v = q[head++];
        //cout << v.x << ' ' << v.y << endl;
        if (v.x == finish.x && v.y == finish.y)
            break;
        if (v.x + 1 < n && !used[v.x + 1][v.y] && mas[v.x + 1][v.y] == '.') {
            Point lol = v;
            lol.x++;
            q[sz++] = lol;
            p[v.x + 1][v.y] = v;
            used[v.x + 1][v.y] = true;
        }
        if (v.y + 1 < m && !used[v.x][v.y + 1] && mas[v.x][v.y + 1] == '.') {
            Point lol = v;
            lol.y++;
            q[sz++] = lol;
            p[v.x][v.y + 1] = v;
            used[v.x][v.y + 1] = true;
        }
        if (v.x - 1 >= 0 && !used[v.x - 1][v.y] && mas[v.x - 1][v.y] == '.') {
            Point lol = v;
            lol.x--;
            q[sz++] = lol;
            p[v.x - 1][v.y] = v;
            used[v.x - 1][v.y] = true;
        }
        if (v.y - 1 >= 0 && !used[v.x][v.y - 1] && mas[v.x][v.y - 1] == '.') {
            Point lol = v;
            lol.y--;
            q[sz++] = lol;
            p[v.x][v.y - 1] = v;
            used[v.x][v.y - 1] = true;
        }
    }
    if (!used[finish.x][finish.y]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<Point> ans;
        ans.push_back(finish);
        Point i = finish;
        while (i.x != e.x && i.y != e.y) {
            ans.push_back(p[i.x][i.y]);
            i = p[i.x][i.y];
        }
        for (int i = ans.size() - 2; i >= 0; i--) {
            printf("%d %d\n", ans[i].y + 1, ans[i].x + 1);
        }
    }
}

 main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    freopen("dfsongrid.in", "r", stdin);freopen("dfsongrid.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    cin >> m >> n;
    cin >> start.y >> start.x >> finish.y >> finish.x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = getchar();
            while (c <= 32) c = getchar();
            mas[i][j] = c;
        }
    }
    start.x--, start.y--, finish.x--, finish.y--;
    bfs();
}
