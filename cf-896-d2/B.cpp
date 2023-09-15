#include <cstdio>
#include <cmath>

#define S 200005

using namespace std;
typedef long long ll;

int x[S], y[S];

void solve() {
	int n, k, a, b; scanf("%d %d %d %d", &n, &k, &a, &b);
	a -= 1; b -=1;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	ll cost = 0;
	
	ll best = -1;
	for (int i = 0; i < k; i++) {
		ll dist = (ll)abs(x[i] - x[a]) + abs(y[i] - y[a]);
		if (best == -1 || dist < best) best = dist;
	}
	cost += best;
	best = -1;
	for (int i = 0; i < k; i++) {
		ll dist = (ll)abs(x[i] - x[b]) + abs(y[i] - y[b]);
		if (best == -1 || dist < best) best = dist;
	}
	cost += best;
	
	ll straight = (ll)abs(x[a] - x[b]) + abs(y[a] - y[b]);
	if (k != 0 && straight > cost) printf("%lld\n", cost);
	else printf("%lld\n", straight);
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
