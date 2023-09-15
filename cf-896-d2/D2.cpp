#include <cstdio>
#include <cstring>
#include <cmath>

#define S 200005

using namespace std;

typedef long long ll;

ll a[S];
int powers[S], powers_p[S], powers_m[S];

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
	memset(powers_p, 0, sizeof powers_p);
	memset(powers_m, 0, sizeof powers_m);
	
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
	
	int count_p1 = 0, count_m1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == target) continue;
		
		ll diff = abs(a[i] - target);
		
		if (is_exp_2(diff)) {
			int e = lsb(diff);
			if (a[i] > target) powers_m[e]++;
			else powers_p[e]++;
			continue;
		}
		
		int e1 = lsb(diff);
		if (!is_exp_2(pow(2, e1) + diff)) {
			printf("no\n");
			return;
		}
		int e2 = lsb(pow(2, e1) + diff);
		
		if (a[i] > target) {
			powers[e1]++;
			powers[e2]--;
		} else {
			powers[e1]--;
			powers[e2]++;
		}
	}
	
	for (int i = S - 1; i >= 0; i--) {
		powers[i] += powers_p[i] - powers_m[i];
		if (i) {
			if (powers[i] > 0 && powers_m[i - 1] >= powers[i]) {
				powers_m[i - 1] -= powers[i];
				powers[i - 1] += powers[i];
				powers[i] = 0;
			}
			if (powers[i] < 0 && -powers_p[i - 1] <= powers[i]) {
				powers_p[i - 1] += powers[i];
				powers[i - 1] += powers[i];
				powers[i] = 0;
			}
		}
		if (powers[i] == 0) continue;
		
		printf("no\n"); return;
	}
	
	printf("yes\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
