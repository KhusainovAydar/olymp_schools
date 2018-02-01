#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000500;

int n;
string s;
int sa[maxn], nsa[maxn], bl[maxn], pbl[maxn], cnt[maxn], nbl;

int good(int x) {return x >= n ? x-n : x;} // just x%n

void buildSA()
{
    n = s.length();

    for (int i = 0; i < n; i++)
        bl[i] = s[i];
    nbl = 256;
    for (int i = 0; i < n; i++)
        sa[i] = i;

    for (int d = 0; d < n; d = d ? d*2 : 1)
    {
        for (int i = 0; i < n; i++)
            nsa[i] = good(sa[i] - d + n); // sort by second block

        for (int i = 0; i < nbl; i++) // sort by first block
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
            cnt[bl[i]]++;
        for (int i = 1; i < nbl; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            sa[--cnt[bl[nsa[i]]]] = nsa[i];

        nbl = 0;
        for (int i = 0; i < n; i++) // relabel
        {
            if (i != 0 && (bl[sa[i]] != bl[sa[i-1]] || bl[good(sa[i]+d)] != bl[good(sa[i-1]+d)]))
                ++nbl;
            pbl[sa[i]] = nbl;
        }
        ++nbl;
        for (int i = 0; i < n; i++)
            bl[i] = pbl[i];
    }
}

int main()
{
    cin >> s;
    s += '$';
    buildSA();
    for (int i = 0; i < (int)s.length(); i++) if (sa[i] != (int)s.length() - 1)
        printf("%d ", sa[i]);
    printf("\n");
    for (int i = 0; i <(int)s.length(); i++)
        cout << s.substr(sa[i]) << endl;

    return 0;
}
