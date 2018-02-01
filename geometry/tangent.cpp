#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
    void write (){
        cout << x << ' ' << y << endl;
    }
};

struct Vector {
    double x, y;
    void init(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

};

double sqr (double n) {
    return sqrt(n);
}

double dist (Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct Circle {
    Point O;
    double R;

    void init () {
        cin >> O.x >> O.y >> R;
    }

    void kas (Point P) {
        if (dist(O, P) == R * R) {
            cout << 1 << endl << P.x << ' ' << P.y;
            exit(0);
        }

        if (dist(O, P) < R * R) {
            cout << 0;
            exit(0);
        }

        cout << 2 << endl;

        double OP = sqr(dist(O, P));

        double XP = OP * OP - R * R;

        double HP = XP / OP;

        double XH = sqr(XP - HP * HP);

        Vector V;
        V.init(O, P);

        Vector e;
        e.x = V.x / OP;
        e.y = V.y / OP;

        Vector OH;
        OH.x = e.x * (OP - HP);
        OH.y = e.y * (OP - HP);

        Point H;
        H.x = O.x + OH.x;
        H.y = O.y + OH.y;

        H.write();

        double k = e.x;
        e.x = -e.y;
        e.y = k;

        cout << HP << ' ' << XH << endl;

        Point ans;
        ans.x = H.x + e.x * XH;
        ans.y = H.y + e.y * XH;

        ans.write();

        ans.x = H.x - e.x * XH;
        ans.y = H.y - e.y * XH;

        ans.write();

    }
};
 main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    freopen("tangent.in", "r", stdin);freopen("tangent.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    cout.precision(20);
    Circle O;
    O.init();

    Point P;
    cin >> P.x >> P.y;

    O.kas(P);

}
