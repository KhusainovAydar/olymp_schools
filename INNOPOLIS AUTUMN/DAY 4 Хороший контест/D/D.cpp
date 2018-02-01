#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
//#define MOD 1000000007

using namespace std;

typedef long long ll;

vector<int> a;
int n;

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
#endif
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    ll minn = INT_MAX;
    n++;
    int kok = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            kok = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        vector<bool> used(n, 0);
        used[kok] = 1;
        int pos = a[kok];
        ll ans1 = 0, ans2 = 0;
        int x = n - 1;
        if (kok > i) {
            for (int j = kok; j >= i; j--) {
                ans1 += abs(a[j] - pos) * x;
                ans2 += abs(a[j] - pos) * x;
                if (!used[j]) {
                    used[j] = 1;
                    x--;
                }
                pos = a[j];
            }
        } else {
            for (int j = kok; j <= i; j++) {
                ans1 += abs(a[j] - pos) * x;
                ans2 += abs(a[j] - pos) * x;
                if (!used[j]) {
                    used[j] = 1;
                    x--;
                }
                pos = a[j];
            }
        }
        vector<bool> copy = used;
        int copyx = x;
        for (int j = i; j >= 0; j--) {
            ans1 += abs(a[j] - pos) * x;
            if (!used[j]) {
                used[j] = 1;
                x--;
            }
            pos = a[j];
        }
        for (int j = 0; j < n; j++) {
            ans1 += abs(a[j] - pos) * x;
            if (!used[j]) {
                used[j] = 1;
                x--;
            }
            pos = a[j];
        }
        x = copyx;
        used = copy;
        pos = a[i];
        for (int j = i; j < n; j++) {
            ans2 += abs(a[j] - pos) * x;
            if (!used[j]) {
                used[j] = 1;
                x--;
            }
            pos = a[j];
        }
        for (int j = n - 1; j >= 0; j--) {
            ans2 += abs(a[j] - pos) * x;
            if (!used[j]) {
                used[j] = 1;
                x--;
            }
            pos = a[j];
        }
        minn = min({minn, ans1, ans2});
    }
    cout << minn;
}