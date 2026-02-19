#include <stdio.h>
#include <locale.h>
#include <string.h>

// printf("\n      -----ATENCAO!----- FUNCIONALIDADE AINDA NAO IMPLEMENTADA!!!\n");

// declaro struct antes da função

struct verboirreg {
	char verboi[50], ireu[50], irtu[50], irelx[50], irnos[50], irvos[50], irelxs[50];
	
};

int preencha(struct verboirreg entra[], int j){
	int i = 0;
	FILE *arq;
	
	arq = fopen("verboirreg.txt", "rt");
	
	// FEOF retorna TRUE se tiver chegado ao final do arquivo e FALSE caso contrario
	
	while(!feof(arq)){
		fscanf(arq, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", &entra[i].verboi, &entra[i].ireu, &entra[i].irtu, &entra[i].irelx, &entra[i].irnos, &entra[i].irvos, &entra[i].irelxs);
		i++;
	}
	
	return i;
}

int procurar_verbo(struct verboirreg entrada[], char *verbo, int j) {
	
   // para eu chamar o cjgd eu tive que usar o fato de que ele é um vetor
   
   // criei uma variável "encontrado" como base e utilizei método normal de pesquisa
    int encontrado = -1;
    for (int i = 0; i <= j; i++) {
        if (strcmp(verbo, entrada[i].verboi) == 0) {
            encontrado = i;
            return encontrado;
        }
    }
    
    return encontrado;
    
}

void vetorir (struct verboirreg entra[], int j, int tam, char verbo[]){

	printf("\nInsira o modo correto:\n");
					
					int k=0;
					
					while(k<tam){
						entra[j].verboi[k] = verbo[k];
						k++;
					}
					entra[j].verboi[k] = '\0';
					
					
					printf("\n--- Conjugue o verbo ---");
					printf("\n\nEu ");
					fflush(stdin);
					gets(entra[j].ireu);
					printf("\nTu ");
					fflush(stdin);
					gets(entra[j].irtu);
					printf("\nEle(a) ");
					fflush(stdin);
					gets(entra[j].irelx);
					printf("\nNós ");
					fflush(stdin);
					gets(entra[j].irnos);
					printf("\nVós ");
					fflush(stdin);
					gets(entra[j].irvos);
					printf("\nEles(a) ");
					fflush(stdin);
					gets(entra[j].irelxs);
					
					printf("\n\n                 Verbo: %s\n", entra[j].verboi);
					printf("\n                 Eu %s", entra[j].ireu);
					printf("\n                 Tu %s", entra[j].irtu);
					printf("\n                 Ele(a) %s", entra[j].irelx);
					printf("\n                 Nós %s", entra[j].irnos);
					printf("\n                 Vós %s", entra[j].irvos);
					printf("\n                 Eles(as) %s\n", entra[j].irelxs);
				
				
	
}

void savevir (struct verboirreg entra[], int j){
	int i = 0;
	
	FILE *arq;
	
	arq = fopen("verboirreg.txt", "wt");
	
	while (i<=j){
		
	fprintf(arq, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", entra[i].verboi, entra[i].ireu, entra[i].irtu, entra[i].irelx, entra[i].irnos, entra[i].irvos, entra[i].irelxs);
	i++;
	}
			

	fclose(arq);
	
	
}


int conjuga_ca (char *radical){
		printf("\n                 Eu %so", radical);
		printf("\n                 Tu %sas", radical);
		printf("\n                 Ele(a) %sa", radical);
		printf("\n                 Nós %samos", radical);
		printf("\n                 Vós %sais", radical);
		printf("\n                 Eles(as) %sam\n", radical);
}

int conjuga_ce (char *radical){
		printf("\n                 Eu %so", radical);
		printf("\n                 Tu %ses", radical);
		printf("\n                 Ele(a) %se", radical);
		printf("\n                 Nós %semos", radical);
		printf("\n                 Vós %seis", radical);
		printf("\n                 Eles(as) %sem\n", radical);
}

int conjuga_ci (char *radical){
		printf("\n                 Eu %so", radical);
		printf("\n                 Tu %ses", radical);
		printf("\n                 Ele(a) %se", radical);
		printf("\n                 Nós %simos", radical);
		printf("\n                 Vós %sis", radical);
		printf("\n                 Eles(as) %sem\n", radical);
}

int conjuga_co (char *radical){
	printf("\n                 Eu %sonho", radical);
		printf("\n                 Tu %soes", radical);
		printf("\n                 Ele(a) %soe", radical);
		printf("\n                 Nós %somos", radical);
		printf("\n                 Vós %sondes", radical);
		printf("\n                 Eles(as) %soem\n", radical);
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	int tam, rad, j=0, k=0;
	char op, verbo[50], radical[50], sufixo[3], correcao;
	
		struct verboirreg cjgd[100];
		j = preencha(cjgd,j);
	
/*	
for(int p=0; p<j; p++){
	printf("%s %s %s %s %s %s %s\n", cjgd[p].verboi, cjgd[p].ireu, cjgd[p].irtu, cjgd[p].irelx, cjgd[p].irnos, cjgd[p].irvos, cjgd[p].irelxs);
}
*/
		
		do{
		
		printf("Opcpes:\n(C)onjugar um verbo\n(S)air do programa\nEscolha e tecle <Enter>");
		scanf("%c", &op);
		getchar();
		
		if (op=='C'){
		while  (op == 'C'){
			printf("      -----------Conjugar um Verbo\n                 Digite o verbo que quer conjugar: ");
			fflush(stdin);
			gets(verbo);
			
			
			int veja = procurar_verbo(cjgd,verbo,j);
			
			
		// parte dos códigos da conjugação
		if (veja == -1){
		
			tam = strlen(verbo);
			rad = tam-2;
			printf("\n                 ");
			int t=0, i=0;
			while (t<rad){
				radical[i]= verbo[t];
				i++;
				t++;
			}
			radical[i] = '\0';
			sufixo[0] = verbo[t];
			sufixo[1] = verbo[t+1];
			sufixo[2] = '\0';
			
				printf("\n                 Radical: %s\n                 Sufixo: %s\n\n", radical, sufixo);
					
				if (sufixo[0] == 'a'){
				
				conjuga_ca(radical);
				
				} else {
					
					if (sufixo[0] == 'e'){
				
				conjuga_ce(radical);
				
				}
				
				if (sufixo[0] == 'i'){
				
				conjuga_ci(radical);
				
				}
				
				if (sufixo[0] == 'o'){
				
				conjuga_co(radical);
				
				}
					
				}
				
				printf("\n\nA Conjugação está correta?\n[S]im ou [N]ão\nDigite e tecle <Enter>");
				fflush(stdin);
				scanf("%c", &correcao);
				getchar();
		
				
				if (correcao == 'N'){
					
					vetorir(cjgd,j,tam,verbo);
					savevir(cjgd,j);
					
				j++;
		
				}
				
			} else {
			
			printf("\n\n                 Verbo: %s\n", cjgd[veja].verboi);
					printf("\n                 Eu %s", cjgd[veja].ireu);
					printf("\n                 Tu %s", cjgd[veja].irtu);
					printf("\n                 Ele(a) %s", cjgd[veja].irelx);
					printf("\n                 Nós %s", cjgd[veja].irnos);
					printf("\n                 Vós %s", cjgd[veja].irvos);
					printf("\n                 Eles(as) %s\n", cjgd[veja].irelxs);
					
					printf("\n\n                 Posição da struct %d\n", veja);
					
		}
				
				
					
			printf("\n");
			
		// codigos da conjugação
		
			printf("      -----Opções:\n           (C)onjugar outro verbo\n           Qualquer outra letra pra Sair do programa\n           Escolha e tecle <Enter>");
			scanf("%c", &op);
			getchar();
			
			if (op!='C'){
				return 0;
			}	
		}		
	} else if (op=='S'){
		return 0;
	}
		} while (op!='C');
	
	
	return 0;
}


