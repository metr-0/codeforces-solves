#include <cstdio>

void send(bool type, int value) {
	printf("%c %d\n", type ? '!' : '?', value);
	fflush(stdout);
}

void solve() {
	int n, k; scanf("%d %d", &n, &k);
	int result = 0, t;
	for (int i = 0; i + k - 1 < n; i += k) {
		send(false, i + 1);
		scanf("%d", &t);
		result ^= t;
	}
	
	if (n % k == 0) {
		send(true, result);
		return;
	}
	
	send(false, n - (n % k / 2) - k + 1);
	scanf("%d", &t);
	result ^= t;
	
	send(false, n - k + 1);
	scanf("%d", &t);
	result ^= t;
	
	send(true, result);
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
