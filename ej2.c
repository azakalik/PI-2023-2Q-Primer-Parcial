#include <stdio.h>
#define M 6
#define CONJUGATE(i) (M-i-1) //given a row or column i, it calculates the index of the conjugate column (0-6), (1-5), (2-4), etc

int sumaDeFila(int matriz[M][M], int startCol, int endCol, int fila){
    int suma = 0;
    while(startCol <= endCol){
        suma += matriz[fila][startCol++];
    }
    return suma;
}

int sumaDeColumna(int matriz[M][M], int startFil, int endFil, int columna){
    int suma = 0;
    while(startFil <= endFil){
        suma += matriz[startFil++][columna];
    }
    return suma;
}

void bordes(int matriz[M][M], int sumas[M/2]){
    for (int i = 0; i < M/2; i++){
        int suma = 0;
        suma += sumaDeFila(matriz, i, CONJUGATE(i), i);
        suma += sumaDeFila(matriz, i, CONJUGATE(i), CONJUGATE(i));
        suma += sumaDeColumna(matriz, i+1, CONJUGATE(i)-1, i);
        suma += sumaDeColumna(matriz, i+1, CONJUGATE(i)-1, CONJUGATE(i));
        sumas[i] = suma;
    }
    
}

int main(){
    int matriz[][M] =   {{1,1,1,1,1,1},
                        {1,2,2,2,2,1},
                        {1,2,3,3,2,1},
                        {1,2,3,3,2,1},
                        {1,2,2,2,2,1},
                        {1,1,1,1,1,1}}; //expected output is 20, 24, 12
    int sumas[M/2];
    bordes(matriz, sumas);
    printf("The sums are:");
    for (int i = 0; i < M/2; i++)
    {
        printf(" %d,", sumas[i]);
    }
    printf("\b.\n");
    
    return 0;
}