#include <cstdio>
#include <algorithm>

#define S 200005

using namespace std;

int a[S];

int solve() {
    int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	sort(a, a + n);
	
	int ans = 0;
	
	for (int i = 1; i < n; i++) {
		if ((long long)i * (a[i] - a[i - 1]) + ans > k) {
			return a[i - 1] + (k - ans) / i;
		}
		ans += i * (a[i] - a[i - 1]);
	}
	
	return a[n - 1] + (k - ans) / n;
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) printf("%d\n", solve());
}

