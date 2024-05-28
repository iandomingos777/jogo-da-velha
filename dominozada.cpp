#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define tam 28

int i, j, z, jogador, peca1, peca2, jogada = 0, global = 0;

struct p {
    int lado1;
    int lado2;
};
typedef struct p peca;


peca pecas[tam];
peca jogador1[21];
peca jogador2[21];                
peca extra[14];
peca jogo[tam];          // variaveis globais criadas
        
void gerarpecas() {
    while (z < tam) {
        for (i = 0; i < 7; i++) {
            for (j = i; j < 7; j++) {
                pecas[z].lado1 = i;
                pecas[z].lado2 = j;
                z++;
            }
        }
    }
}                             // pe�a criadas 


void embaralharpecas() {
    for (i = 0; i < tam; i++) {
        peca auxiliar;
        j = rand()%tam;
        auxiliar = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = auxiliar;
    }
}                           // embaralhando 


void mao(){
    for(i=0;i<7;i++){
        jogador1[i] = pecas[i];
        jogador2[i] = pecas[i+7];
    }
}
void ext(){
    for(i=0;i<14;i++){
        extra[i] = pecas[i+14];
    }
  }                 // mao dos jogadores e mao da mesa definidas
  

void inicio() {
	int ajuda1, ajuda2;
	peca maior; 
	maior.lado1 = -1;
	maior.lado2 = -1;
	int soma = maior.lado1 + maior.lado2;
	for (i = 0; i < 7; i++) {
     if (jogador1[i].lado1 == jogador1[i].lado2 && jogador2[i].lado1 != jogador2[i].lado2 && jogador1[i].lado1 + jogador1[i].lado2 > soma) {
            soma = jogador1[i].lado1 + jogador1[i].lado2;
            jogador = 1;
        } else if (jogador1[i].lado1 != jogador1[i].lado2 && jogador2[i].lado1 == jogador2[i].lado2 && jogador2[i].lado1 + jogador2[i].lado2 > soma) {
            soma = jogador2[i].lado1 + jogador2[i].lado2;
            jogador = 2;
        } else if (jogador1[i].lado1 == jogador1[i].lado2 && jogador2[i].lado1 == jogador2[i].lado2) {
            if (jogador1[i].lado1 + jogador1[i].lado2 > soma && jogador2[i].lado1 + jogador2[i].lado2 <= soma) {
                soma = jogador1[i].lado1 + jogador1[i].lado2;
                jogador = 1;
            } else if (jogador1[i].lado1 + jogador1[i].lado2 <= soma && jogador2[i].lado1 + jogador2[i].lado2 > soma) {
                soma = jogador2[i].lado1 + jogador2[i].lado2;
                jogador = 2;
            } else if (jogador1[i].lado1 + jogador1[i].lado2 > soma && jogador2[i].lado1 + jogador2[i].lado2 > soma) {
                if (jogador1[i].lado1 + jogador1[i].lado2 > jogador2[i].lado1 + jogador2[i].lado2) {
                    soma = jogador1[i].lado1 + jogador1[i].lado2;
                    jogador = 1;
                } else {
                    soma = jogador2[i].lado1 + jogador2[i].lado2;
                    jogador = 2;
                }
            }
        }
	}
	if (soma != -2) {
		printf("O jogador %d comeca\nJogue sua maior dupla\n", jogador);
	}
	else {    // se o codigo chegou ate aqui, nenhum dos jogadores recebeu uma dupla
	int soma1 = 0, soma2 = 0;
	for (i = 0; i < 7; i++) {
		soma1 += jogador1[i].lado1 + jogador1[i].lado2;
		soma2 += jogador2[i].lado1 + jogador2[i].lado2;
	}
	if (soma1 > soma2) {
		jogador = 1;
	}
	else if (soma2 > soma1) {
		jogador = 2;
	}
	if (soma1 != soma2) {
		printf("O jogador %d comeca\nEscolha a peca para iniciar o jogo", jogador);
	}
	else {  // se o codigo chegou aqui, nenhum dos jogadores recebeu uma dupla, e a soma das pe�as dos jogadores � igual 
	int maior1 = 0, maior2 = 0;
	for (i = 0; i < 7; i++) {
		if (jogador1[i].lado1 + jogador1[i].lado2 > maior1) {
			maior1 = jogador1[i].lado1 + jogador1[i].lado2;
		}
		if(jogador2[i].lado1 + jogador2[i].lado2 > maior2) {
			maior2 = jogador2[i].lado1 + jogador2[i].lado2;
		}
	}
	if (maior1 > maior2) {
		jogador = 1;
	}
	else {
		jogador = 2;
	    }
	}
	if (soma1 == soma2) {
		printf("O jogador %d comeca\nEscolha a peca para iniciar o jogo", jogador);
	}
  }	
}                // definido quem comeca


