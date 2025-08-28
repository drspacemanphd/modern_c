#include <stdio.h>

int main() {
    int i = 2;

    switch(i) {
        case 2:
            printf("2");
            i -= 1;
        case 1:
            printf("1");
            i -= 1;
        case 0:
            printf("0");
            i -= 1;
            break;
        default:
            printf("default");
    }
}