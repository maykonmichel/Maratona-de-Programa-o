//Maratona de programação 2008 - Fase 1 - Apagando e Ganhando

#include <stdio.h>
#include <stack>

using namespace std;

typedef long int li;

main() {
	
	int n;	//Quantidade de dígitos
	int d;	//Quantos dígitos devem ser apagados
	char m;	//Digito	
	
	while(scanf("%d %d", &n, &d) && n) {
		int a = 0;		//Digitos apagados
		stack<char> s;	//Digitos restantes
		for(int k=0; k<n; k++) {
			scanf(" %c", &m);
			while(s.size() && a<d && m>s.top()) {
				s.pop();
				a++;
			}
			if(s.size() < n-d) {
				s.push(m);
			}
		}
		
		stack<char> r;
		
		while(s.size()) {
			r.push(s.top());
			s.pop();
		}
		
		while(r.size()) {
			printf("%c", r.top());
			r.pop();
		}
		printf("\n");
	}
	
}
