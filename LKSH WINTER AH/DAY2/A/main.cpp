#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

enum GAME {
    WIN, LOSE, DRAW, NOT_USED, USED
};

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("retro.in", "r", stdin);
    freopen("retro.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m) {
        vector< vector<int> > gr;
        gr.resize((unsigned long) n);
        vector<int> cur((unsigned long) n, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            gr[b].pb(a);
            cur[a]++;
        }

        vector<GAME> d((unsigned long) n, NOT_USED), used((unsigned long) n, NOT_USED);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (cur[i] == 0) {
                d[i] = LOSE;
                st.push(i);
            }
        }

        while (st.size()) {
            int v = st.top();
            used[v] = USED;
            st.pop();
            for (auto to : gr[v]) {
                cur[to]--;
                if (used[to] == USED) continue;
                if (d[v] == LOSE) {
                    d[to] = WIN;
                    used[to] = USED;
                    st.push(to);
                }
                if (cur[to] == 0 && d[to] == NOT_USED) {
                    d[to] = LOSE;
                    st.push(to);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (d[i] == NOT_USED) {
                cout << "DRAW" << endl;
            } else if (d[i] == WIN) {
                cout << "FIRST" << endl;
            } else if (d[i] == LOSE) {
                cout << "SECOND" << endl;
            }
        }
    }
}