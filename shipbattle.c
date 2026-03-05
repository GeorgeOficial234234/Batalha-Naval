#include <stdio.h>
#include <string.h>

#define LINHA 10
#define COLUNA 10

int cone(int lineship, int colship, int size, int map[LINHA][COLUNA]){
    for(int i=0; i<size; i++){ //Dertemina o tamanho vertical do cone;
        map[i+lineship][i+colship] = 1; //A posição da ponta do cone por iteração de linha e coluna;
        for(int j=0; j<i; j++){
            map[i+lineship][j+colship] = 1; //Simplesmente preenche o lado direito do cone;
        }
        for(int j=0; j<i; j++){
            map[i+lineship][-j+(colship)-1] = 1; //"-j" Negativa as iterações fazendo as com que preencham o lado esquerdo do cone; 
                                             //"-1" Separa uma coluna para não "entra" no outro loop interno;
        }
    }
}
 
int cruz(int lineship, int colship, int size, int cz, int map[LINHA][COLUNA]){
    for(int i=0; i<size+cz; i++){
        map[lineship][i+colship] = 1; //itera horizontalmente a partir do valor de colship;
        for(int j=0; j<=i; j++){
            map[i+(lineship)-cz][colship+cz] = 1; //"i+(lineship)" itera verticalmente; "colship+cz" posiciona no centro da horizontal;
        }
    }
}

int octaedro(int lineship, int colship, int size, int map[LINHA][COLUNA]){
    for(int i=0; i<size; i++){
    map[i+lineship][i+colship] = 1;
    for(int j=0; j<i; j++){
        map[i+lineship][j+colship] = 1;
    }
    for(int j=0; j<i; j++){
        map[i+lineship][-j+(colship)-1] = 1; //Até aqui é literalmente o mesmo código do cone;
    }
    for(int j=0; j<i; j++){
        map[(-i+5)+lineship][-j+colship] = 1; //Essa linha é o inverso da linha de cima; Completa o lado esquerdo só que invertido;
        for(int p=0; p<j; p++){
            map[i+lineship+1][j+colship] = 1; //Completa o inverso do loop de cima;
        }
    }
}
}

int main(){

//Criar o mapa 10x10. A "água" do jogo, com matrizes

//Criar dois navios representados pelo número 3 e inserir no
//mapa com comprimento 3, um vertical e o outro horizontal

//Criar dois navios diagonais

/*
Criar habilidades com área de efeito: Cone, Cruz e Octaedro
Inicialmente vou fazê-las manualmente para entender a lógica dos formatos
Após, irei fazer com que surjam a partir dos navios
*/

int map[LINHA][COLUNA] = {0};
int size = LINHA-7;

int shiph = 0, shipv = 0, shipde = 0, shipdd = 0;
int lineship = 0;
int colship = 0;


//Área de Efeito Cone
lineship = 1;
colship = 2;
cone(lineship, colship, size, map);

//Área de Efeito Cruz
lineship = 2;
colship = 5;
int cz = 2;
cruz(lineship, colship, size, cz, map);

//Área de Efeito Octaedro
lineship = 5;
colship = 4;
octaedro(lineship, colship, size, map);


//Esta é a 'ÁGUA'
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        printf("%d ", map[i][j]);
    }
    printf("\n");
}

return 0;
}