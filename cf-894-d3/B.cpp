#include <cstdio>

int a[200005], b[400005];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int m = 0;
		b[m++] = a[0];
		for (int i = 1; i < n; i++) {
			b[m++] = a[i];
			if (a[i] < a[i - 1]) b[m++] = a[i];
		}
		printf("%d\n", m);
		for (int i = 0; i < m; i++) {
			if (i != m - 1) printf("%d ", b[i]);
			else printf("%d\n", b[i]);
		}
	}
}
