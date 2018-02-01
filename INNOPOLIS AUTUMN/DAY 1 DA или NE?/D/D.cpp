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
#define MOD 1000000007

using namespace std;

typedef long long ll;


const int NMAX = 150;
int a[NMAX][NMAX];


int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
    //#else
    //        freopen("magic.in", "r", stdin);
    //        freopen("magic.out", "w", stdout);
#endif
    int cnt = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll sum = 0;
        for (int j = 0; j < n - 1; j++) {
            a[i][j] = cnt++;
            sum += a[i][j];
        }
        a[i][n - 1] = a[i][n - 2] * n - sum;
        cnt = a[i][n - 1] + 1;
    }
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = 0; j < n - 1; j++) {
            //a[j][i] = cnt++;
            sum += a[j][i];
        }
        a[n - 1][i] = a[n - 2][i] * n - sum;
        cnt = a[n - 1][i] + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}