#include <cstdio>
#include <cstring>
#include <cmath>

#define S 200005

using namespace std;

typedef long long ll;

ll a[S];
int powers[S];

bool is_exp_2(ll n) {
	return (n & (n - 1)) == 0;
}

int lsb(ll n) {
	int res = 0;
	while (true) {
		if (n % 2) return res;
		res++; n /= 2;
	}
}

void solve() {
	memset(powers, 0, sizeof powers);
	int n; scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	if (sum % n) {
		printf("no\n"); return;
	}
	ll target = sum / n;
	
	for (int i = 0; i < n; i++) {
		if (a[i] == target) continue;
		
		ll diff = abs(a[i] - target);
		int e1 = lsb(diff);
		if (!is_exp_2(pow(2, e1) + diff)) {
			printf("no\n");
			return;
		}
		int e2 = lsb(pow(2, e1) + diff);
		
		if (a[i] > target) {
			powers[e1] += 1;
			powers[e2] -= 1;
		} else {
			powers[e1] -= 1;
			powers[e2] += 1;
		}
	}
	for (int i = 0; i < S; i++) {
		if (!powers[i]) continue;
		printf("no\n"); return;
	}
	
	printf("yes\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
