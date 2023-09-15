#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, x; scanf("%d %d", &n, &x);
		
		int h[205];
		for (int i = 0; i < 2 * n; i++)
			scanf("%d", &h[i]);
		sort(h, h + 2 * n);
		
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (h[i + n] - h[i] >= x) continue;
			f = false; break;
		}
		
		if (f) printf("yes\n");
		else printf("no\n");
	}
}
