#include "bits/stdc++.h"

#define S 55
#define M 900000000

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

typedef priority_queue<l> pql;
typedef priority_queue<ll> pqll;

void solve() {
	l n; scanf("%lld", &n);
	
	vvl incl(S, vl(n, 0));
	vl empty(S, 1);
	
	for (l i = 0; i < n; i++) {
		l k; scanf("%lld", &k);
		for (l j = 0; j < k; j++) {
			l t; scanf("%lld", &t);
			incl[t][i] = 1;
			empty[t] = 0;
		}
	}
	
	l ans = 0;
	
	for (l i = 0; i < S; i++) {
		if (empty[i]) continue;
		
		l count = 0;
		for (l j = 0; j < S; j++) {
			if (empty[j]) continue;
			
			bool f = false;
			for (l ij = 0; ij < n; ij++) {
				if (incl[j][ij] && !incl[i][ij]) {
					f = true; break;
				}
			}
			if (f) count += 1;
		}
		ans = max(ans, count);
	}
	
	printf("%lld\n", ans);
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
