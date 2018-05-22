#include <stdio.h>

main() {
	
	int h;	//Altura
	int l;	//Largura
	
	scanf("%d %d", &h, &l);
	
	int m[h][l];
	
	for(int y=0; y<h; y++) {
		for(int x=0; x<l; x++) {
			scanf("%d", &m[h][l]);
		}
	}
	
}
