#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;

const double pi = 3.14159265358979323;
const double eps = 1e-9;

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

struct PolarPoint {
    double r, phi;
    PolarPoint() {}
    PolarPoint(double r, double phi) : r(r), phi(phi) {}
    void in() {
        cin >> r >> phi;
        phi = toRad(phi);
    }
};

struct Point {
    double x, y;
};

struct Vector {
    double a, b;
    Vector() {}
    Vector(double a, double b) : a(a), b(b) {}
    Vector(PolarPoint pt) {
        a = pt.r * cos(pt.phi);
        b = pt.r * sin(pt.phi);
    }
    double len() {
        return sqrt(sqr(a) + sqr(b));
    }
    void in() {
        cin >> a >> b;
    }
    double dist(Vector pt) {
        return sqrt(sqr(a - pt.a) + sqr(b - pt.b));
    }
};

Vector operator - (const Vector &vc1, const Vector &vc2) {
    return Vector(vc1.a - vc2.a, vc1.b - vc2.b);
}

int operator ^ (const Vector &vc1, const Vector &vc2) {
    return vc1.a * vc2.b - vc1.b * vc2.a;
}

int operator * (const Vector &vc1, const Vector &vc2) {
    return vc1.a * vc2.a + vc1.b * vc2.b;
}

double getAngle(const Vector &vc1, const Vector &vc2) {
    return fabs(atan2(vc1 ^ vc2, vc1 * vc2));
}

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
    double get(Vector pt) {
        return a * pt.a + b * pt.b + c;
    }
    double dist(Vector pt) {
        return fabs(get(pt));
    }
};

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


PolarPoint toPolar(Vector &pt) {
    return PolarPoint(pt.len(), atan2(pt.b, pt.a));
}

Vector toPoint(const PolarPoint &pt) {
    return Vector(pt.r * cos(pt.phi), pt.r * sin(pt.phi));
}

bool inAngle(const Vector &A, const Vector &O, const Vector &B, const Vector &P) {
    Vector OA = A - O;
    Vector OB = B - O;
    Vector OP = P - O;

    if ((OP ^ OA) * (OP ^ OB) <= 0) {
        if (Less(getAngle(OA, OP) + getAngle(OB, OP), pi)) {
            return true;
        }
    }
    return false;
}

double dist(Vector a, Vector b){
    return sqrt((a.a - b.a) * (a.a - b.a) + (a.b - b.b) * (a.b - b.b));
}

int main() {
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //freopen("distance.in", "r", stdin);freopen("distance.out", "w", stdout);

    Vector P1, P2, A, B;
    A.in();
    B.in();
    P1.in();
    P2.in();
    Segment AB(A, B);
    Segment PP(P1, P2);
    if(A.a == B.a && A.b == B.b && P1.a == P2.a && P1.b == P2.b){
        cout.precision(20);
        cout << (double)dist(A, P1);
        return 0;
    }
    if(A.a == B.a && A.b == B.b){
        cout.precision(20);
        cout << PP.dist(A);
        return 0;
    }
    if(P1.a == P2.a && P1.b == P2.b){
        cout.precision(20);
        cout << AB.dist(P1);
        return 0;
    }
    if(AB.intersect(PP)||PP.intersect(AB)){
        cout << 0;
        return 0;
    }
    cout.precision(20);
    cout << min(min(AB.dist(P1), AB.dist(P2)),min(PP.dist(A), PP.dist(B))) ;
}
