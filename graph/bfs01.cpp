#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1e3;
int n, m;
char mas[NMAX][NMAX];
int dist[3][NMAX][NMAX];

deque< pair<int, int> > q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mas[i][j];
		}
	}

	memset(dist, -1, sizeof dist);

	for (int c = '1'; c <= '3'; c++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mas[i][j] == c) {
					dist[c - '1'][i][j] = 0;
					q.push_back({i, j});
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().fi;
			int y = q.front().se;
			q.pop_front();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && mas[nx][ny] != '#') {
					int nd = dist[c - '1'][x][y] + (mas[nx][ny] == '.');
					if (dist[c - '1'][nx][ny] == -1 || dist[c - '1'][nx][ny] > nd) {
						dist[c - '1'][nx][ny] = nd;
						if (mas[nx][ny] == '.') {
							q.push_back({nx, ny});
						} else q.push_front({nx, ny});
					}
				}
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[1][i][j] != -1 && dist[2][i][j] != -1 && dist[0][i][j] != -1) {
				int nval = dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2 * (mas[i][j] == '.');
				if (ans == -1 || ans > nval) {
					ans = nval;
				}
			}
		}
	}
	cout << ans;
}