#include <stdio.h>

float calculate_discount(float bill) {
    if (bill >= 500 && bill <= 1000) return bill * 0.9;
    if (bill > 1000) return bill * 0.8;
    return bill;
}

int main() {
    float bill;
    printf("Enter bill amount: ₹");
    scanf("%f", &bill);
    printf("Final amount: ₹%.2f\n", calculate_discount(bill));
    return 0;
}
