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

vector<int> pref_fun(const string & s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
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

inline string getstr() {
    string ans = "";
    char c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) {
        ans += c;
        c = getchar();
    }
    return ans;
}


int main() {
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    /*#else
        freopen("cyclic-shift.in", "r", stdin); 
        freopen("cyclic-shift.out", "w", stdout);*/
    #endif
    string s = getstr();
    string a = s + s;
    string b = s + '#' + a;
    vector<int> pref = pref_fun(b);
    int cnt = 0;
    for (int i = (int)s.length() - 1; i < pref.size(); i++) {
        if (pref[i] == (int)s.length()) cnt++;
    }
    cout << cnt - 1;
}