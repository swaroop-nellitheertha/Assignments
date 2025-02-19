#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct {
    char name[50];
    int age;
    char destination[50];
} Passenger;

void sortPassengers(Passenger passengers[], int n) {
    for (int i = 1; i < n; i++) {
        Passenger key = passengers[i];
        int j = i - 1;
        while (j >= 0 && strcmp(passengers[j].destination, key.destination) > 0) {
            passengers[j + 1] = passengers[j];
            j--;
        }
        passengers[j + 1] = key;
    }
}

void searchPassengers(Passenger passengers[], int n, char searchDest[]) {
    int found = 0;
    printf("\nPassengers traveling to %s:\n", searchDest);
    for (int i = 0; i < n; i++) {
        if (strcmp(passengers[i].destination, searchDest) == 0) {
            printf(" - %s (Age: %d)\n", passengers[i].name, passengers[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found for this destination.\n");
    }
}

int main() {
    Passenger passengers[MAX_PASSENGERS];
    int n;

    printf("Enter number of passengers: ");
    scanf("%d", &n);
    getchar();

    if (n <= 0 || n > MAX_PASSENGERS) {
        printf("Invalid number of passengers.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details (Name Age Destination): ");
        scanf("%s %d %s", passengers[i].name, &passengers[i].age, passengers[i].destination);
    }

    sortPassengers(passengers, n);

    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf(" %s (Age: %d) -> %s\n", passengers[i].name, passengers[i].age, passengers[i].destination);
    }

    char searchDest[50];
    printf("\n Enter destination to search: ");
    scanf("%s", searchDest);
    searchPassengers(passengers, n, searchDest);

    return 0;
}
