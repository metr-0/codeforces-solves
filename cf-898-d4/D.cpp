#include <cstdio>
#include <vector>

#define S 200005

using namespace std;

typedef vector<int> vi;

char buf[S];

void solve() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", buf);
	
	vi v;
	for (int i = 0; i < n; i++) if (buf[i] == 'B')
		v.push_back(i);
	
	int lim = 0, res = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < lim) continue;
		res++;
		lim = v[i] + k;
	}
	printf("%d\n", res);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

