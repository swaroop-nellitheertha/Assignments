#include <stdio.h>
#include <string.h>

#define MAX_URL 100
#define MAX_HISTORY 50

struct BrowserHistory {
    char urls[MAX_HISTORY][MAX_URL];
    int current;
    int total;
};

void initHistory(struct BrowserHistory *history) {
    history->current = -1;
    history->total = 0;
}

void visitPage(struct BrowserHistory *history, char *url) {
    history->current++;
    history->total = history->current + 1;
    strcpy(history->urls[history->current], url);
}

void goBack(struct BrowserHistory *history) {
    if (history->current > 0) {
        history->current--;
    }
}

void goForward(struct BrowserHistory *history) {
    if (history->current < history->total - 1) {
        history->current++;
    }
}

void displayCurrent(struct BrowserHistory *history) {
    printf("Current Page: %s\n", history->urls[history->current]);
}

int main() {
    struct BrowserHistory history;
    initHistory(&history);
    char url[MAX_URL];
    int choice;

    while (1) {
        printf("\n1. Visit Page\n2. Go Back\n3. Go Forward\n4. Show Current\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, MAX_URL, stdin);
                url[strcspn(url, "\n")] = 0;
                visitPage(&history, url);
                break;
            case 2:
                goBack(&history);
                displayCurrent(&history);
                break;
            case 3:
                goForward(&history);
                displayCurrent(&history);
                break;
            case 4:
                displayCurrent(&history);
                break;
            case 5:
                return 0;
        }
    }
}
