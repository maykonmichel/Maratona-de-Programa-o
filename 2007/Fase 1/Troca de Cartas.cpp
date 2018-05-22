#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

main() {
	
	int a;
	int b;
	int c;
	set<int> x;
	set<int> y;
	
	scanf("%d %d", &a, &b);
	
	for(int k=0; k<a; k++) {
		scanf("%d", &c);
		x.insert(c);
	}
	
	for(int k=0; k<b; k++) {
		scanf("%d", &c);
		y.insert(c);
	}
	
	c = 0;
	
	if(x.size() > y.size()) {
		x.swap(y);
	}
	
	/*printf("x:");
	for(set<int>::iterator it=x.begin(); it!=x.end(); it++) {
		printf(" %d", *it);
	}
	printf("\n");
	
	printf("y:");
	for(set<int>::iterator it=y.begin(); it!=y.end(); it++) {
		printf(" %d", *it);
	}
	printf("\n\n");*/
	
	for(set<int>::iterator it=x.begin(); it!=x.end();) {
		int n = *it;
		it++;
		if(y.erase(n)) {
			x.erase(n);
		}
	}
	
	printf("%d", x.size()<y.size() ? x.size() : y.size());
	
}