void inicializacao0() {
	for (i = 0; i < 21; i++) {
	jogador1[i].lado1 = -1;
	jogador1[i].lado2 = -1;
	jogador2[i].lado1 = -1;
	jogador2[i].lado2 = -1;
	}
	for (i = 0; i < tam; i++) {
	extra[i].lado1 = -1;
	extra[i].lado2 = -1;	
	}
	for (i = 0; i < tam; i++) {
		jogo[i].lado1 = -1;
		jogo[i].lado2 = -1;
	}
}               // inicializando as pecas em -1 para poder oper�-las


int interface() {
    int cont=0, cont2=0;
        if (jogador % 2 != 0) {
        	printf("Eh a vez do jogador 1\n");
        	printf("Suas pecas sao: ");
         for (i = 0; i < 21; i++) {
                if(jogador1[i].lado1!=-1){
                    printf("[%d|", jogador1[i].lado1);
                    printf("%d] ", jogador1[i].lado2);
                }
                if(jogador2[i].lado1!=-1){
                cont++;
        }
         }
        printf("\n");
        printf("O jogador 2 tem %d pecas na mao\n",cont);
        }
        else  {
        	printf("Eh a vez do jogador 2\n");
        	printf("Suas pecas sao: ");
            for (i = 0; i < 21; i++) {
               if(jogador2[i].lado1!=-1){
                printf("[%d|", jogador2[i].lado1);
                printf("%d] ", jogador2[i].lado2);
               }
                     if(jogador1[i].lado1!=-1){
                cont++;
        }
        }
         printf("\n");
        printf("O jogador 1 tem %d pecas na mao\n",cont);
    }
		for (i = 0; i < 14; i++) {
			if (extra[i].lado1 != -1 && extra[i].lado2 != -1) {
				cont2++;
			}
		}
		printf("Ainda ha %d pecas para puxar\n", cont2);	
}                  // interface informativa

