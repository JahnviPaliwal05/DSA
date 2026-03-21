#include <stdio.h>
#include <string.h>
#include <time.h>

int comparisonCount = 0;

int naivePatternMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int occurance = 0;
    int i, j;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            comparisonCount++;   // count comparisons

            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            occurance++;
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

    // Start timing
    start = clock();

    int result = naivePatternMatch(text, pattern);

    // End timing
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nNumber of occurrences: %d\n", result);

    // Real-time output
    printf("Execution time: %f seconds\n", cpu_time);

    // Comparison count
    printf("Total comparisons: %d\n", comparisonCount);

    printf("n = %d, m = %d\n", n, m);
    printf("n * m = %d\n", n * m);

    printf("\nTime Complexity Verification:\n");
    printf("Comparisons grow proportional to (n * m)\n");
    printf("Hence, Time Complexity = O(n * m)\n");

    return 0;
}