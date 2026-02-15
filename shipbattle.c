#include <stdio.h>
#include <string.h>

int main(){

//Criar o mapa 10x10. A "água" do jogo, com matrizes

//Criar dois navios representados pelo número 3 e inserir no 
//mapa com comprimento 3, um vertical e o outro horizontal

int map[10][10];

//Esta é a 'ÁGUA'
for (int i=0; i<10;i++){
    for(int j=0; j<10; j++){
        map[i][j] = 0;
    }
}

//Acrescenta NAVIOS

//Vertical
map[0][9] = 3;
map[1][9] = 3;
map[2][9] = 3;

//Horizontal
map[6][3] = 3;
map[6][4] = 3;
map[6][5] = 3;

for (int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        printf("%d", map[i][j]);
    }
    printf("\n");
}

return 0;
}