#include <cstdio>
#include <cstring>

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		char a[5005], b[5005]; scanf("%s %s", a, b);
		int n = strlen(a);
		
		bool s0 = false, s1 = false, e0 = false, e1 = false;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) break;
			if (a[i] == '0') s0 = true;
			else if (a[i] == '1') s1 = true;
			if (s0 && s1) break;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] != b[i]) break;
			if (a[i] == '0') e0 = true;
			else if (a[i] == '1') e1 = true;
			if (e0 && e1) break;
		}
		
		if (s0 && e0 || s1 && e1) {
			printf("yes\n");
			continue;
		}
		
		bool f = false;
		for (int i = 1; i < n; i++) {
			if (a[i] != b[i] || a[i - 1] != b[i - 1]) continue;
			if (s0 && e1 && a[i - 1] == '0' && a[i] == '1' ||
				s1 && e0 && a[i - 1] == '1' && a[i] == '0') {
					f = true; break;
				}
		}
		if (f) printf("yes\n");
		else printf("no\n");
	}
}
