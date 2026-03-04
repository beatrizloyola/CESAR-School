#include <stdio.h>
#include <stdlib.h>

int main(){
    int quadrada[3][3] = {0};
    
    /*
    Transforma em matriz identidade (diagonal principal vira 1)
    */

    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (i == j){
                quadrada[i][j] = 1;
            }
            
            printf("\n[%d][%d] = %d", i, j, quadrada[i][j]);
        }
    }

    /*
    Transforma a diagonal secundária em 2
    */
   
    int n = 3 - 1;
    int i, j;

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (i + j == n){
                quadrada[i][j] = 2;
            }

            printf("\n[%d][%d] = %d", i, j, quadrada[i][j]);
        }
    }

    return 0;
};