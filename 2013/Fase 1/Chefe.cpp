//Maratona de programação 2013 - Fase 1 - Chefe

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 510;

int r[MAX];		//Registro
int ie[MAX];	//Idade[empregado]
int ce[MAX];	//Cargo[empregado]
int ec[MAX];	//Empregado[cargo]

vector<int> g[MAX];	//Gerencias[empregado]

int dfs(int e) {
	//printf("\t\t%d\n", e);
	int c = ec[e];
	if(r[e] == -1) {
		r[e] = ie[e];
		for(int k=0; k<g[c].size(); k++) {
			if()
			r[e] = min(r[e], dfs(ce[g[c][k]]));
		}
	}
	return r[e];
}

main() {
	
	int n;	//Número de empregados
	int m;	//Número de relações de gerência direta
	int i;	//Número de instruções
	
	scanf("%d %d %d", &n, &m, &i);
	
	for(int k=1; k<=n; k++) {
		scanf("%d", &ie[k]);
		ce[k] = k;
		ec[k] = k;
	}
	
	int x;
	int y;
	
	while(m--) {
		scanf("%d %d", &x, &y);
		g[y].push_back(x);
	}
	
	while(i--) {
		scanf(" %c", &m);	//Identificador
		if(m == 'T') {
			int a;
			int b;
			scanf("%d %d", &a, &b);
			swap(ce[a], ce[b]);
			swap(ec[a], ec[b]);
		}
		else {
			int e;
			scanf("%d", &e);
			memset(r, -1, sizeof(r));
			printf("\t\t%d\n", dfs(e));
		}
	}
	
}
