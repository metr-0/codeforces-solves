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

l a[S];

void solve() {
	l n; scanf("%lld", &n);
	
	a[0] = 1; a[1] = 3;
	printf("1 3");
	for (l i = 2; i < n; i++) {
		a[i] = a[i - 1] + 1;
		while (3 * a[i] % (a[i - 1] + a[i - 2]) == 0)
			a[i]++;
		
		printf(" %lld", a[i]);
	}
	printf("\n");
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
