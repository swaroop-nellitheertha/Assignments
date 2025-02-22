#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

struct Warehouse {
    char items[MAX_ITEMS][MAX_NAME];
    int top;
};

void initWarehouse(struct Warehouse *warehouse) {
    warehouse->top = -1;
}

int isFull(struct Warehouse *warehouse) {
    return warehouse->top >= MAX_ITEMS - 1;
}

int isEmpty(struct Warehouse *warehouse) {
    return warehouse->top < 0;
}

void addItem(struct Warehouse *warehouse, char *item) {
    if (!isFull(warehouse)) {
        warehouse->top++;
        strcpy(warehouse->items[warehouse->top], item);
        printf("Stock Added: %s\n", item);
    } else {
        printf("Warehouse is full!\n");
    }
}

void dispatchItem(struct Warehouse *warehouse) {
    if (!isEmpty(warehouse)) {
        printf("Dispatching Item: %s\n", warehouse->items[warehouse->top]);
        warehouse->top--;
    } else {
        printf("Warehouse is empty!\n");
    }
}

void displayStock(struct Warehouse *warehouse) {
    printf("Remaining Stock: ");
    for (int i = 0; i <= warehouse->top; i++) {
        printf("%s", warehouse->items[i]);
        if (i < warehouse->top) printf(", ");
    }
    printf("\n");
}

int main() {
    struct Warehouse warehouse;
    initWarehouse(&warehouse);
    char item[MAX_NAME];
    int choice;

    while (1) {
        printf("\n1. Add Item\n2. Dispatch Item\n3. Display Stock\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(item, MAX_NAME, stdin);
                item[strcspn(item, "\n")] = 0;
                addItem(&warehouse, item);
                break;
            case 2:
                dispatchItem(&warehouse);
                break;
            case 3:
                displayStock(&warehouse);
                break;
            case 4:
                return 0;
        }
    }
}
