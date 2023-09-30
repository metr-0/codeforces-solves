#include <cstdio>

char t[] {'v', 'i', 'k', 'a'};

int main() {
	int tc; scanf("%d\n", &tc);
	while (tc--) {
		int n, m; scanf("%d %d\n", &n, &m);
		char A[25][25];
		for (int i = 0; i < n; i++)
			gets(A[i]);
		
		int cur = 0; bool flag = false;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (A[i][j] != t[cur]) continue;
				cur++;
				break;
			}
			if (cur < 4) continue;
			flag = true;
			break;
		}
		
		if (flag) printf("yes\n");
		else printf("no\n");
	}
}
