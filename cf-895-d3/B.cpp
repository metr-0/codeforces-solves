#include <cstdio>
#include <cstring>

void solve() {
	int n; scanf("%d", &n);
	int room[410]; memset(room, 0, sizeof room);
	for (int i = 0; i < n; i++) {
		int d, s; scanf("%d %d", &d, &s);
		if (room[d] == 0 || s < room[d]) room[d] = s;
	}
	
	int cur = 1, max = 410;
	while (true) {
		if (room[cur]) {
			int t = cur + (room[cur] - 1) / 2;
			if (max > t) max = t;
		}
		if (cur >= max) break;
		cur++;
	}
	
	printf("%d\n", cur);
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) solve();
}
