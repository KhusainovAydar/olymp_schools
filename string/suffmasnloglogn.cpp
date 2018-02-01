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

int n;

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

const int MAXN = 1 << 21;
int N, k;
int sa[MAXN], pos[MAXN], tmp[MAXN];

bool sufCmp(int i, int j) {
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += k;
    j += k;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(string S) {
    N = S.size();
    for (int i = 0; i < N; i++) sa[i] = i, pos[i] = S[i];
    for (k = 1; ; k *= 2) {
        sort(sa, sa + N, sufCmp);
        for (int i = 0; i < N - 1; i++) {
            tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        }
        for (int i = 0; i < N; i++) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}

int main() {
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("suffarray.in", "r", stdin); 
        freopen("suffarray.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    buildSA(s);
    for (int i = 0; i < (int)s.length(); i++) {
        cout << sa[i] << ' ';
    }
}