void jogar(int peca1,int peca2){
    if (jogador % 2 != 0){
        for(i=0;i<21;i++){
            if(jogador1[i].lado1==peca1 && jogador1[i].lado2==peca2 && peca1!=-1 && peca2!=-1){
                jogo[jogada]=jogador1[i];
                jogador1[i].lado1=-1;
                jogador1[i].lado2=-1;
                break;
            }
        }
    }
    else{
        for(i=0;i<21;i++){
            if(jogador2[i].lado1==peca1 && jogador2[i].lado2==peca2 && peca1!=-1 && peca2!=-1){
                jogo[jogada]=jogador2[i];
                jogador2[i].lado1=-1;
                jogador2[i].lado2=-1;
                break;
            }        
        }
    }
}                    // funcao para jogar uma peca
int jogar1(int peca1,int peca2){
  int escolha=0;
  int aux=0;
  if(jogador%2==1){
			for(i=0;i<21;i++){
			if(peca1==jogador1[i].lado1 && peca2==jogador1[i].lado2){
				if(jogada==0){
					jogo[0]=jogador1[i];
				}
				else{
			if((jogo[0].lado1==jogador1[i].lado2 || jogo[0].lado1==jogador1[i].lado1) &&
			jogo[jogada-1].lado2!=jogador1[i].lado2 && jogo[jogada-1].lado2!=jogador1[i].lado1){
				for(int j=27;j>0;j--){
					jogo[j]=jogo[j-1];
				}
				if(jogo[0].lado1==jogador1[i].lado1){
					aux=jogador1[i].lado1;
					jogador1[i].lado1=jogador1[i].lado2;
					jogador1[i].lado2=aux;
				}
				jogo[0]=jogador1[i];
				jogador1[i].lado1=-1;
				jogador1[i].lado2=-1;		
			}
			else if((jogo[jogada-1].lado2==jogador1[i].lado2 || jogo[jogada-1].lado2==jogador1[i].lado1) &&
			jogo[0].lado1!=jogador1[i].lado2 && jogo[0].lado1!=jogador1[i].lado1 ){
					if(jogo[jogada-1].lado2==jogador1[i].lado2){
					aux=jogador1[i].lado1;
					jogador1[i].lado1=jogador1[i].lado2;
					jogador1[i].lado2=aux;
				}
				jogo[jogada]=jogador1[i];
				jogador1[i].lado1=-1;
				jogador1[i].lado2=-1;
			}
			if((jogo[jogada-1].lado2==jogador1[i].lado2 || jogo[jogada-1].lado2==jogador1[i].lado1) &&
			(jogo[0].lado1==jogador1[i].lado1 || jogo[0].lado1==jogador1[i].lado2)){
				printf("Voce quer inserir em qual extremidade?\n");
				printf("1-Esquerda\n2-Direita\n");	
                   	scanf("%d",&escolha);
				if(escolha==1){
						for(int j=27;j>0;j--){
					jogo[j]=jogo[j-1];
				}
					if(jogo[0].lado1==jogador1[i].lado1){
					aux=jogador1[i].lado1;
					jogador1[i].lado1=jogador1[i].lado2;
					jogador1[i].lado2=aux;
				}
				jogo[0]=jogador1[i];
				jogador1[i].lado1=-1;
				jogador1[i].lado2=-1;		
			}
			if(escolha==2){
					if(jogo[jogada-1].lado2==jogador1[i].lado2){
					aux=jogador1[i].lado1;
					jogador1[i].lado1=jogador1[i].lado2;
					jogador1[i].lado2=aux;
				}
					jogo[jogada]=jogador1[i];
				jogador1[i].lado1=-1;
				jogador1[i].lado2=-1;
			}
				}
			}
			break;
		return 1;
		}
		}
	}
		else{
			for(i=0;i<21;i++){
			if(peca1==jogador2[i].lado1 && peca2==jogador2[i].lado2){
				if(jogada==0){
					jogo[0]=jogador2[i];
				}
				else{
			if((jogo[0].lado1==jogador2[i].lado2 || jogo[0].lado1==jogador2[i].lado1) &&
			jogo[jogada-1].lado2!=jogador2[i].lado2 && jogo[jogada-1].lado2!=jogador2[i].lado1){
				for(int j=27;j>0;j--){
					jogo[j]=jogo[j-1];
				}
					if(jogo[0].lado1==jogador2[i].lado1){
					aux=jogador2[i].lado1;
					jogador2[i].lado1=jogador2[i].lado2;
					jogador2[i].lado2=aux;
				}
				jogo[0]=jogador2[i];
				jogador2[i].lado1=-1;
				jogador2[i].lado2=-1;		
			}
			else if((jogo[jogada-1].lado2==jogador2[i].lado2 || jogo[jogada-1].lado2==jogador2[i].lado1) && 
			jogo[0].lado1!=jogador2[i].lado2 && jogo[0].lado1!=jogador2[i].lado1){
					if(jogo[jogada-1].lado2==jogador2[i].lado2){
					aux=jogador2[i].lado1;
					jogador2[i].lado1=jogador2[i].lado2;
					jogador2[i].lado2=aux;
				}
				jogo[jogada]=jogador2[i];
				jogador2[i].lado1=-1;
				jogador2[i].lado2=-1;
			}
			if((jogo[jogada-1].lado2==jogador2[i].lado2 || jogo[jogada-1].lado2==jogador2[i].lado1) &&
			(jogo[0].lado1==jogador2[i].lado1 || jogo[0].lado1==jogador2[i].lado2)){
				printf("Voce quer inserir em qual extremidade?\n");
				printf("1-Esquerda\n2-Direita\n");
				scanf("%d",&escolha);
				if(escolha==1){
						for(int j=27;j>0;j--){
					jogo[j]=jogo[j-1];
				}
					if(jogo[0].lado1==jogador2[i].lado1){
					aux=jogador2[i].lado1;
					jogador2[i].lado1=jogador2[i].lado2;
					jogador2[i].lado2=aux;
				}
				jogo[0]=jogador2[i];
				jogador2[i].lado1=-1;
				jogador2[i].lado2=-1;		
			}
			if(escolha==2){
					if(jogo[jogada-1].lado2==jogador2[i].lado2){
					aux=jogador2[i].lado1;
					jogador2[i].lado1=jogador2[i].lado2;
					jogador2[i].lado2=aux;
				}
					jogo[jogada]=jogador2[i];
				jogador2[i].lado1=-1;
				jogador2[i].lado2=-1;
			}
				}
			}
			break;
			return 1;
		}
	}
		}
		global = 0;
		return 0;
}                             // funcao para jogar apos a primeira jogada


