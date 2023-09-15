#include <cstdio>
#include <cmath>

void solve() {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int d = (abs(a - b) + 1) / 2;
	if (d % c) printf("%d\n", d / c + 1);
	else printf("%d\n", d / c);
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
