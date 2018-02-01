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
	void init() {
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

double sqr (double a) {
	return a * a;
}

double dist (Point A, Point B) {
	return sqr(A.x - B.x) + sqr(A.y - B.y);
}

struct Line {
	double a, b, c;
	void init (Point A, Point B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = (A.y - B.y) * A.x + (B.x - A.x) * A.y;
	}
};

double Line_check (Line A, Point B) {
	return A.a * B.x + A.b * B.y + A.c;
}

bool check (Point A, Point B, Point P) {
	Vector AB;
	AB.init(A, B);
	Vector AP;
	AP.init(A, P);
	if (cross_product(AB, AP) == 0 && (((A.x <= P.x && P.x <= B.x) || (A.x >= P.x && P.x >= B.x)) && ((A.y <= P.y && P.y <= B.y) || (A.y >= P.y && P.y >= B.y)))) {
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
	Point A, B, C, D;
	A.init(); B.init(); C.init(), D.init();
	Line AB, CD;
	AB.init(A, B);
	CD.init(C, D);

	if (Line_check(AB, C) * Line_check(AB, D) > 0) {
		cout << "NO";
		return 0;
	}

	if (Line_check(CD, A) * Line_check(CD, B) > 0) {
		cout << "NO";
		return 0;
	}

	if (Line_check(AB, C) * Line_check(AB, D) < 0 && Line_check(CD, A) * Line_check(CD, B) < 0) {
		cout << "YES";
		return 0;
	}

	if (Line_check(AB, C) == 0) {
		if (check(A, B, C)) {
			cout << "YES";
			return 0;
		}
	}

	if (Line_check(AB, D) == 0) {
		if (check(A, B, D)) {
			cout << "YES";
			return 0;
		}
	}

	if (Line_check(CD, A) == 0) {
		if (check(C, D, A)) {
			cout << "YES";
			return 0;
		}
	}

	if (Line_check(CD, B) == 0) {
		if (check(C, D, B)) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

}