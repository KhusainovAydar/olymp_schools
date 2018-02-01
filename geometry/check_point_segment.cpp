#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define double ll
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

bool check (double a, double b, double c) {
	if (a >= b && b >= c) return true;
	if (a <= b && b <= c) return true;
	return false;
}

bool check_point (Point A, Point B, Point P) {
	Vector AB, AP;
	AB.init(A, B); AP.init(A, P);
	if (cross_product(AB, AP) == 0) {
		if (check(A.x, P.x, B.x))
			if (check(A.y, P.y, B.y))
				return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	//#if __APPLE__ 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	//#endif
	Point A, B, P;
	P.init(); A.init(); B.init();
	if (check_point(A, B, P)) {
		cout << "YES";
	} else cout << "NO";
}