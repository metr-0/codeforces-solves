#include <cstdio>
#include <cstring>

#define S 200005

void solve() {
    char buf[S]; scanf("%s", buf);
    int n = strlen(buf);
    int cur_len = 0, sum = 0, min_len = 99999999;
    for (int i = 0; i < n; i++) {
        if (buf[i] == 'A') cur_len += 1;
        else {
            sum += cur_len;
            if (min_len > cur_len) min_len = cur_len;
            cur_len = 0;
        }
    }
    sum += cur_len;
    if (min_len > cur_len) min_len = cur_len;

    sum -= min_len;
    printf("%d\n", sum);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) solve();
}

