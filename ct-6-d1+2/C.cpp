#include <cstdio>
#include <cstring>

#define S 100005

int a[S];
int top[S], down[S];

void solve() {
    memset(top, 0, sizeof(top));
    memset(down, 0, sizeof(down));
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        top[a[i]] = -1; down[a[i]] = -1;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        while (cur <= a[i]) {
            if (top[cur] == -1) top[cur] = i + 1;
            cur++;
        }
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (cur <= a[i]) {
            if (down[cur] == -1) down[cur] = i + 1;
            cur++;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (i != 1) printf(" ");
        if (top[i])
            printf("%d", 2 * (down[i] - top[i] + 1));
        else printf("%d", 0);
    }
    printf("\n");
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

