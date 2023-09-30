#include <cstdio>

#define S 100005

char buf[S];

void solve() {
	int n; scanf("%d", &n);
	scanf("%s", buf);
	
	int dif = 0, sim = 0;
	for (int i = 0; i < n / 2; i++) {
		if (buf[i] == buf[n - 1 - i]) sim += 2;
		else dif++;
	}
	if (n % 2) sim++;
	
	for (int i = 0; i <= n; i++) {
		if (i < dif) {
			printf("0"); continue;
		}
		if ((i - dif) % 2 <= n % 2 && i - dif <= sim)
			printf("1");
		else printf("0");
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
