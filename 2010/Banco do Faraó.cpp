#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 100010;
const int NINF = -999999999;

int n;				//Contas
int v[MAX];			//Saldo das contas
int tree[4*MAX];

void showTree() {
	printf("\n\n");
	for(int k=1; k<4*n; k++) {
		printf("tree[%d] = %d\n", k, tree[k]);
	}
	printf("\n\n");
}

void build(	int i,	//Index
			int l,	//Left index interval
			int r	//Right index interval
			) {
	if(l == r) {
		tree[i] = v[l];
		//printf("tree[%d] = %d\n", i, tree[i]);
	}
	else {
		int ls = 2*i; 		//Left son
		int m = (l+r)/2;	//Middle
		int rs = 2*i+1;		//Right son
		build(ls, l, m);
		build(rs, m+1, r);
		tree[i] = tree[ls]+tree[rs];
	}
}

void build() {
	build(1, 1, n);
	//showTree();
}

int query(	int i,	//Index
			int l,	//Left index
			int r,	//Right index
			int ql,	//Left query index
			int qr	//Right query index
			) {
	if(ql<=l && r<=qr) {
		return tree[i];
	}
	if(qr<l || ql>r) {
		return 0;
	}
	int ls = 2*i;		//Left son
	int m = (l+r)/2;	//Middle
	int rs = 2*i+1;		//Right son
	return query(ls, l, m, ql, qr) + query(rs, m+1, r, ql, qr);
}

int query(int l, int r) {
	return query(1, 1, n, l, r);
}

int max_sum(int &a, int &b) {
	int q = query(a, b);
	while(a!=1 || b!=1) {
		if(v[a] < 0) {
			q -= v[a++];
		}
		else if(v[b] < 0) {
			q -= v[b--];
		}
		else {
			break;
		}
	}
	return q;
}

main() {
	
	int t;	//Instâncias
	int q;	//Consultas
	int a;
	int b;
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		for(int k=1; k<=n; k++) {
			scanf("%d", &v[k]);
		}
		build();
		scanf("%d", &q);
		for(int k=0; k<q; k++) {
			scanf("%d %d", &a, &b);
			printf("%d ", max_sum(a, b));
			printf("%d\n", b-a+1);
		}
	}
	
}
