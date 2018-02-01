#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define rand() ((rand() << 16) + rand())
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//#define MIN -2147483648
//#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef long long ll;

double sqr(double x) {
    return x * x;
}

struct Point {
    double x, y;
    
    void init() {
        cin >> x >> y;
    }
    
    bool operator==(const Point & a) const {
        return a.x == x && a.y == y;
    }
};

double dist(Point a, Point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

struct Vector {
    double x, y;
    
    void init(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    
    double len() {
        return sqrt(sqr(x) + sqr(y));
    }
    
};

double scalmul(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double vectmul(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    double a, b, c;
    Vector n;
    
    void init(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(a * p1.x + b * p1.y);
        n = {a, b};
    }
    
    void init(double A, double B, double C) {
        a = A;
        b = B;
        c = C;
        n = {a, b};
    }
    
    double val(Point p) {
        return a * p.x + b * p.y + c;
    }
    
    double dist(Point p) {
        double kek = sqrt(sqr(a) + sqr(b));
        double d = fabs(val(p));
        return d / kek;
    }
    
    bool one_side(Point p1, Point p2) {
        return ((val(p1) * val(p2)) > 0);
    }
    
    bool match(Line L) {
        return (a * L.b == b * L.a) && (b * L.c == c * L.b) && (a * L.c == L.a * c);
    }
    
    bool parallel(Line L) {
        return (a * L.b == b * L.a) && (b * L.c != c * L.b) && (a * L.c != L.a * c);
    }
    
    pair< Line, Line > parallel_line(double R) {
        Line ret, ret2;
        ret.a = a, ret.b = b;
        double e = n.len();
        e *= R;
        ret.c = c + e;
        ret2 = {a, b, c - e};
        return {ret, ret2};
    }

    Point intersec(Line A) {
        Point ans;
        double aa[2] = {a, A.a}, bb[2] = {b, A.b}, cc[2] = {c, A.c};
        ans.y = (aa[1] * cc[0] - cc[1] * aa[0]) / (aa[0] * bb[1] - bb[0] * aa[1]);
        ans.x = (cc[0] * bb[1] - bb[0] * cc[1]) / (aa[1] * bb[0] - bb[1] * aa[0]);
        return ans;
    }
    
    bool intersec(Point A) {
        return (val(A) == 0);
    }
};

struct Segment {
    Point A, B;
    Line L_AB;
    Vector V_AB, V_BA;
    
    void init(Point a, Point b) {
        A = a;
        B = b;
        V_AB.init(a, b);
        V_BA.init(b, a);
        L_AB.init(a, b);
    }
    
    bool check_on_segment(Point P) {
        Vector V_AP, V_BP; V_AP.init(A, P), V_BP.init(B, P);
        return scalmul(V_AB, V_AP) >= 0 && scalmul(V_BA, V_BP) >= 0;
    }
    
    double dist(Point p) {
        if (check_on_segment(p)) {
            return L_AB.dist(p);
        }
        return min(::dist(p, B), ::dist(p, A));
    }
    
    bool intersec(Point p) {
        return check_on_segment(p) && L_AB.intersec(p);
    }
};

struct Ray {
    Point st;
    Vector n;
    Line pr;
    
    void init(Point a, Point b) {
        pr.init(a, b);
        st = a;
        n.init(a, b);
    }
    
    bool check_on_Ray(Point p) {
        Vector S;
        S.init(st, p);
        return scalmul(S, n) >= 0;
    }
    
    bool intersec(Point a) {
        Vector S;
        S.init(st, a);
        return check_on_Ray(a) && vectmul(S, n) == 0 && pr.intersec(a);
    }
};

bool ch(Segment a, Segment b) {
    bool val = a.L_AB.one_side(b.A, b.B);
    return (!val && !b.L_AB.one_side(a.A, a.B));
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cout.precision(20);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("basicvector.in", "r", stdin);
    freopen("basicvector.out", "w", stdout);
#endif
    
    return 0;
}



