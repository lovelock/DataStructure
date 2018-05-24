#include <stdio.h>

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("%d: %c => %c\n", n, A, C);
    } else {
        hanoi(n-1, A, C, B);
        printf("%d: %c => %c\n", n, A, C);
        hanoi(n-1,B, A, C);
    }
}


int main() {
    char A = 'A';
    char B = 'B';
    char C = 'C';

    int n;

    printf("please input dishes to move\n");
    scanf("%d", &n);

    hanoi(n, A, B, C);
}
