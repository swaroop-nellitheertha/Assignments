#include <stdio.h>
#include <string.h>

struct Medicine {
    int id;
    char name[50];
    char expiry[15];
    float price;
};

void sortMedicines(struct Medicine meds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(meds[i].expiry, meds[j].expiry) > 0) {
                struct Medicine temp = meds[i];
                meds[i] = meds[j];
                meds[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of medicines: ");
    scanf("%d", &n);
    struct Medicine meds[n];
    FILE *file = fopen("medicine_inventory.txt", "w");

    for (int i = 0; i < n; i++) {
        printf("Enter Medicine %d (ID Name Expiry YYYY-MM-DD Price): ", i + 1);
        scanf("%d %s %s %f", &meds[i].id, meds[i].name, meds[i].expiry, &meds[i].price);
    }
    
    sortMedicines(meds, n);
    
    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, meds[i].name, meds[i].expiry);
        fprintf(file, "%d, %s, %s, ₹%.2f\n", meds[i].id, meds[i].name, meds[i].expiry, meds[i].price);
    }
    
    fclose(file);
    printf("\nRecords saved in \"medicine_inventory.txt\"\n");
    return 0;
}
