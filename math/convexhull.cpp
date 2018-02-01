#include <bits/stdc++.h>
#define double long double
#define int long long
#define fi first
#define se second
#define endl '\n'

using namespace std;

typedef long long ll;

typedef pair<double, double> point;

const double EPS = 1e-6;

double operator ^ (const point &vc1, const point &vc2) {
    return vc1.fi * vc2.se - vc1.se * vc2.fi;
}

double area (vector<point> a) {
    double ans = 0;

    reverse(a.begin(), a.end());
    int n = a.size();
    for (int i = 1; i < n; i++) {
        ans += a[i - 1] ^ a[i];
    }
    ans += a[n - 1] ^ a[0];

    if (ans < 0)
        ans = ans * (-1);
    return ans * 0.5;
}


double cross(const point &a, const point &b, const point &c) {
	return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

struct Line {
    double a, b, c;
    void init (point A, point B) {
        a = (B.se - A.se);
        b = (A.fi - B.fi);
        c = -(a * A.fi + b * A.se);
    }
    bool left (point B) {
        if (a * B.fi + b * B.se + c < -EPS) {
            return true;
        } else return false;
    }
};
vector<point> convexHull(vector<point> points) {
	if (points.size() <= 3)
		return points;
	sort(points.begin(), points.end());
	vector<point> h;
	for (auto p: points) {
		while (h.size() >= 2 && cross(h.end()[-2], h.back(), p) >= 0)
			h.pop_back();
		h.push_back(p);
	}
	reverse(points.begin(), points.end());
	int upper = h.size();
	for (auto p: points) {
		while (h.size() > upper && cross(h.end()[-2], h.back(), p) >= 0)
			h.pop_back();
		h.push_back(p);
	}
	h.resize(h.size() - 1 - (h[0] == h[1]));
	return h;
}

main() {
    double minn = LLONG_MAX;
    cout.precision(22);
    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            vector<point> first, second;
            Line pr; pr.init(v[i], v[j]);
            for (int y = 0; y < n; y++) {
                if (y == i || y == j) continue;
                if (pr.left(v[y])) {
                    first.push_back(v[y]);
                } else second.push_back(v[y]);
            }
            vector<point> ff = first;
            vector<point> ss;
            //cout << first.size() << ' ' << second.size() << endl;

            for (int cnt = 1; cnt <= 2; cnt++) {
                double area1 = 0, area2 = 0;
                if (cnt == 1) {
                    ff = first;
                    if (ff.size() == 0) continue;
                    ff.push_back(v[i]); ff.push_back(v[j]);
                    ss = convexHull(ff);
                    if (ss.size() != ff.size()) continue;
                    else {
                        //if (ss.size() != 0)
                            area1 = area(ss);
                    }
                    ss = convexHull(second);
                    if (second.size() == 0) continue;
                    if (second.size() != ss.size()) continue;
                    else {
                        //if (ss.size() != 0)
                            area2 = area(ss);
                    }
                    //cout << area1 << ' ' << area2 << endl;
                    if (area1 > EPS && area2 > EPS) {
                        minn = min(minn, fabs(area1 - area2));
                    }
                } else {
                    ff = second;
                    if (ff.size() == 0) continue;
                    ff.push_back(v[i]); ff.push_back(v[j]);
                    ss = convexHull(ff);
                    if (ss.size() != ff.size()) continue;
                    else {
                        //if (ss.size() != 0)
                            area1 = area(ss);
                    }
                    ss = convexHull(first);
                    if (first.size() == 0) continue;
                    if (first.size() != ss.size()) continue;
                    else {
                        //if (ss.size() != 0)
                            area2 = area(ss);
                    }
                    //cout << area1 << ' ' << area2 << endl;
                    if (area1 > EPS && area2 > EPS) {
                        minn = min(minn, fabs(area1 - area2));
                    }
                }
            }
        }
    }
    if (minn == LLONG_MAX) {
        cout << -1;
        return 0;
    } else cout << minn;
}
