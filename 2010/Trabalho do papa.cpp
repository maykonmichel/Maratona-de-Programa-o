//Maratona de programa��o 2010 - Trabalho do papa

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 1010;
const int INF = 1000010;

pii c[MAX];

int dp(int i, int p) {
	if(!i) {
		return 0;
	}
	if(p < 0) {
		return -1;
	}
	return max(dp(i-1, min(p-c[i].first, c[i].second-c[i].first))+1, dp(i-1, p));
}

main() {
	
	int n;	//N�mero de caixas
	
	scanf("%d", &n);
	
	int p;	//Peso
	int r;	//Resist�ncia
	
	for(int k=1; k<=n; k++) {
		scanf("%d %d", &p, &r);
		c[k] = make_pair(p, r);
	}
	
	printf("%d\n", dp(n, INF));
	
}
