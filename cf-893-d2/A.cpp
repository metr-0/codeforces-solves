#include <cstdio>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		int first = a + (c / 2) + (c % 2);
		int second = b + (c / 2);
		
		if (first > second) printf("First\n");
		else printf("Second\n");
	}
}
