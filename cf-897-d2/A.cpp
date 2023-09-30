#include <cstdio>
#include <utility>
#include <algorithm>

#define S 40005

using namespace std;

typedef pair<int, int> ii;

ii array[S];

void solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		array[i] = ii(t, i);
	}
	sort(array, array + n);
	for (int i = 0; i < n; i++) {
		array[i] = ii(array[i].second, n - i);
	}
	sort(array, array + n);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", array[i].second);
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
