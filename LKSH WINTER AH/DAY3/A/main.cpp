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

const int NMAX = 100005;

bool isPrime[NMAX];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("sieve.in", "r", stdin);
    freopen("sieve.out", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i * i < NMAX; i++) {
        if (isPrime[i]) {
            continue;
        }
        for (int j = i * i; j < NMAX; j += i) {
            isPrime[j] = 1;
        }
    }
    for (int i = a; i <= b; i++) {
        if (!isPrime[i]) {
            cout << i << ' ';
        }
    }
}