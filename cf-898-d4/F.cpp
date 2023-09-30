#include <cstdio>

#define S 200005

int a[S], h[S];

void solve() {
    int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	
	int cur = 0, max = 0;
	int cur_sum = 0;
	
	for (int i = 0; i < n; i++) {
		if (i == 0 || h[i - 1] % h[i]) {
			cur = 0; cur_sum = 0;
		}
		cur += 1; cur_sum += a[i];
		while (cur_sum > k) {
			cur_sum -= a[i + 1 - cur];
			cur--;
		}
		
		if (cur > max) max = cur;
	}
	
	printf("%d\n", max);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

