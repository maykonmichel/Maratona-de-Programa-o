//Maratona de programação 2008 - O Fantástico Jaspion

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

const int MAX = 10010;

main() {
	
	int t;	//Instâncias
	
	scanf("%d", &t);
	
	int m;	//Número de palavras no dicionário
	int n;	//Número de linhas na letra da música
	
	string j;	//Palavra em japonês
	string p;	//Significado em português
	
	map<string, string> d;	//Dicionário
	
	while(t--) {
		
		d.clear();
		
		scanf("%d %d ", &m, &n);
		
		while(m--) {
			getline(cin, j);
			getline(cin, p);
			d[j] = p;
		}
		
		while(n--) {
			getline(cin, j);	//Linha em japonês
			istringstream iss(j);	
			while(iss >> p) {	//Cada palavra da linha
				if(d.find(p) != d.end()) {
					cout << d[p];
				}
				else {
					cout << p;
				}
				cout << " ";
			}
			cout << "\n";
		}
		
		cout << "\n";
		
	}
	
}
