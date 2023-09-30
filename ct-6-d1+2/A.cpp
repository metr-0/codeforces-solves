#include <cstdio>

int solve() {
    int n, k, x; scanf("%d %d %d", &n, &k, &x);

    if (n < k || x < k - 1) return -1;

    int res = (k - 1) * k / 2;
    if (x == k) return res + (n - k) * (x - 1);
    else return res + (n - k) * x;
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) printf("%d\n", solve());
}

