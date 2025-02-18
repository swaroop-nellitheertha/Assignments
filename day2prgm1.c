#include <stdio.h>

long long factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1; 
    } else if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    if (scanf("%d", &num)!= 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; 
    }

    long long result = factorial(num);

    if (result == -1) {
        return 1; 
    } else {
        printf("Factorial of %d is %lld\n", num, result);
        return 0;
    }
}
