#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

int n;

const int NMAX = 1e5 + 5;
const int K = 20;

int go[K][NMAX];
int parent[NMAX];

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //        freopen("magic.in", "r", stdin);
    //        freopen("magic.out", "w", stdout);
#endif
    cin >> n;
    int cor = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (x == -1) {
            cor = i;
            parent[i] = -1;
            continue;
        }
        parent[i] = x;
    }
    for (int i = 0; i < n; i++) go[0][i] = parent[i];
    for (int i = 1; i < K; i++) {
        for (int v = 0; v < n; v++)
            if (go[i - 1][v] == -1) {
                go[i][v] = -1;
            } else {
                go[i][v] = go[i - 1][go[i - 1][v]];
            }
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < K; j++) {
            if (go[j][i] != -1)
                cout << go[j][i] + 1 << ' ';
        }
        cout << endl;
    }
}