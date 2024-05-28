#include<stdio.h>
char mat[4][4]={{' ','1','2','3'},{'1','-','-','-'},{'2','-','-','-'},{'3','-','-','-'}};
int i,j;
void tabela(){
    for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        printf("%c ",mat[i][j]);
    }
    printf("\n");
}
}
int a=0;
void preencher(int linha,int coluna){
       if(mat[linha][coluna]=='-' && linha>0 && linha<4 && coluna>0 && coluna<4){
            if(a%2==0){
                mat[linha][coluna]='X';
            }
            else{
                mat[linha][coluna]='O';
            }
               tabela();
               a++;
        }
}
 int resultado(){
     int vit=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(mat[1][j]!='-' && mat[1][j]==mat[2][j] && mat[2][j]==mat[3][j]|| 
                mat[i][1]!='-' && mat[i][1]==mat[i][2] && mat[i][2]==mat[i][3]
                || mat[1][1]!='-' && mat[1][1]==mat[2][2] && mat[2][2]==mat[3][3] || 
                mat[1][3]!='-' && mat[1][3]==mat[2][2] && mat[2][2]==mat[3][1]){
                    vit=1;
                }
            }
        }
        if(a%2==0 && vit==1){
       printf("jogador O venceu\n");
       return 1;
        }
        else if(a%2==1 && vit==1){
        printf("jogador X venceu\n");
        return 1;
        }
        else if(a>8){
            printf("empate\n");
            return 1;
        }
        return 0;
 }
void vez(){
       if(a%2==0){
            printf("vez do jogador X\n");
        }
        else{
            printf("vez do jogador O\n");
        }
}
int main(){
    printf("jogo da velha:\n");
    tabela();
    printf("insira o numero da linha e da coluna\n");
    printf("\n");
    int linha,coluna;
   while(a<9){
      vez();
      scanf("%d %d",&linha,&coluna);
      preencher(linha,coluna);
        if(resultado()==1){
            break;
        }
   }
    return 0;
}