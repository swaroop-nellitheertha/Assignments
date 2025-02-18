#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char cardNumber[17], upiID[50];
    int bankChoice;

    printf("Select Payment Method:\n");
    printf("1. Credit/Debit Card\n2. UPI\n3. Net Banking\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter your 16-digit Card Number: ");
            scanf("%s", cardNumber);
            if (strlen(cardNumber) == 16)
                printf("Payment Successful!\n");
            else
                printf("Transaction Failed. Please enter a valid 16-digit card number.\n");
            break;

        case 2:
            printf("Enter your UPI ID: ");
            scanf("%s", upiID);
            if (strchr(upiID, '@'))
                printf("Payment Successful!\n");
            else
                printf("Transaction Failed. Invalid UPI ID.\n");
            break;

        case 3:
            printf("Select Bank:\n1. SBI\n2. HDFC\n3. ICICI\nEnter choice: ");
            scanf("%d", &bankChoice);
            if (bankChoice >= 1 && bankChoice <= 3)
                printf("Payment Successful!\n");
            else
                printf("Transaction Failed. Invalid bank selection.\n");
            break;

        default:
            printf("Invalid payment method. Please try again.\n");
    }

    return 0;
}
