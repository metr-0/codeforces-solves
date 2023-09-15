#include <cstdio>
#include <cstring>

#define S 4005
#define M 998244353

typedef long long l;

int n, k;
l memo[S][S], sums[S][S], powk[S];

l rec(int idx, int len) {
	if (memo[idx][len] != -1) return memo[idx][len];
	if (idx == n) return len == k;
	
	l sum = 0;
	if (len == k) {
		sum = (sum + rec(idx + 1, 1) * k + powk[n - idx]) % M;
	} else {
		sum = (sum + rec(idx + 1, len + 1) * (k - len)) % M;
		if (len == 1) sums[idx][len] = rec(idx + 1, 1);
		else if (len) {
			if (sums[idx][len - 1] == -1) rec(idx, len - 1);
			sums[idx][len] = (sums[idx][len - 1] + rec(idx + 1, len)) % M;
		}
		if (len) sum = (sum + sums[idx][len]) % M;
	}
	
	memo[idx][len] = sum;
	return sum;
}

int main() {
	scanf("%d %d", &n, &k);
	powk[0] = 1;
	for (int i = 1; i < S; i++)
		powk[i] = powk[i - 1] * k % M;
	for (int i = 0; i < S; i++) {
		memset(memo[i], -1, sizeof memo[i]);
		memset(sums[i], -1, sizeof sums[i]);
	}
	printf("%lld", rec(0, 0));
}
