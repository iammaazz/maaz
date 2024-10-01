#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

// Function to perform binary search
int binarySearch(char names[][MAX_NAME_LENGTH], int left, int right, const char *target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare the target with the middle element
        int result = strcmp(names[mid], target);

        // Check if the target is present at mid
        if (result == 0) {
            return mid; // Target found
        }

        // If target is greater, ignore the left half
        if (result < 0) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int n, i;
    char target[MAX_NAME_LENGTH];

    // Input number of names
    printf("Enter number of names (max %d): ", MAX_NAMES);
    scanf("%d", &n);
    getchar(); // To consume the newline character

    // Input names
    printf("Enter %d names (sorted in ascending order):\n", n);
    for (i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove newline character
    }

    // Input the name to search for
    printf("Enter the name to search for: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0'; // Remove newline character

    // Perform binary search
    int result = binarySearch(names, 0, n - 1, target);

    // Output result
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found in the list.\n", target);
    }

    return 0;
}
