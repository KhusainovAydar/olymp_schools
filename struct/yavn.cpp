#include <bits/stdc++.h>

using namespace std;

struct tree {
    int key, prior;
    tree * l, * r;
    tree (int x) {
        key = x;
        l = r = 0;
        prior = rand();
    }
};

void split(tree * t, tree * &l, tree * &r, int sk) {
    if (!t) return void(l = r = 0);
    if (t->key <= sk) split(t->r, t->r, r, sk), l = t;
    else split(t->l, l, t->l, sk), r = t;
}

void merge(tree * & t, tree * l, tree * r) {
    if (!l || !r) t = l ? l : r;
    else if (l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
}

void insert(tree * & t, int x) {
    tree * tl, * tr;
    split(t, tl, tr, x);
    merge(tl, tl, new tree(x));
    merge(t, tl, tr);
}

void erase(tree * & t, int x) {
    tree * tl, * tm, * tr;
    split(t, tl, tr, x);
    split(tl, tl, tm, x - 1);
    merge(t, tl, tr);
}

bool exist(tree * & t, int x) {
    if (!t) return false;
    if (t->key == x) return true;
    if (t->key < x) return exist(t->r, x);
    else return exist(t->l, x);
}

tree * t = NULL;

int main() {
    string s;
    int x;
    while (cin >> s) {
        cin >> x;
        if (s[0] == 'i') insert(t, x);
        if (s[0] == 'd') erase(t, x);
        if (s[0] == 'e') cout << boolalpha << exist(t, x) << endl;
    }
    return 0;
}
