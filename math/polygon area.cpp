#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
    void read() {
        cin >> x >> y;
    }
};

struct Vector {
    double a, b;
    Vector() {}
    Vector(double a, double b) : a(a), b(b) {}
    Vector perpendicular() {
        return Vector(-b, a);
    }
    void in() {
        cin >> a >> b;
    }
};

double operator ^ (const Vector &vc1, const Vector &vc2) {
    return vc1.a * vc2.b - vc1.b * vc2.a;
}

double operator * (const Vector &vc1, const Vector &vc2) {
    return vc1.a * vc2.a + vc1.b * vc2.b;
}

 main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //freopen("area.in", "r", stdin);freopen("area.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Vector> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b;
    }

    double ans = 0;

    cout.precision(20);

    reverse(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        ans += a[i - 1] ^ a[i];
    }
    ans += a[n - 1] ^ a[0];

    if (ans < 0)
        ans = ans * (-1);
    cout << ans * 0.5;
}
