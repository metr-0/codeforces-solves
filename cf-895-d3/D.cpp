#include <cstdio>

int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int n, x, y; scanf("%d %d %d", &n, &x, &y);
	long long t = ((long long)x * y) / gcd(x, y);
	int cx = n / x - n / t, cy = n / y - n / t;
	
	printf("%lld\n", (long long)n * (n + 1) / 2 - (long long)(n - cx) * (n - cx + 1) / 2 - (long long)cy * (cy + 1) / 2);
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
