#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A {
	int u, v, w;
	bool operator<(const A& b) {
		return w < b.w;
	}
};

vector<A> graph;

vector<int> root;

int ans = 0;

int find(int a) {
	if (root[a] == a) return a;
	else return root[a] = find(root[a]);
}

int merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) {
		root[x] = y;
		return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int v, e; cin >> v >> e;

	for (int i = 0; i <= v; i++) root.push_back(i);

	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph.push_back(A{ a,b,c });
	}

	sort(graph.begin(), graph.end());

	for (A a : graph) {
		if (merge(a.u, a.v)) {
			ans += a.w;
		}
	}

	cout << ans;
}