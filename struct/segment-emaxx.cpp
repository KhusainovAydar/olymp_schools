#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5;

int a[NMAX], tsum[4 * NMAX];

void buildsum(int v, int tl, int tr) {
    if (tl == tr)
        tsum[v] = a[tl];
    else {
        int tm = (tl + tr) >> 1;
        buildsum(2 * v + 1, tl, tm);
        buildsum(2 * v + 2, tm + 1, tr);
        tsum[v] = tsum[2 * v + 1] + tsum[2 * v + 2];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l == tl && tr == r)
        return tsum[v];
    if (l > r)
        return 0;
    int tm = (tl + tr) >> 1;
    return sum(2 * v + 1, tl, tm, l, min(r, tm)) +
            sum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

void updsum(int v, int tl, int tr, int pos, int val) {
    if (tl == tr)
        tsum[v] = val;
    else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) updsum(2 * v + 1, tl, tm, pos, val);
        else updsum(2 * v + 2, tm + 1, tr, pos, val);
        tsum[v] = tsum[2 * v + 1] + tsum[2 * v + 2];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    buildsum(0, 0, n - 1);
    while (true) {
        string s;
        cin >> s;
         if (s[0] == 'a') {
            int l, r;
            cin >> l >> r;
            updsum(0, 0, n - 1, l - 1, r);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(0, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
}
