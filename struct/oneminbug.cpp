#include <bits/stdc++.h>

using namespace std;

vector<int> t;
int n;

const int INF = 1000*1000*1000;

void init (int nn)
{
	n = nn;
	t.assign (n, INF);
}

int getmin (int r)
{
	int result = INF;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result = min (result, t[r]);
	return result;
}

void update (int i, int new_val)
{
	for (; i < n; i = (i | (i+1)))
		t[i] = min (t[i], new_val);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		update (i, a[i]);
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
            update(pos, val);
        } else {
            int l, r;
            cin >> r;
            cout << getmin(r - 1) << endl;
        }
    }
}
