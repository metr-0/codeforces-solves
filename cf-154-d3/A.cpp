#include <cstdio>

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		char buf[10];
		scanf("%s", buf);
		
		if (buf[0] == '1') printf("%d\n", 17);
		else if (buf[0] == '2') printf("%d\n", 23);
		else if (buf[0] == '3') printf("%d\n", 31);
		else if (buf[0] == '4') printf("%d\n", 43);
		else if (buf[0] == '5') printf("%d\n", 59);
		else if (buf[0] == '6') printf("%d\n", 61);
		else if (buf[0] == '7') printf("%d\n", 73);
		else if (buf[0] == '8') printf("%d\n", 83);
		else if (buf[0] == '9') printf("%d\n", 97);
	}
}
