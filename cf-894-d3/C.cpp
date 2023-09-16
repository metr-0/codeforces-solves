#include <cstdio>

int a[200005], b[200005];

bool cmp(int n) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) return false;
	return true;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (a[0] != n) {
			printf("no\n");
			continue;
		}
		
		int cur = 0;
		b[cur++] = n;
		int x = n - 1, y = 0;
		while (x != 0 or y != n - 1) {
			if (y + 1 == a[x]) x--;
			else y++;
			
			if (x == n - 1 || y + 1 > a[x + 1])
				b[cur++] = x + 1;
		}
		
		if (cmp(n)) printf("yes\n");
		else printf("no\n");
	}
}
