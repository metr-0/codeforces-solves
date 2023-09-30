#include "bits/stdc++.h"

using namespace std;

typedef long long l;
typedef pair<l, l> ll;

typedef vector<l> vl;
typedef vector<vl> vvl;

typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef queue<l> ql;
typedef queue<ll> qll;

typedef stack<l> sl;
typedef stack<ll> sll;

typedef priority_queue<ll> pqll;

vl bfs(vvl& adjlist, l start) {
	vl d(adjlist.size(), -1); ql q;
	q.push(start); d[start] = 0;
	
	while (!q.empty()) {
		l u = q.front(); q.pop();
		for (l v : adjlist[u]) if (d[v] == -1) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	
	return d;
}

l to_cicle(vvl& adjlist, l start) {
	vl d(adjlist.size(), -1); sll s;
	s.push(ll(start, -1));
	
	while (!s.empty()) {
		l u = s.top().first, lu = s.top().second; s.pop();
		d[u] = 0;
		for (l v : adjlist[u]) {
			if (d[v] == -1) {
				s.push(ll(v, u));
			} else if (lu != -1 && lu != v) {
				return v;
			}
		}
	}
	return -1;
}

void solve() {
	l n, a, b; scanf("%lld %lld %lld", &n, &a, &b);
	a--; b--;
	vvl adjlist(n);
	
	for (l i = 0; i < n; i++) {
		l u, v; scanf("%lld %lld", &u, &v);
		u--; v--;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	
	l target = to_cicle(adjlist, b);
	vl da = bfs(adjlist, a);
	vl db = bfs(adjlist, b);
	
	if (db[target] < da[target]) printf("yes\n");
	else printf("no\n");
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
