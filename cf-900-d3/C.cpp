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

l sumn(l n) {
	return n * (n + 1) / 2;
}

void solve() {
	l n, k, x; scanf("%lld %lld %lld", &n, &k, &x);
	l minx = sumn(k);
	l maxx = sumn(n) - sumn(n - k);
	
	if (minx <= x && x <= maxx) printf("yes\n");
	else printf("no\n");
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
