#include <bits/stdc++.h>

using namespace std;

const int n = 2022, m = 2022;

bool used[3000][3000];

struct Point {
    int x, y;
};

const int kek = 1010;
queue<Point> qq;
int head, sz;

Point start, finish;

void bfs() {
    qq.push(start);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            used[i][j] = false;
        }
    }
    vector<vector<int> > d (n, vector<int> (m));
    d[start.x + kek][start.y + kek] = 0;
    used[start.x + kek][start.y + kek] = true;
    while (!qq.empty()) {
        Point v = qq.front();
        qq.pop();
        if (v.x == finish.x && v.y == finish.y)
            break;
        if (v.x + 1 < 1001 && !used[v.x + 1 + kek][v.y + kek] && v.y % 2 != 0) {
            Point lol = v;
            lol.x++;
            qq.push(lol);
            d[v.x + 1 + kek][v.y + kek] = d[v.x + kek][v.y + kek] + 1;
            used[v.x + 1 + kek][v.y + kek] = true;
        }
        if (v.y + 1 < 1001 && !used[v.x + kek][v.y + 1 + kek] && v.x % 2 != 0) {
            Point lol = v;
            lol.y++;
            qq.push(lol);
            d[v.x + kek][v.y + 1 + kek] = d[v.x + kek][v.y + kek] + 1;
            used[v.x + kek][v.y + 1] = true;
        }
        if (v.x - 1 >= -1000 && !used[v.x - 1 + kek][v.y + kek] && v.y % 2 == 0) {
            Point lol = v;
            lol.x--;
            qq.push(lol);
            d[v.x - 1 + kek][v.y + kek] = d[v.x + kek][v.y + kek] + 1;
            used[v.x - 1 + kek][v.y + kek] = true;
        }
        if (v.y - 1 >= -1000 && !used[v.x + kek][v.y - 1 + kek] && v.x % 2 == 0) {
            Point lol = v;
            lol.y--;
            qq.push(lol);
            d[v.x + kek][v.y - 1 + kek] = d[v.x + kek][v.y + kek] + 1;
            used[v.x + kek][v.y - 1 + kek] = true;
        }
    }
    cout << d[finish.x + kek][finish.y + kek] << ' ' << '\n';
    exit(0);
}

 main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //freopen("area.in", "r", stdin);freopen("area.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    cin >> start.x >> start.y >> finish.x >> finish.y;
    bfs();
    return 0;
}
