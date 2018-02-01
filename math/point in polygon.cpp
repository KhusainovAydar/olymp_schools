#include <bits/stdc++.h>
#define Point Vector
#define fi first
#define se second
using namespace std;

typedef long long ll;

const double pi = 3.14159265358979323;
const double eps = 1e-6;

double sqr(double x) {
    return x * x;
}

double Equal(double a, double b) {
    return fabs(a - b) < eps;
}

double Less(double a, double b) {
    return a + eps < b;
}

double toRad(double ang) {
    return ang / 180 * pi;
}

double toDeg(double ang) {
    return ang / pi * 180;
}

struct Vector {
    double a, b;
    Vector() {}
    Vector(double a, double b) : a(a), b(b) {}
    Vector perpendicular() {
        return Vector(-b, a);
    }
    double len() {
        return sqrt(sqr(a) + sqr(b));
    }
    void norm() {
        double d = len();
        a /= d;
        b /= d;
    }
    void in() {
        cin >> a >> b;
    }
    double dist(Vector pt) {
        return sqrt(sqr(a - pt.a) + sqr(b - pt.b));
    }
};

Vector norm(Vector vc) {
    vc.norm();
    return vc;
}

Vector operator + (const Vector &vc1, const Vector &vc2) {
    return Vector(vc1.a + vc2.a, vc1.b + vc2.b);
}

Vector operator - (const Vector &vc1, const Vector &vc2) {
    return Vector(vc1.a - vc2.a, vc1.b - vc2.b);
}

Vector operator * (const Vector &vc1, const double &x) {
    return Vector(vc1.a * x, vc1.b * x);
}

double operator ^ (const Vector &vc1, const Vector &vc2) {
    return vc1.a * vc2.b - vc1.b * vc2.a;
}

double operator * (const Vector &vc1, const Vector &vc2) {
    return vc1.a * vc2.a + vc1.b * vc2.b;
}


double getAngle(const Vector &vc1, const Vector &vc2) {
    return atan2(vc1 ^ vc2, vc1 * vc2);
}

struct Segment {
    Vector pt1, pt2;
    Segment() {}
    Segment(Vector pt1, Vector pt2) : pt1(pt1), pt2(pt2) {}
    bool in(Vector pt) {
        Vector AB = pt2 - pt1;
        Vector BA = pt1 - pt2;
        Vector AP = pt - pt1;
        Vector BP = pt - pt2;
        return (AB ^ AP) == 0 && (AB * AP) >= 0 && (BA * BP) >= 0;
    }
    double dist(Vector pt) {
        if ((pt - pt1) * (pt2 - pt1) >= 0 && (pt - pt2) * (pt1 - pt2) >= 0) {
            return fabs((pt - pt1) ^ (pt2 - pt1)) / (pt2 - pt1).len();
        } else {
            return min(pt.dist(pt1), pt.dist(pt2));
        }
    }
    bool intersect(Segment CD) {
        Vector A = pt1, B = pt2;
        Vector C = CD.pt1, D = CD.pt2;
        double sgn1 = (C - A) ^ (B - A);
        double sgn2 = (D - A) ^ (B - A);
        double sgn3 = (A - C) ^ (D - C);
        double sgn4 = (B - C) ^ (D - C);
        if (sgn1 == 0 && sgn2 == 0 && sgn3 == 0 && sgn4 == 0) {
            return in(C) || in(D) || CD.in(A) || CD.in(B);
        } else if (sgn1 * sgn2 <= 0 && sgn3 * sgn4 <= 0) {
            return true;
        }
        return false;
    }
};

struct Line {
    double a, b, c;
    Line() {}
    Line(Vector pt1, Vector pt2) {
        a = pt2.b - pt1.b;
        b = pt1.a - pt2.a;
        c = -a * pt1.a - b * pt1.b;
        double z = sqrt(sqr(a) + sqr(b));
        a /= z;
        b /= z;
        c /= z;
    }
    void in() {
        cin >> a >> b >> c;
        double z = sqrt(sqr(a) + sqr(b));
        a /= z;
        b /= z;
        c /= z;
    }
    bool parallel(Line ln) {
        return Equal(Vector(a, b) ^ Vector(ln.a, ln.b), 0);
    }
    Vector intersect(Line ln) {
        double z = b * ln.a - a * ln.b;
        return Vector((c * ln.b - b * ln.c) / z, (ln.c * a - c * ln.a) / z);
    }
    double get(Vector pt) {
        return a * pt.a + b * pt.b + c;
    }
    double dist(Vector pt) {
        return fabs(get(pt));
    }
    bool in(Vector &pt) {
        return Equal(get(pt), 0);
    }
};

struct Circle {
    Vector O;
    double R;
    Circle() {}
    Circle(Vector O, double R) : O(O), R(R) {}
};

Circle getIncircle(const Vector &A, const Vector &B, const Vector &C) {
    Line bis1(A, A + norm(B - A) + norm(C - A));
    Line bis2(B, B + norm(A - B) + norm(C - B));
    Vector O = bis1.intersect(bis2);
    double R = Line(A, B).dist(O);
    return Circle(O, R);
}

Circle getCircircle(const Vector &A, const Vector &B, const Vector &C) {
    Line perp1((A + B) * 0.5, (A + B) * 0.5 + (B - A).perpendicular());
    Line perp2((A + C) * 0.5, (A + C) * 0.5 + (C - A).perpendicular());
    Vector O = perp1.intersect(perp2);
    double R = O.dist(A);
    return Circle(O, R);
}

struct Poly {
    int n;
    vector<Point> pts;
    void in(int n) {
        this->n = n;
        pts.resize(n);
        for (int i = 0; i < n; i++) {
            pts[i].in();
        }
    }
    bool in(Point pt) {
        double ang = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            ang += getAngle(pts[i] - pt, pts[j] - pt);
            if (Segment(pts[i], pts[j]).in(pt)) return true;
        }
        ang = fabs(ang);
        return Equal(ang, 2 * pi);
    }
};

bool inAngle(const Vector &A, const Vector &O, const Vector &B, const Vector &P) {
    Vector OA = A - O;
    Vector OB = B - O;
    Vector OP = P - O;

    if ((OP ^ OA) * (OP ^ OB) <= 0) {
        if (Less(fabs(getAngle(OA, OP)) + fabs(getAngle(OB, OP)), pi)) {
            return true;
        }
    }
    return false;
}

double TriangleArea(const Vector &A, const Vector &B, const Vector &C) {
    Vector AC = A - C;
    Vector BC = B - C;
    return fabs(AC ^ BC) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //freopen("point.in", "r", stdin); freopen("point.out", "w", stdout);
    int n;
    cin >> n;

    Point P;
    P.in();

    Poly poly;
    poly.in(n);

    if (poly.in(P)) {
        puts("YES");
    } else {
        puts("NO");
    }
}
