#include <stdio.h>
#include <string.h>
union Rent {
    int daily;
    int total;
};
struct Car {
    int id;
    char model[50];
    union Rent rent;
};
int main() {
    int n;
    printf("Enter number of cars: ");
    scanf("%d", &n);
    struct Car cars[n];
    FILE *file = fopen("car_rentals.txt", "w");
    for (int i = 0; i < n; i++) {
        printf("Enter Car %d (ID Model Rent/Day): ", i + 1);
        scanf("%d %s %d", &cars[i].id, cars[i].model, &cars[i].rent.daily);
    }
    printf("\nCars Available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %d/day\n", i + 1, cars[i].model, cars[i].rent.daily);
        fprintf(file, "%d, %s, %d/day\n", cars[i].id, cars[i].model, cars[i].rent.daily);
    }
    fclose(file);
    printf("\nData saved in \"car_rentals.txt\"\n");
    return 0;
}
