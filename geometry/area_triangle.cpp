#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define pi 3.14159265359

using namespace std;

typedef long long ll;

struct Point {
	double x, y;
	void init () {
		cin >> x >> y;
	}
};

struct Vector {
	double x, y;
	void init (Point a, Point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};

double dot_product (Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

double cross_product (Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

double area_triangle (Point A, Point B, Point C) {
	Vector AB, AC;
	AB.init(A, B);
	AC.init(A, C);
	double ans = cross_product(AC, AB);
	return fabs(ans * 0.5);
}

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	Point A, B, C;
	A.init(); B.init(); C.init();
	cout.precision(20);
	cout << area_triangle(A, B, C);
}