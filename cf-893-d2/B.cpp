#include <cstdio>

#define SIZE 100005

typedef long long ll;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll n, m, d; scanf("%lld %lld %lld", &n, &m, &d);
		ll s[SIZE];
		for (int i = 0; i < m; i++) scanf("%lld", &s[i]);
		
		ll sum = 0;
		
		if (s[0] != 1)
			sum += (s[0] - 2) / d + 1;
		for (int i = 1; i < m; i++)
			sum += (s[i] - s[i - 1] - 1) / d + 1;
		if (s[m - 1] != n)
			sum += (n - s[m - 1]) / d + 1;
		else sum += 1;
		
		ll best = -1;
		ll count = 0;
		
		ll save, remove;
		
		if (s[0] != 1)
			save = ((s[0] - 2) / d + 1) + ((s[1] - s[0] - 1) / d + 1);
		else
			save = (s[1] - s[0] - 1) / d + 1;
		remove = (s[1] - 2) / d + 1;
		
		if (save - remove > best) {
			best = save - remove; count = 1;
		} else if (save - remove == best) {
			count += 1;
		}
		
		for (int i = 1; i < m - 1; i++) {
			save = ((s[i] - s[i - 1] - 1) / d + 1) + ((s[i + 1] - s[i] - 1) / d + 1);
			remove = (s[i + 1] - s[i - 1] - 1) / d + 1;
			
			if (save - remove > best) {
				best = save - remove; count = 1;
			} else if (save - remove == best) {
				count += 1;
			}
		}
		
		if (s[m - 1] != n)
			save = ((s[m - 1] - s[m - 2] - 1) / d + 1) + ((n - s[m - 1]) / d + 1);
		else
			save = (s[m - 1] - s[m - 2] - 1) / d + 2;
		remove = (n - s[m - 2]) / d + 1;
		
		if (save - remove > best) {
			best = save - remove; count = 1;
		} else if (save - remove == best) {
			count += 1;
		}
		
		printf("%lld %lld\n", sum - best, count);
	}
}
