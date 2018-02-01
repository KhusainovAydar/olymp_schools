#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;
int n;
double r, ans;
const double pi = 3.14159265359;

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> r;
    pair<double, double> pt, pp;
    cin >> pt.first >> pt.second;
    pp = pt;
    for (int i = 1; i < n; i++) {
        pair<double, double> pr;
        cin >> pr.first >> pr.second;
        ans += dist(pr, pp);
        pp = pr;
    }

    ans += dist(pp, pt) + 2 * pi * r;

    cout << fixed << setprecision(2) << ans;
}
