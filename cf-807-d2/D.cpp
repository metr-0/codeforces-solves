#include <cstdio>
#include <cmath>

typedef long long ll;

char s[200005], t[200005];
int start_s[200005], start_t[200005],
	end_s[200005], end_t[200005];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		
		scanf("%s %s", s, t);
		
		if (s[0] != t[0]) {
			printf("-1\n"); continue;
		}
		
		int count_s = 1, count_t = 1;
			
		start_s[0] = start_t[0] = 0;
		end_s[0] = end_t[0] = 0;
		
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				end_s[count_s - 1] = i;
			} else {
				start_s[count_s] = i;
				end_s[count_s] = i;
				count_s++;
			}
			
			if (t[i] == t[i - 1]) {
				end_t[count_t - 1] = i;
			} else {
				start_t[count_t] = i;
				end_t[count_t] = i;
				count_t++;
			}
		}
		
		if (count_s != count_t) {
			printf("-1\n"); continue;
		}
		
		ll ans = 0;
		for (int i = 0; i < count_s; i += 2)
			ans += abs(start_s[i] - start_t[i]) + abs(end_s[i] - end_t[i]);
		
		printf("%lld\n", ans);
	}
}
