#include <cstdio>

#define S 200005

int a[S], b[S];

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
       
    int ors = 0;
    for (int i = 0; i < m; i++)
        ors |= b[i];

    int min = 0;
    for (int i = 0; i < n; i++)
        min ^= a[i];
    int max = 0;
    for (int i = 0; i < n; i++)
        max ^= a[i] | ors;

    if (n % 2 != 0) printf("%d %d\n", min, max);
    else printf("%d %d\n", max, min);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

