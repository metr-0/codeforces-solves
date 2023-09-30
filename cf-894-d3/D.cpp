#include <cstdio>

typedef long long ll;

ll sum(ll n) {
	if (n % 2 == 0) return (n / 2) * (n - 1);
	return ((n - 1) / 2) * n;
}

ll bs(ll n) {
	ll lo = 2, hi = 1500000000, mid;
	while (hi - 1 != lo) {
		mid = (hi + lo) / 2;
		if (sum(mid) > n) hi = mid;
		else lo = mid;
	}
	
	return lo;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll n; scanf("%lld", &n);
		ll res = bs(n);
		printf("%lld\n", res + n - sum(res));
	}
}
