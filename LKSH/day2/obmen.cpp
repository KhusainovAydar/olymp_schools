#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

unordered_map<int, int> mp;

inline int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}

int main() {
    //ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("swap.in", "r", stdin); 
        freopen("swap.out", "w", stdout);
    #endif
    int n;
    n = getint();
    for (int i = 0; i < n; i++) {
        int a = getint(), b = getint();
        int x, y;
        if (mp[a] == 0) {
            x = a;
        } else x = mp[a];
        if (mp[b] == 0) {
            y = b;
        } else y = mp[b];
        printf("%d\n", abs(x - y));
        mp[a] = x;
        mp[b] = y;
        swap(mp[a], mp[b]);
    }
}       