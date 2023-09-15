#include <cstdio>

typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		
		int a[200005];
		ll count = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		bool f = false;
		for (int i = 0; i < n - 1; i++) {
			count += a[i];
			if (f && !a[i]) count++;
			if (!f && a[i]) f = true;
		}
		
		printf("%lld\n", count);
	}
}
