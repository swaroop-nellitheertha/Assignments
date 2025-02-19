#include <stdio.h>

int main() {
    int scores[100];
    int n;
    int highest, lowest;
    float sum = 0;

    printf("Enter number of matches: ");
    scanf("%d", &n);

    printf("Enter scores of %d matches: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    highest = scores[0];
    lowest = scores[0];

    for (int i = 0; i < n; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
        sum += scores[i];
    }

    float average = sum / n;

    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.1f\n", average);

    return 0;
}
