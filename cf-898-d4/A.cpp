#include <cstdio>

void solve() {
    char buf[5]; scanf("%s", buf);
	if (buf[0] == 'a' || buf[1] == 'b' || buf[2] == 'c') printf("yes\n");
	else printf("no\n");
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

