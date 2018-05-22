//Maratona de programação - 2008 - Fase 2 - Bora Bora

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXP = 11;

vector<pii> mj[MAXP];	//Mãos dos jogadores
queue<pii> ps;			//Pilha de saque

int p;		//Número de jogadores
pii cd;		//Carta no topo da pilha de descarte
int d;		//Direção
int j;		//Jogador atual
bool ec;	//Efeito da carta
bool pv;	//Perde a vez

void proximo() {
	j += d;
	if(j > p) {
		j = 1;
	}
	else if(!j) {
		j = p;
	}
}

void compra() {
	mj[j].push_back(ps.front());
	ps.pop();
}

void penalidade(int c) {
	switch(c) {
		case 12:	//Dama
			d *= -1;
			break;
		case 7:		//Sete
			compra();
		case 1:		//Ás
			compra();
		case 11:	//Valete
			pv = true;
	}
	ec = false;
}

bool descarta(int i) {
	if(mj[j][i].first==cd.first || mj[j][i].second==cd.second) {
		cd = mj[j][i];
		mj[j].erase(mj[j].begin()+i);
		ec = true;
		return true;
	}
	return false;
}

bool comp(pii a, pii b) {
	return a>b;
}

void joga() {
	bool flag = false;	//Descartou
	
	sort(mj[j].begin(), mj[j].end(), comp);
	for(int k=0; k<mj[j].size() && !flag; k++) {
		flag = descarta(k);
	}
	if(!flag) {
		compra();
		descarta(mj[j].size()-1);
	}
}

void clear() {
	queue<pii> empty;
	swap(ps, empty);
	
	d = 1;
	j = 1;
	ec = true;
	pv = false;
	
	for(int k=0; k<MAXP; k++) {
		mj[k].clear();
	}
}

main() {
	
	int m;	//Número de cartas/jogador
	int n;	//Número de cartas no baralho 
	
	int x;	//Valor da carta
	char s;	//Naipe da carta
	int nc;	//Naipe da carta
	
	while(true) {
		clear();
		
		scanf("%d %d %d", &p, &m, &n);
		
		if(!p) {
			return 0;
		}
		
		for(int k=1; k<=n; k++) {
			scanf("%d %c", &x, &s);
			
			nc = 0;
			
			switch(s) {
				case 'S':
					nc++;
				case 'H':
					nc++;
				case 'D':
					nc++;
				case 'C':
					nc++;
			}
			
			if(k-1 < p*m) {
				//printf("\t\t%d\n", (k-1)/m+1);
				mj[(k-1)/m+1].push_back(make_pair(x, nc));
			}
			else {
				ps.push(make_pair(x, nc));
			}
		}
		
		/*for(int k=1; k<=p; k++) {
			printf("\n%d: ", k, mj[k].size());
			for(int i=0; i<mj[k].size(); i++) {
				printf(" (%d %d)", mj[k][i].first, mj[k][i].second);
			}
		}*/
		
		cd = ps.front();
		ps.pop();
		
		while(true) {
			if(ec) {
				penalidade(cd.first);
			}
			if(!pv)	{
				joga();
			}
			if(mj[j].empty()) {
				printf("%d\n", j);
				break;
			}
			pv = false;
			proximo();
		}
	}
	
}
