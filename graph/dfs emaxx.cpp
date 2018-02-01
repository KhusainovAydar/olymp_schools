#include <bits/stdc++.h>

using namespace std;

vector < vector<int> > g; // ����
int n; // ����� ������

vector<int> color; // ���� ������� (0, 1, ��� 2)

vector<int> time_in, time_out; // "�������" ������ � ������ �� �������
int dfs_timer = 0; // "������" ��� ����������� �����

void dfs (int v) {
	time_in[v] = dfs_timer++;
	color[v] = 1;
	for (auto i=g[v].begin(); i!=g[v].end(); ++i)
		if (color[*i] == 0)
			dfs (*i);
	color[v] = 2;
	time_out[v] = dfs_timer++;
}

vector<char> used;

void dfs2 (int v) {
	used[v] = true;
	for (auto i=g[v].begin(); i!=g[v].end(); ++i)
		if (!used[*i])
			dfs (*i);
}

int main() {

}
