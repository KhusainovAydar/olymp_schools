#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;

const int NMAX = 1e5;

int n;
ll a[NMAX];

ll t[4 * NMAX];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    }
    if (l > r) return 0;
    int tm = (tl + tr) >> 1;
    return sum(2 * v + 1, tl, tm, l, min(tm, r)) +
            sum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

void upd(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = t[v] + 1;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            upd(2 * v + 1, tl, tm, pos);
        } else upd(2 * v + 2, tm + 1, tr, pos);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    build(0, 0, n - 1);
    int m;
    cin >> m;
    ll b;
    for (int i = 0; i < m; i++) {
        cin >> b;
        int l = -1, r = n - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            ll summ = sum(0, 0, n - 1, 0, mid);
            if (a[mid] - summ >= b) {
                r = mid;
            } else l = mid;
        }
        if (a[r] - sum(0, 0, n - 1, 0, r) >= b) {
            cout << n - r << endl;
            upd(0, 0, n - 1, r);
        }
        else
            cout << 0 << endl;
        /*for (int j = 0; j < n; j++) {
            cout << sum(0, 0, n - 1, 0, r) << ' ';
        }
        cout << endl;*/
    }
}
