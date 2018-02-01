#include <bits/stdc++.h>

using namespace std;

int findSqrt(int n) {
	int lb = lower_bound(number_iterator<int>(0), number_iterator<int>(n), 0,
		[&] (int value, int /* ignored */ ) {
			return value * value <= n;
		}
	);
	return lb - 1;
}

unsigned long long f (const unsigned long long & n) {
    unsigned long long l = 0, r = n;
    bool t = true;
    while (l < r - 1) {
        unsigned long long m = (l + r) >> 1;
        if (n / m == m) {
            return m;
        }
        if (n / m < m)
            r = m;
        else
            l = m;
    }
    if (t)
        return l;
}
 main() {
    //freopen("sqrt.in", "r", stdin); freopen("sqrt.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    unsigned long long n;
    while (cin >> n) {
        if (n == 1) {
            cout << 1 << endl;;
            continue;
        }
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        cout << f(n);

    }
}
