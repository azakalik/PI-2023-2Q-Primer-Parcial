#include <stdio.h>
#define COLS 6

int filaEsCapicua(char fila[COLS]){
    int it1 = 0, it2 = COLS - 1;
    int esCapicua = 1;
    while(it1 < it2){
        if (fila[it1++] != fila[it2--])
            esCapicua = 0;
    }
    return esCapicua;
}

//se podria haber usado memcpy tambien
int copiarFila(char filaACopiar[COLS], char filaDondeCopiar[COLS]){
    for (int i = 0; i < COLS; i++){
        filaDondeCopiar[i] = filaACopiar[i];
    }
    return 0;
}

int elimina(char matriz[][COLS], int filas){
    int cantFilasNoCapicuas = 0;
    for(int fila = 0; fila < filas; fila++){
        if (!filaEsCapicua(matriz[fila])){
            copiarFila(matriz[fila], matriz[cantFilasNoCapicuas++]);
        }
    }

    return cantFilasNoCapicuas;
}

void printMatrix(char matrix[][COLS], int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int filas = 6;
    char matrix[/*filas*/][COLS] = {
        {'L', '#', 'B', 'B', '#', 'L'},
        {'3', '1', 'r', 'R', '1', '3'},
        {'3', '2', 'S', 'S', '2', '3'},
        {'R', 'L', 'A', 'H', 'N', 'N'},
        {'W', 'A', 'O', 'Y', 'U', 'T'},
        {'Q', 'S', 'G', 'S', 'M', 'A'}
    };
    int cant = elimina(matrix, filas);
    printf("La matriz tiene %d filas y es:\n", cant);
    printMatrix(matrix, cant, COLS);
    return 0;
}