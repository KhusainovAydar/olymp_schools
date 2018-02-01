#include <bits/stdc++.h>
#define int long long
using namespace std;


const int INF = 1000000000000000000;

const int NMAX = 5005;

vector<vector<pair<int, int>>> g(NMAX);

int n, m;
int v1, v2, v3, v4;

int Dijkstra(int s, int fi) {
    int v, vv;
    if (s == v1) {
        v = v3;
        vv = v4;
    }
    if (s == v2) {
        v = v1;
        vv = v4;
    }
    if (s == v3) {
        v = v1;
        vv = v2;
    }
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
            //if (to == v || to == vv)
            //    continue;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}
		}
	}
	return d[fi];
}

 main() {
    cin >> n >> m;
    cin >> v1 >> v2 >> v3 >> v4;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    v1--, v2--, v3--, v4--;
    int ans1 = Dijkstra(v1, v2);
    int ans2 = Dijkstra(v2, v3);
    int ans3 = Dijkstra(v3, v4);
    if (ans1 >= INF || ans2 >= INF || ans3 >= INF) {
        cout << -1;
        return 0;
    }
    cout << ans1 + ans2 + ans3;
}