void puxando() {
	if (jogador % 2 != 0) {
		for (i = 0; i < 21; i++) {
			if (jogador1[i].lado1 == -1 && jogador1[i].lado2 == -1) {
				for (j = 0; j < 14; j++) {
					if (extra[j].lado1 != -1 && extra[j].lado2 != -1) {
						jogador1[i].lado1 = extra[j].lado1;
						jogador1[i].lado2 = extra[j].lado2;
						extra[j].lado1 = -1;
						extra[j].lado2 = -1;
						break;
					}
				}
				break;
			}
		}
	}
	else {
		for (i = 0; i < 21; i++) {
			if (jogador2[i].lado1 == -1 && jogador2[i].lado2 == -1) {
				for (j = 0; j < 14; j++) {
					if (extra[j].lado1 != -1 && extra[j].lado2 != -1) {
						jogador2[i].lado1 = extra[j].lado1;
						jogador2[i].lado2 = extra[j].lado2;
						extra[j].lado1 = -1;
						extra[j].lado2 = -1;
						break;
					}
				}
				break;
			}
		}
	}
	system("cls");
}                         // funcao para puxar uma peca


void mostrarjogo() {
	printf("O jogo esta assim:\n");
	for (i = 0; i < tam; i++) {
		if (jogo[i].lado1 != -1) {
			printf("[%d", jogo[i].lado1);
			printf("|%d] ", jogo[i].lado2);
				}
			}
	printf("\n");
}                       // mostrando a situacao atual do jogo

int win() {
    int contwin = 0;
    if (jogador % 2 != 0) {
        for (i = 0; i < 21; i++) {
            if (jogador1[i].lado1 != -1) {
                contwin++;
            }
        }
        if (contwin == 0) {
            return 1;
        }
    } else {
        for (i = 0; i < 21; i++) {
            if (jogador2[i].lado1 != -1) {
                contwin++;
            }
        }
        if (contwin == 0) {
            return 2;
        }
    }
}                      

void salvarestado() {
    FILE *file = fopen("estadomino.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar o estado.\n");
        return;
    }
    fprintf(file, "%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n", i, j, z, jogador, peca1, peca2, jogada, global);
    for (i = 0; i < 21; i++) {
    	fprintf(file, "%d %d\n", jogador1[i].lado1, jogador1[i].lado2);
    	fprintf(file, "%d %d\n", jogador2[i].lado1, jogador2[i].lado2);
	}
	for (i = 0; i < 14; i++) {
		fprintf(file, "%d %d\n", extra[i].lado1, extra[i].lado2);
	}
	for (i = 0; i < 28; i++) {
		fprintf(file, "%d %d\n", jogo[i].lado1, jogo[i].lado2);
	}
	rewind(file);
	fclose(file);
}                      

