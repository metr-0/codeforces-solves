#include <cstdio>

void solve() {
	int n, m; scanf("%d %d", &n, &m);
	
	int k;
	if (n + 1 > m) k = m;
	else k = n + 1;
	
	printf("%d\n", m == 1 ? 0 : k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j) printf(" ");
			
			if (j >= k) printf("%d", j);
			else if (i >= k - 1) printf("%d", (j + 1) % k);
			else printf("%d", (j + (k - 1 - i)) % k);
		}
		printf("\n");
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
