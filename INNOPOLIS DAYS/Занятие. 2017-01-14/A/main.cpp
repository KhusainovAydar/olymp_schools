#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define rand() ((rand() << 16) + rand())
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
//#define MIN -2147483648
//#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef long long ll;

bool ans[266];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    
#endif
    int n;
    cin >> n;
    vector< string > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int y = 0;
        bool ch = 1;
        for (y = 0; y < min(a[i].size(), s.size()); y++) {
            if (a[i][y] != s[y]) {
                ch = 0;
                break;
            }
        }
        if (!ch || (a[i].size() == s.size())) continue;
        if (y == s.size()) {
            ans[a[i][y] - 'A'] = 1;
            cerr << a[i][y] << endl;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << '*';
    }
    for (int i = 0; i < 5; i++) {
        if (ans[i]) {
            cout << char(i + 'A');
        } else {
            cout << '*';
        }
    }
    cout << endl;
    for (int i = 5; i < 5 + 8; i++) {
        if (ans[i]) {
            cout << char(i + 'A');
        } else {
            cout << '*';
        }
    }
    cout << endl;
    for (int i = 5 + 8; i < 5 + 8 + 8; i++) {
        if (ans[i]) {
            cout << char(i + 'A');
        } else {
            cout << '*';
        }
    }
    cout << endl;
    for (int i = 5 + 8 + 8; i < 26; i++) {
        if (ans[i]) {
            cout << char(i + 'A');
        } else {
            cout << '*';
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << '*';
    }
}