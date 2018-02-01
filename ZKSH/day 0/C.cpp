#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
    int start, finish, time;
};

bool cmp1(node a, node b) {
    if (a.finish - a.start == b.finish - b.start) {
        return a.start < b.start;
    }
    return a.finish - a.start < b.finish - b.start;
}

bool cmp2(node a, node b) {
    if (a.start + a.time + b.time <= b.finish && b.start + b.time + a.finish <= a.finish) {
        return a.start < b.start;
    }
    if (a.start + a.time + b.time <= b.finish) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
//    srand((unsigned ll)time(NULL));
//    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<node> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].start >> v[i].finish >> v[i].time;
        }
        sort(v.begin(), v.end(), cmp1);
        int tim = 0;
        bool bad = false;
        for (int i = 0; i < v.size(); i++) {
            tim = max(tim, v[i].start);
            tim += v[i].time;
            if (tim > v[i].finish) {
                bad = 1;
                break;
            }
        }

        if (bad) {
            tim = 0;
            bad = false;
            sort(v.begin(), v.end(), cmp2);
            for (int i = 0; i < v.size(); i++) {
                tim = max(tim, v[i].start);
                tim += v[i].time;
                if (tim > v[i].finish) {
                    bad = 1;
                    break;
                }
            }
            if (!bad) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << 1 << endl;
        }
    }
}