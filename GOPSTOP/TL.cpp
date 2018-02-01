#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define Write(x) cout << #x << " = " << x << endl;
#include <ctime>

const double TL = 2; // seconds

inline bool isTimeLimit() {
    static int is = 0, cnt = 0;
    if (++cnt == 1000) { // каждый раз вызывать clock() - слишком долго
        cnt = 0;
        is |= clock() > (TL - 0.1) * CLOCKS_PER_SEC; // время работы с запуска программы
    }
}


using namespace std;
typedef long long ll;
typedef pair <int, int> pi;
const ll MOD = 1e9 + 7;
const int N = 26;
const int inf = 2e9;
const int MAX = 1e6 + 12;

int main() {

}
