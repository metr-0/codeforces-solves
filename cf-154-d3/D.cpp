#include <cstdio>

int a[200005], pref[200005], suff[200005];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		
		pref[0] = 0, pref[1] = 1, suff[n] = 0, suff[n - 1] = 0;
		
		for (int i = 2; i <= n; i++) {
			pref[i] = pref[i - 1];
			if (a[i - 1] >= a[i - 2]) pref[i]++;
		}
		for (int i = n - 2; i >= 0; i--) {
			suff[i] = suff[i + 1];
			if (a[i] >= a[i + 1]) suff[i]++;
		}
		
		int best = 999999999;
		for (int i = 0; i <= n; i++) {
			if (pref[i] + suff[i] < best)
				best = pref[i] + suff[i];
		}
		printf("%d\n", best);
	}
}
