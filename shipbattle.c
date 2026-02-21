#include <stdio.h>
#include <string.h>

int main(){

//Criar o mapa 10x10. A "água" do jogo, com matrizes

//Criar dois navios representados pelo número 3 e inserir no
//mapa com comprimento 3, um vertical e o outro horizontal

//Criar dois navios diagonais

int map[10][10] = {0};
int linha;
int coluna;

for (int i=0; i<3;i++){
//Acrescenta NAVIOS
    //VERTICAL
    linha=0; coluna=0;
    map[linha+i][coluna]=3;
    //HORIZONTAL
    linha=4; coluna=7;
    map[linha][coluna+i]=3;

    //DIAGONAIS
    linha=2; coluna=2;
    map[linha+i][coluna+i]=3;

    linha=7; coluna=5;
    map[linha+i][coluna+i]=3;
}

//Esta é a 'ÁGUA'

for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        printf("%d ", map[i][j]);
    }
    printf("\n");
}

return 0;
}