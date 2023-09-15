#include <cstdio>

typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, c, q; scanf("%d %d %d", &n, &c, &q);
		char s[200005]; scanf("%s", s);
		
		ll left[45], len[45], start[45];
		for (int i = 0; i < c; i++) {
			ll l, r; scanf("%lld %lld", &l, &r);
			
			if (i) left[i] = left[i - 1] + len[i - 1];
			else left[i] = n;
			
			len[i] = r - l + 1;
			start[i] = l;
		}
		
		for (int i = 0; i < q; i++) {
			ll k; scanf("%lld", &k); k--;
			
			while (k >= n) {
				int j;
				for (j = 0; j < c - 1; j++) {
					if (k >= left[j + 1]) continue;
					break;
				}
				ll offset = k - 1 - left[j];
				k = start[j] + offset;
			}
			
			printf("%c\n", s[k]);
		}
	}
}
