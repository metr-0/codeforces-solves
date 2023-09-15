#include <cstdio>

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
	}
	
	if (n % 2 == 0) printf("2\n1 %d\n1 %d\n", n, n);
	else printf("4\n1 %d\n1 %d\n2 %d\n2 %d\n", n - 1, n - 1, n, n);
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
