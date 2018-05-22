#include <stdio.h>

const int MAX = 1000000010;

main() {
	
	int n;
	int a;
	int b;
	int c;
	int d;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	for(n=a; n<=c; n+=a) {
		if(n%b && !(c%n) && d%n) {
			break;
		}
	}
	
	printf("%d", n>=c ? -1 : n);
	
}
