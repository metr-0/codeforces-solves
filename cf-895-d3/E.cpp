#include <cstdio>

#define S 100005

char s[S];
int a[S], pref[S + 1];

void solve() {
	int n; scanf("%d", &n);
	pref[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pref[i + 1] = pref[i] ^ a[i];
	}
	scanf("%s", s);
	int x0 = 0, x1 = 0;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') x0 ^= a[i];
		else x1 ^= a[i];
	}
	
	int q; scanf("%d", &q);
	bool is_first = true;
	for (int i = 0; i < q; i++) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			int l, r; scanf("%d %d", &l, &r);
			int delta = pref[l - 1] ^ pref[r];
			x0 ^= delta; x1 ^= delta;
		} else {
			int g; scanf("%d", &g);
			if (is_first) is_first = false;
			else printf(" ");
			printf("%d", g ? x1 : x0);
		}
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
