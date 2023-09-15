#include <cstdio>

#define S 3005

char s[S];
int pref0[S][S], pref1[S][S], suff0[S][S], suff1[S][S];
int count1[S];

void solve() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", s);
	
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) {
		if (i == 0) {
			pref0[i][j] = pref1[i][j] = 0;
			continue;
		}
		
		if (s[i - 1] == '0') {
			pref0[i][j] = pref0[i - 1][j] + 1;
			pref1[i][j] = j ? (pref1[i - 1][j - 1] + 1) : 0;
		} else {
			pref0[i][j] = j ? (pref0[i - 1][j - 1] + 1) : 0;
			pref1[i][j] = pref1[i - 1][j] + 1;
		}
	}
	
	for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) {
		if (pref0[i - 1][j] > pref0[i][j]) pref0[i][j] = pref0[i - 1][j];
		if (j && pref0[i][j - 1] > pref0[i][j]) pref0[i][j] = pref0[i][j - 1];
		
		if (pref1[i - 1][j] > pref1[i][j]) pref1[i][j] = pref1[i - 1][j];
		if (j && pref1[i][j - 1] > pref1[i][j]) pref1[i][j] = pref1[i][j - 1];
	}
	
	for (int i = n; i >= 0; i--) for (int j = 0; j <= k; j++) {
		if (i == n) {
			suff0[i][j] = suff1[i][j] = 0;
			continue;
		}
		
		if (s[i] == '0') {
			suff0[i][j] = suff0[i + 1][j] + 1;
			suff1[i][j] = j ? (suff1[i + 1][j - 1] + 1) : 0;
		} else {
			suff0[i][j] = j ? (suff0[i + 1][j - 1] + 1) : 0;
			suff1[i][j] = suff1[i + 1][j] + 1;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) for (int j = 0; j <= k; j++) {
		if (suff0[i + 1][j] > suff0[i][j]) suff0[i][j] = suff0[i + 1][j];
		if (j && suff0[i][j - 1] > suff0[i][j]) suff0[i][j] = suff0[i][j - 1];
		
		if (suff1[i + 1][j] > suff1[i][j]) suff1[i][j] = suff1[i + 1][j];
		if (j && suff1[i][j - 1] > suff1[i][j]) suff1[i][j] = suff1[i][j - 1];
	}
	
	for (int i = 0; i < S; i++) count1[i] = -1;
	
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) {
		if (count1[pref0[i][j]] < suff1[i][k - j])
			count1[pref0[i][j]] = suff1[i][k - j];
		if (count1[suff0[i][j]] < pref1[i][k - j])
			count1[suff0[i][j]] = pref1[i][k - j];
	}
	
	for (int a = 1; a <= n; a++) {
		int best = -1;
		for (int i = 0; i < S; i++) {
			if (count1[i] == -1) continue;
			if (a * i + count1[i] > best) best = a * i + count1[i];
		}
		
		if (a != 1) printf(" ");
		printf("%d", best);
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
