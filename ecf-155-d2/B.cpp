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
	l suma = 0, mina = INT32_MAX, sumb = 0, minb = INT32_MAX;
	for (l i = 0; i < n; i++) {
		l a; scanf("%lld", &a);
		suma += a;
		if (a < mina) mina = a;
	}
	for (l i = 0; i < n; i++) {
		l b; scanf("%lld", &b);
		sumb += b;
		if (b < minb) minb = b;
	}
	
	printf("%lld\n", min(suma + n * minb, sumb + n * mina));
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
