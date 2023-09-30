#include <stdio.h>
#define M 6

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
        suma += sumaDeFila(matriz, i, M-i-1, i);
        suma += sumaDeFila(matriz, i, M-i-1, M-i-1);
        suma += sumaDeColumna(matriz, i+1, M-i-2, i);
        suma += sumaDeColumna(matriz, i+1, M-i-2, M-i-1);
        sumas[i] = suma;
    }
    
}

int main(){
    int matriz[][M] =   {{1,1,1,1,1,1},
                        {1,2,2,2,2,1},
                        {1,2,3,3,2,1},
                        {1,2,3,3,2,1},
                        {1,2,2,2,2,1},
                        {1,1,1,1,1,1}};
    int sumas[M/2];
    bordes(matriz, sumas);
    for (int i = 0; i < M/2; i++)
    {
        printf("%d", sumas[i]);
    }
    
    return 0;
}