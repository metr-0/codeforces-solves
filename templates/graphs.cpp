#include "bits/stdc++.h"

using namespace std;

typedef long long l;
typedef pair<l, l> ll;

typedef vector<l> vl;
typedef vector<vl> vvl;

typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef queue<l> ql;
typedef priority_queue<ll> pqll;

vl bfs(vvl adjlist, l start) {
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

vl dijkstra(vvll adjlist, l start) {
	vl d(adjlist.size(), -1); pqll pq;
	pq.push(ll(0, start));
	
	while (!pq.empty()) {
		l u = pq.top().second, ud = pq.top().first; pq.pop();
		
		if (d[u] != -1 && d[u] <= ud) continue;
		d[u] = ud;
		
		for (ll vdv : adjlist[u]) if (d[vdv.second] == -1) {
			pq.push(ll(ud + vdv.first, vdv.second));
		}
	}
	
	return d;
}

void solve() {
	l n; scanf("%lld", &n);
	for (l i = 0; i < n; i++) {
		l t; scanf("%d", &t);
		
	}
	
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
