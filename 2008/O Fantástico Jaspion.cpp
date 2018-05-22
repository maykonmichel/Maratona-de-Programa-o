//Maratona de programa��o 2008 - O Fant�stico Jaspion

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

const int MAX = 10010;

main() {
	
	int t;	//Inst�ncias
	
	scanf("%d", &t);
	
	int m;	//N�mero de palavras no dicion�rio
	int n;	//N�mero de linhas na letra da m�sica
	
	string j;	//Palavra em japon�s
	string p;	//Significado em portugu�s
	
	map<string, string> d;	//Dicion�rio
	
	while(t--) {
		
		d.clear();
		
		scanf("%d %d ", &m, &n);
		
		while(m--) {
			getline(cin, j);
			getline(cin, p);
			d[j] = p;
		}
		
		while(n--) {
			getline(cin, j);	//Linha em japon�s
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
