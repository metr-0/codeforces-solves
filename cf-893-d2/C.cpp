#include <cstdio>

void solve() {
	int n; scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) continue;
		for (int j = i; j <= n; j *= 2) {
			if (j != 1) printf(" ");
			printf("%d", j);
		}
	}
	
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
