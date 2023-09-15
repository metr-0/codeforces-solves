#include <cstdio>
#include <queue>

#define S 200005

using namespace std;
typedef long long l;
typedef priority_queue<int, vector<int>, greater<int>> pqi;

void solve() {
    int n, m, d; scanf("%d %d %d", &n, &m, &d);
    int a[S];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    l cur = 0, best = 0;
    pqi pq;
    for (int i = 0; i < n; i++) {
        cur -= d;
        if (a[i] > 0) { cur += a[i]; pq.push(a[i]); }
        if (pq.size() > m) { cur -= pq.top(); pq.pop(); }
        if (cur > best) best = cur;
    }

    printf("%lld\n", best);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

