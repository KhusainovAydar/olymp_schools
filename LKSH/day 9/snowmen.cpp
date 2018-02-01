#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
using namespace std;

typedef long long ll;

struct Stack {
    int last;
    ll sum;
    Stack(int l, ll s) {
        sum = s;
        last = l;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("snowmen.in", "r", stdin);
    freopen("snowmen.out", "w", stdout);
#endif
    vector<Stack> kek;
    int n;
    cin >> n;
    kek.push_back(Stack(0, 0));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b != 0) {
            kek.push_back(Stack(a, kek[a].sum + b));
        } else {
            kek.push_back(kek[kek[a].last]);
        }
    }
    ll sum = 0;
    for (int i = 0; i < kek.size(); i++) {
        sum += kek[i].sum;
    }
    cout << sum;
}