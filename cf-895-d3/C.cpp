#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi primes;
bool f[10005];

void solve() {
	int l, r; scanf("%d %d", &l, &r);
	if (l <= 2 && r >= 4) l = 4;
	if (l % 2 == 0 && l / 2 > 1) {
		printf("%d %d\n", 2, 2 * (l / 2 - 1));
		return;
	}
	if (l != r && (l + 1) / 2 > 1) {
		printf("%d %d\n", 2, 2 * ((l + 1) / 2 - 1));
		return;
	}
	if (l == r) {
		for (int p : primes) {
			if (p > l) break;
			if (l % p == 0 && l / p > 1) {
				printf("%d %d\n", p, p * (l / p - 1));
				return;
			}
		}
	}
	printf("%d\n", -1);
}

int main() {
	for (int i = 2; i < 10005; i++) {
		if (f[i]) continue;
		primes.push_back(i);
		for (int j = i * i; j < 10005; j += i)
			f[j] = true;
	}
	
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
