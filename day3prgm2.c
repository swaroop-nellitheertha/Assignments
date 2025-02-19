#include <stdio.h>

int main() {
    char dna[100];
    char pattern[50];
    int count = 0;
    int dnaLen = 0;
    int patternLen = 0;

    printf("Enter DNA Sequence: ");
    scanf("%s", dna);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    while (dna[dnaLen] != '\0') {
        dnaLen++;
    }

    while (pattern[patternLen] != '\0') {
        patternLen++;
    }

    if (patternLen > dnaLen) {
        printf("Pattern length cannot exceed DNA sequence length.\n");
        return 1;
    }

    for (int i = 0; i <= dnaLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (dna[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            count++;
        }
    }

    printf("Pattern found %d time(s) in the DNA sequence.\n", count);

    return 0;
}
