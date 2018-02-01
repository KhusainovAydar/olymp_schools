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
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;

int n, x;

const int NMAX = 100000;

int isPrime[NMAX], last[NMAX];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("inverse2.in", "r", stdin);
//    freopen("inverse2.out", "w", stdout);
#endif
    cin >> n >> x;
    vector<int> p;
    int X = 1;
    isPrime[0] = isPrime[1] = x;
    int k = (int) sqrt(n);
    int ans = 0;
    for (int i = 2; i <= min(n, k); i++) {
        if (isPrime[i] == X) {
            continue;
        }
        isPrime[i] = X;
        p.pb(i);
        last[p.size() - 1] = i * i;
        //cout << i << ", ";
        ans = ans * x + i;
        for (int j = i * i; j <= k; j += i) {
            isPrime[j] = X;
            last[p.size() - 1] += i;
        }
    }
    for (int i = 1; i * k <= n; i++) {
        ++X;
        isPrime[0] = X;
        int ioi = min(n, (i + 1) * k) - i * k;
        for (int js = 0; js < p.size(); js++) {
            //int kek = t * (last[t] + 1);
            last[js] -= k;
            for (; last[js] <= ioi; last[js] += p[js]) {
                int id = last[js];
                isPrime[id] = X;
            }
        }
        for (int j = 1; j <= k; j++) {
            int pro = j + i * k;
            if (pro <= n && (isPrime[j] != X)) {
                //cout << pro << ", ";
                ans = ans * x + pro;
            }
            if (pro > n)
                break;
        }
    }
    cout << ans;
}