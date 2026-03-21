#include <stdio.h>
#include <string.h>
#include <time.h>

// CreatePMT(pattern)
void createPMT(char pattern[], int m, int pmt[]) {
    int pos = 0;
    pmt[0] = 0;

    for (int j = 1; j < m; j++) {
        if (pattern[j] == pattern[pos]) {
            pmt[j] = pmt[j - 1] + 1;
            pos++;
        } else {
            pmt[j] = 0;
            pos = 0;
        }
    }
}

// restart(i, j, pmt)
void restart(int *i, int *j, int pmt[]) {
    if (*j == 0 || pmt[*j - 1] == 0) {
        (*i)++;
    } else {
        *j = pmt[*j - 1];
    }
}

// KMP(text, pattern)
int KMP(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int pmt[100];
    createPMT(pattern, m, pmt);

    int occurance = 0;
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;

            if (j == m) {
                occurance++;
                restart(&i, &j, pmt);
            }
        } else {
            restart(&i, &j, pmt);
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

    clock_t start, end;
    double cpu_time;

    // Start time
    start = clock();

    int result = KMP(text, pattern);

    // End time
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nNumber of occurrences: %d\n", result);

    printf("Execution time: %f seconds\n", cpu_time);

    printf("\nTime Complexity (Theoretical): O(n + m)\n");

    return 0;
}