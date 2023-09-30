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
	l n; scanf("%lld", &n);
	l s1, e1; scanf("%lld %lld", &s1, &e1);
	bool f = true;
	for (l i = 1; i < n; i++) {
		l s, e; scanf("%lld %lld", &s, &e);
		if (e < e1 || s < s1) continue;
		f = false;
	}
	
	if (f) printf("%lld\n", s1);
	else printf("%lld\n", (l)-1);
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
