#include <bits/stdc++.h>

using namespace std;

int mas[1000][1000];
const int INF = 1488228;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        mas[a][b] = t;
        mas[b][a] = t;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                mas[i][j] = min(mas[i][j], mas[i][k] + mas[k][j]);
            }
        }
    }

    vector<pair<int, int>> maxx;
    for (int i = 0; i < n; i++) {
        pair<int, int> minn = {-1, -1};
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (mas[i][j] < INF) {
                if (mas[i][j] > minn.first) {
                    minn.first = mas[i][j];
                    minn.second = i + 1;
                }
            }
        }
        maxx.push_back(minn);
    }
    sort(maxx.begin(), maxx.end());
    cout << maxx[0].second << ' ' << maxx[0].first;
}
