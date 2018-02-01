#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct Point {
    double x, y;
};

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("anniversary.in", "r", stdin);
//    freopen("anniversary.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Point> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        double L = 0, R = pi;
        for (int it = 0; it < 100; it++) {
            double M = (L + R) * 0.5;
            vector< Point > b = a;
            double X[] = {-1000000, 1000000}, Y[] = {-1000000, 1000000};
            for (int i = 0; i < n; i++) {
                b[i].x = a[i].x * cos(M) - a[i].y * sin(M);
                b[i].y = a[i].x * sin(M) + a[i].y * cos(M);
                X[0] = max(X[0], b[i].x);
                X[1] = min(X[1], b[i].x);
                Y[0] = max(Y[0], b[i].y);
                Y[1] = min(Y[1], b[i].y);
            }
            if (X[0] - X[1] <= Y[0] - Y[1]) {
                L = M;
            } else {
                R = M;
            }
        }
        vector< Point > b = a;
        double X[] = {-1000000, 1000000}, Y[] = {-1000000, 1000000};
        for (int i = 0; i < n; i++) {
            b[i].x = a[i].x * cos(L) - a[i].y * sin(L);
            b[i].y = a[i].x * sin(L) + a[i].y * cos(L);
            X[0] = max(X[0], b[i].x);
            X[1] = min(X[1], b[i].x);
            Y[0] = max(Y[0], b[i].y);
            Y[1] = min(Y[1], b[i].y);
        }
        Point A[] = {{X[0], Y[0]}, {X[0], Y[1]}, {X[1], Y[0]}, {X[1], Y[1]}};
        cout.precision(20);
        for (int i = 0; i < 4; i++) {
            double x = A[i].x * cos(-L) - A[i].y * sin(-L);
            double y = A[i].x * sin(-L) + A[i].y * cos(-L);
            cout << x << ' ' << y << endl;
        }
    }
}