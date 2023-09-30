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

char s[S];
l lefts[S], rights[S];
l idx[S], inv[S];

void solve() {
	l n, k; scanf("%lld %lld", &n, &k);
	scanf("%s", s);
	
	memset(inv, 0, sizeof(inv));
	
	for (l i = 0; i < k; i++)
		scanf("%lld", &lefts[i]);
	for (l i = 0; i < k; i++)
		scanf("%lld", &rights[i]);
	
	for (l i = 0; i < k; i++) {
		lefts[i]--; rights[i]--;
		l left = lefts[i], right = rights[i];
		for (l j = left; j <= right; j++)
			idx[j] = i;
	}
	l q; scanf("%lld", &q);
	while (q--) {
		l t; scanf("%lld", &t);
		t--;
		inv[min(t, lefts[idx[t]] + rights[idx[t]] - t)]++;
	}
	
	for (l i = 0; i < n; i++) {
		l left = lefts[idx[i]], right = rights[idx[i]];
		if (i == left) continue;
		
		if (i <= (left + right) / 2) inv[i] += inv[i - 1];
		else inv[i] = inv[right + left - i];
	}
	
	for (l i = 0; i < n; i++) {
		if (inv[i] % 2 == 0)
			printf("%c", s[i]);
		else
			printf("%c", s[rights[idx[i]] + lefts[idx[i]] - i]);
	}
	printf("\n");
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
