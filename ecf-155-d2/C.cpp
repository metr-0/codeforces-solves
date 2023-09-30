#include "bits/stdc++.h"

#define S 200005
#define M 998244353ll

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

l fac[S];
char s[S];

void solve() {
	scanf("%s", s);
	l n = strlen(s);
	
	l count, ans1 = 0, ans2 = 0;
	for (l i = 0; i < n; i++) {
		if (i == 0) count = 1;
		else if (s[i] != s[i - 1]) {
			ans1 += count - 1;
			ans2++;
			count = 1;
		} else count++;
	}
	ans1 += count - 1;
	ans2 = ((M + ans2) * (M + fac[count])) % M;
	
	printf("%lld %lld\n", ans1, ans2);
}

int main() {
	fac[0] = 1; fac[1] = 1;
	for (l i = 2; i < S; i++)
		fac[i] = (i * (M + fac[i - 1])) % M;
	
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}
