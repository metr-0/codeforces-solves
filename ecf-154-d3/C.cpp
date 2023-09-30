#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		char a[200005]; scanf("%s", a);
		int n = strlen(a);
		
		stack<int> st;
		
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == '0') {
				if (st.size() < 2 || st.top() == 1) {
					f = false; break;
				}
				st.pop(); st.push(-1);
			} else if (a[i] == '1') {
				if (st.size() < 2) continue;
				if (st.top() == -1) {
					f = false; break;
				}
				st.pop(); st.push(1);
			} else if (a[i] == '+') {
				if (st.empty()) st.push(1);
				else if (st.top() == -1) st.push(-1);
				else st.push(0);
			} else if (a[i] == '-') {
				if (st.size() > 1 && st.top() == 1) {
					st.pop(); st.pop(); st.push(1);
				} else st.pop();
			}
		}
		
		if (f) printf("yes\n");
		else printf("no\n");
	}
}
