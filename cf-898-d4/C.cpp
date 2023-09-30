#include <cstdio>
#include <algorithm>

using namespace std;

void solve() {
	int res = 0;
    char buf[20];
	for (int i = 0; i < 10; i++) {
		scanf("%s", buf);
		for (int j = 0; j < 10; j++) {
			if (buf[j] == '.') continue;
			res += min(min(9 - i, 9 - j), min(i, j)) + 1;
		}
	}
	printf("%d\n", res);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

