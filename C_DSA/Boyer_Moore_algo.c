#include <stdio.h>
#include <string.h>
#include <time.h>

#define ALPHABET 256

int skips[ALPHABET];

// SetSkips(pattern)
void SetSkips(char pattern[], int m) {
    for(int i = 0; i < ALPHABET; i++) {
        skips[i] = m; // default shift = pattern length
    }
    for(int i = 0; i < m - 1; i++) {
        skips[(unsigned char)pattern[i]] = m - i - 1; // last occurrence rule
    }
}

// Boyer-Moore Algorithm
int BoyerMoore(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int occurance = 0;

    SetSkips(pattern, m);

    int i = m - 1;  // index in text

    while(i < n) {
        int j = m - 1; // index in pattern
        int k = i;

        // Compare backwards
        while(j >= 0 && text[k] == pattern[j]) {
            k--;
            j--;
        }

        if(j < 0) {
            occurance++;       // match found
            i = i + m;         // shift entire pattern
        } else {
            int shift = skips[(unsigned char)text[i]];
            if(shift < 1) shift = 1;
            i += shift;        // shift according to skip table
        }
    }

    return occurance;
}

int main() {
    char text[1000], pattern[1000];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    clock_t start, end;
    double cpu_time;

    start = clock();
    int result = BoyerMoore(text, pattern);
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nNumber of occurrences: %d\n", result);
    printf("Execution time: %f seconds\n", cpu_time);

    printf("\nTime Complexity (Theoretical):\n");
    printf("Best Case: O(n/m)\n");
    printf("Worst Case: O(n*m)\n");
    printf("Space Complexity: O(ALPHABET) for skip table\n");

    return 0;
}