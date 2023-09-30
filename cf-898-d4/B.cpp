#include <cstdio>

void solve() {
    int n; scanf("%d", &n);
	int min = 10, res = 1;
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		if (t == 0 && min != 0) {
			min = 0, t = 1;
		}
		if (min != 0 && t < min) min = t;
		res *= t;
	}
	if (min != 0) res = res / min * (min + 1);
	printf("%d\n", res);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

