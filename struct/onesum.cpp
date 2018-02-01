#include <bits/stdc++.h>

using namespace std;

vector<int> t;
int n;

void init (int nn)
{
	n = nn;
	t.assign (n, 0);
}

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}

int main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a);
    while (true) {
        string s;
        cin >> s;
        if (s[0] == 'a') {
            int pos, val;
            cin >> pos >> val;
            inc(pos - 1, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(l - 1, r - 1) << endl;
        }
    }
}
