#include "bits/stdc++.h"

#define S 200005
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
	l n, k; scanf("%lld %lld", &n, &k);
	bool f = false;
	for (l i = 0; i < n; i++) {
		l t; scanf("%lld", &t);
		if (t == k) f = true;
	}
	
	if (f) printf("yes\n");
	else printf("no\n");
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
