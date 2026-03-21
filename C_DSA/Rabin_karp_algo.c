#include <stdio.h>
#include <string.h>
#include <time.h>

#define d 256        // Number of characters in input alphabet
#define q 101        // A prime number for modulo operation

int rabinKarp(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int p = 0;       // hash value for pattern
    int t = 0;       // hash value for text window
    int h = 1;
    int occurance = 0;
    int comparisons = 0;

    // The value of h = pow(d, m-1) % q
    for(i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and first window
    for(i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for(i = 0; i <= n - m; i++) {
        comparisons++;  // at least one comparison for hash

        // Check the hash values
        if(p == t) {
            // Hash matched, check character by character
            for(j = 0; j < m; j++) {
                comparisons++;
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == m)
                occurance++;  // pattern found
        }

        // Calculate hash for next window
        if(i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Make sure t is positive
            if(t < 0)
                t += q;
        }
    }

    printf("Total character comparisons: %d\n", comparisons);
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
    int result = rabinKarp(text, pattern);
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nNumber of occurrences: %d\n", result);
    printf("Execution time: %f seconds\n", cpu_time);

    printf("\nTime Complexity (Theoretical):\n");
    printf("Average case: O(n + m)\n");
    printf("Worst case: O(n*m) (when hash collisions occur)\n");

    return 0;
}