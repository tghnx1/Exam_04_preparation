#include <stdio.h>
#include <stdlib.h>

// Parse the arguments to retrieve the target sum and the integer set
int *ft_parse(char **argv, int num, int *target) {
    int *arr = malloc(sizeof(int) * num);
    if (!arr) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }
    *target = atoi(argv[1]);
    for (int i = 0; i < num; i++) {
        arr[i] = atoi(argv[i + 2]);
    }
    return arr;
}

// Recursive backtracking function to generate subsets that sum to `target`
void ft_backtrack(int *arr, int num, int idx, int target, int current_sum, int *subset, int subset_size) {
    // If the current subset's sum equals the target, print it
    if (current_sum == target) {
        for (int i = 0; i < subset_size; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // If we've gone through all elements or the current sum exceeds the target, stop
    if (idx >= num || current_sum > target) {
        return;
    }

    // Include the current element in the subset
    subset[subset_size] = arr[idx];
    ft_backtrack(arr, num, idx + 1, target, current_sum + arr[idx], subset, subset_size + 1);

    // Exclude the current element from the subset and move to the next element
    ft_backtrack(arr, num, idx + 1, target, current_sum, subset, subset_size);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stdout, "Usage: %s target num1 num2 ...\n", argv[0]);
        return 0;
    }

    int num = argc - 2;
    int target;
    int *arr = ft_parse(argv, num, &target);
    if (!arr) return 1;

    int *subset = malloc(sizeof(int) * num); // To store current subset
    if (!subset) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(arr);
        return 1;
    }

    // Start backtracking from the first index
    ft_backtrack(arr, num, 0, target, 0, subset, 0);

    // Free allocated memory
    free(arr);
    free(subset);
    return 0;
}
