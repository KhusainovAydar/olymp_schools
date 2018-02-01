#include <bits/stdc++.h>

using namespace std;

int const INF = 1 << 30;

struct SegmentTree {
    vector<int> mx;
    int n;

    void init(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        mx.assign(n * 2, 0);
    }

    void add(int x, int y) {
        x += n;
        mx[x] += y;
        while (x > 1) {
            x >>= 1;
            mx[x] = std::max(mx[x * 2], mx[x * 2 + 1]);
        }
    }

    int getmax(int left, int right) { // [, )
        --right;
        int ret = -INF;
        for (left += n, right += n; left <= right; left >>= 1, right >>= 1) {
            if (left & 1) ret = std::max(ret, mx[left++]);
            if ((right & 1) == 0) ret = std::max(ret, mx[right--]);
        }
        return ret;
    }
};

int const N = 123456;

int const K = 20;

vector<int> edges[N];
SegmentTree tree[N];
int father[N], depth[N], parent[N], size[N], heavy[N], en[N], ex[N], go[K][N];
int T;

int getMaxOnPath(int v, int u) {
    int ans = -INF;
    while (father[v] != father[u]) {
        ans = std::max(ans, tree[father[v]].getmax(0, depth[v] + 1));
        v = parent[father[v]];
    }
    return std::max(ans, tree[father[v]].getmax(depth[u], depth[v] + 1));
}


void buildPath(int u) {
    int d = 0;
    for (int z = u; z >= 0; z = heavy[z]) {
        depth[z] = d++;
        father[z] = u;
    }
    assert(u >= 0);
    tree[u].init(d);
}

void dfs(int v, int p) {
    size[v] = 1;
    heavy[v] = -1;
    en[v] = T++;
    parent[v] = p;
    for (int u : edges[v]) {
        if (u == p) continue;
            dfs(u, v);
        size[v] += size[u];
        if (heavy[v] < 0 || size[heavy[v]] < size[u]) heavy[v] = u;
    }
    for (int u : edges[v]) {
        if (u == heavy[v] || u == p) continue;
        buildPath(u);
    }
    ex[v] = T;
}

int anc(int v, int u) {
    return en[v] <= en[u] && ex[u] <= ex[v];
}

int lca(int v, int u) {
    if (anc(v, u)) return v;
    for (int i = K - 1; i >= 0; i--)
        if (!anc(go[i][v], u))
            v = go[i][v];
    return parent[v];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v;
        --u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    T = 0;
    dfs(0, -1);
    buildPath(0);
    for (int i = 0; i < n; i++) go[0][i] = parent[i] < 0 ? i : parent[i];
    for (int i = 1; i < K; i++) {
        for (int v = 0; v < n; v++) go[i][v] = go[i - 1][go[i - 1][v]];
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int c = getchar();
        while (c <= 32) c = getchar();
        int v, u;
        scanf("%d%d", &v, &u);
        if (c == 'I') {
            --v;
            tree[father[v]].add(depth[v], u);
        } else {
            --v;
            --u;
            int q = lca(v, u);
            printf("%d\n", std::max(getMaxOnPath(v, q), getMaxOnPath(u, q)));
        }
    }
}
