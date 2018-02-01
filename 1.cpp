#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31); // 2147483647

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) { return (a % b + b) % b; }

using namespace std;

struct segment {
    vi arr;
    segment(vi _arr) : arr(_arr) { }
};

vector<segment> T;
int K;

void rebuild() {
    int cnt = 0;
    rep(i,0,size(T))
        cnt += size(T[i].arr);
    K = static_cast<int>(ceil(sqrt(cnt)) + 1e-9);
    vi arr(cnt);
    for (int i = 0, at = 0; i < size(T); i++)
        rep(j,0,size(T[i].arr))
            arr[at++] = T[i].arr[j];
    T.clear();
    for (int i = 0; i < cnt; i += K)
        T.push_back(segment(vi(arr.begin()+i, arr.begin()+min(i+K, cnt))));
}

int split(int at) {
    int i = 0;
    while (i < size(T) && at >= size(T[i].arr))
        at -= size(T[i].arr), i++;
    if (i >= size(T)) return size(T);
    if (at == 0) return i;
    T.insert(T.begin() + i + 1, segment(vi(T[i].arr.begin() + at, T[i].arr.end())));
    T[i] = segment(vi(T[i].arr.begin(), T[i].arr.begin() + at));
    return i + 1;
}

void insert(int at, int v) {
    vi arr; arr.push_back(v);
    T.insert(T.begin() + split(at), segment(arr));
}

void erase(int at) {
    int i = split(at); split(at + 1);
    T.erase(T.begin() + i);
}

int main() {

}
