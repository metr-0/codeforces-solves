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
	l meven = 0, modd = 0;
	for (l i = 0; i < n; i++) {
		l a; scanf("%lld", &a);
		
		if (!i) {
			modd = a;
			meven = max(a, 0ll);
			continue;
		}
		
		l old_meven = meven, old_modd = modd;
		meven = max(old_modd + a, max(old_modd, old_meven));
		modd = max(old_modd + a, old_meven);
	}
	
	printf("%lld\n", max(meven, modd));
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
