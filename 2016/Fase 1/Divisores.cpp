#include <stdio.h>

typedef long int li;

const li MAX = 1000000010;

main() {
	
	li n;
	li a;
	li b;
	li c;
	li d;
	
	scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
	
	for(n=a; n<=c; n+=a) {
		if(n%b && !(c%n) && d%n) {
			printf("%ld", n);
			return 0;
		}
	}
	
	printf("-1");
	
}
