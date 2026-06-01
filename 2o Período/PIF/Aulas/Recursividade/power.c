#include <stdio.h>

int power(int base, int exp){
    if (exp == 0){
        return 1;
    } else {
        return base * power(base, exp - 1);
    }
}

int main(){
    int base = 2;
    int exp = 3;
    printf("%d", power(base, exp));

    return 0;
}