void carregarestado() {
    FILE *file = fopen("estadomino.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para carregar o estado.\n");
        return;
    }

    fscanf(file, "%d%d%d%d%d%d%d%d", &i, &j, &z, &jogador, &peca1, &peca2, &jogada, &global);

    for (i = 0; i < 21; i++) {
        fscanf(file, "%d%d", &jogador1[i].lado1, &jogador1[i].lado2);
        fscanf(file, "%d%d", &jogador2[i].lado1, &jogador2[i].lado2);
    }

    for (i = 0; i < 14; i++) {
        fscanf(file, "%d%d", &extra[i].lado1, &extra[i].lado2);
    }

    for (i = 0; i < 28; i++) {
        fscanf(file, "%d%d", &jogo[i].lado1, &jogo[i].lado2);
    }

    fclose(file);
}                  // com essas 2 funcoes, � possivel salvar o jogo e carrega-lo depois de fechado

void interface2() {
	int ajuda;
	mostrarjogo();
	printf("1 - Jogar uma peca\n");
	if (extra[13].lado1 == -1 && extra[13].lado2 == -1) {
		printf("2 - Passar a vez\n");
		ajuda = 0;
	}
	else {
		printf("2 - Puxar\n");
		ajuda = 1;
	}
	printf("3 - Salvar e sair\n");
	int opcao;
	scanf("%d", &opcao);
	if (opcao == 1) {
		system("cls");
		interface();
		mostrarjogo();
		printf("Qual peca voce vai jogar?\n");
		scanf("%d %d", &peca1, &peca2);
		jogar1(peca1, peca2);
	}
	else if (opcao == 2) {
		if (ajuda == 1) {
			puxando();
			interface();
			interface2();
		}
		else if (ajuda == 0) {
			jogada--;
			global++;
		}
	}
	else if (opcao == 3) {
		salvarestado();
		jogador++;
		system("cls");
		system("taskkill /F /IM dominozada.exe");
	}
	else {
		system("cls");
		interface();
		interface2();
	}
}               //     interface de acao

int domino() {
    while (jogada < 28) {
    	system("cls");
    	interface();
    	interface2();
    	win();
    	if (win() == 1 || win () == 2 || global > 1) {
    		break;
		}
    	jogada++;
    	jogador++;
	}
	if (global != 0) {
		system("cls");
		printf("\033[5;32mEmpate!!!\033[0m\n");
	}
	if (win() == 1) {
	    system("cls");
        printf("\033[5;32mO jogador 1 venceu!!!\033[0m\n");
	}
	if (win() == 2) {
	    system("cls");
        printf("\033[5;32mO jogador 2 venceu!!!\033[0m\n");
	}
	return 0;
}                       // logica do jogo 

int main () {
	printf("DOMINO\n1 - Novo jogo\n2 - Carregar jogo\n");
	int opc;
	scanf("%d", &opc);
	getchar();
	system("cls");
	if (opc == 1) {
	srand(time(NULL));
    gerarpecas();
    embaralharpecas();
    inicializacao0();
    mao();
    ext();
    for (i = 5; i >= 0; i--) {
    	printf("O jogo vai comecar em:\n%d\n", i);
    	sleep(1);
    	system("cls");
	}
    inicio();
    printf("Aperte enter para comecar o jogo\n");
    char enter;
    scanf("%c", &enter);
    system("cls");
    interface();
    printf("Faca a primeira jogada\n");
    scanf("%d %d", &peca1, &peca2);
    jogar(peca1, peca2);
    jogada++;
    jogador++;
	domino();
	}
	else if (opc == 2) {
		carregarestado();
		domino();
	}
}

