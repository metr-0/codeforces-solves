#include "bits/stdc++.h"

#define S 105
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

l a[S];

void solve() {
	l n; scanf("%lld", &n);
	for (l i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	
	l cur = 0;
	for (l i = 0; i < n; i++) {
		cur++;
		
		if (cur == a[i]) cur++;
	}
	
	printf("%lld\n", cur);
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
