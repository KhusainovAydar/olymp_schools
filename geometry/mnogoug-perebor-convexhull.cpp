#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

inline string get_str() {
    char c = getchar();
    while (c < 31) c = getchar();
    string s = "";
    while (c >= 32) {
        s += c;
        c = getchar();
    }
    return s;
}

inline int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}

int n, l;

struct Point {
    int x, y;
    void init() {
        cin >> x >> y;
    }
};


bool cmp(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool cww(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}


void convex_hull(vector<Point> &a) {
    if (a.size() <= 1) return;
    sort(a.begin(), a.end(), cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.pb(p1);
    down.pb(p1);
    for (int i = 1; i < a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[(int)up.size() - 2], up[(int)up.size() - 1], a[i])) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || cww(p1, a[i], p2)) {
            while (down.size() >= 2 && !cww(down[(int)down.size() - 2], down[(int)down.size() - 1], a[i])) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < up.size(); i++) {
        a.push_back(up[i]);
    }
    for (int i = (int)down.size() - 2; i > 0; i--) {
        a.push_back(down[i]);
    }
}

vector<Point> b;

int stress_perebor(int k) {
    int kek = 0;
    vector<Point> ans;
    for (unsigned int i = 1; i < (1 << n); i++) {
        ans.clear();
        int cur = 0;
        for (unsigned int j = 0; j < n; j++) {
            if ((i >> j)&1)
                ans.pb(b[j]), cur++;
        }
        if (cur == k) {
            convex_hull(ans);
            if (ans.size() == k) {
                kek++;
            }
            //cout << "LOL";
        }
    }
    return kek;
}

void gentest() {
    n = rand() % 5 + 4;
    l = rand() % (n - 2) + 1;
    b.clear();
    b.resize(n);
    for (int i = 0; i < n; i++) {
        b[i].x = rand() % 20 - 10;
        b[i].y = rand() % 20 - 10;
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
    #if __APPLE__
        freopen("/Users/macbook/Documents/joj/input.txt", "r", stdin);
        freopen("/Users/macbook/Documents/joj/output.txt", "w", stdout);
    #else
        freopen("karelia-light.in", "r", stdin);
        freopen("karelia-light.out", "w", stdout);
    #endif
    cin >> n >> l;
    b.resize(n);
    for (int i = 0; i < n; i++) {
        b[i].init();
    }
    for (int i = 0; i < l; i++) {
        int k;
        cin >> k;
        cout << stress_perebor(k) << ' ';
    }
    /*
    int test = 8000;
    while (test--) {
        gentest();
        for (int i = 0; i < l; i++) {
            int k = rand() % (n - 3) + 3;
            cnt = 0;
            vector<Point> pust;
            perebor(0, k, pust);
            if (cnt != stress_perebor(k)) {
                cout << "WRONG ";
                cout << n << ' ' << k << endl;
                for (int i = 0; i < n; i++) {
                    cout << b[i].x << ' ' << b[i].y << endl;
                }
                cout << endl;
                cout << cnt << ' ' << stress_perebor(k) << ' ' <<  k << endl;
                return 0;
            } else cout << "OK" << endl;
        }
    }
    cout << "OK";*/
}

/*
 6 1
 6 9
 8 5
 7 5
 6 2
 5 4
 8 -10
 4
*/