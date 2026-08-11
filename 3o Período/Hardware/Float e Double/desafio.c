#include <stdio.h>

int main(){
    float f = 0;
    double d = 0;

    for(int i = 0; i < 1000000; i++){
        f = f + 0.1;
    }
    printf("Float: %f\n", f);
    printf("Diferença: %f\n", 100000 - f);

    printf("-----------\n");
    
    for(int i = 0; i < 1000000; i++){
        d = d + 0.1;
    }
    printf("Double: %f\n", d);
    printf("Diferença: %f\n", 100000 - d);

    return 0;
}