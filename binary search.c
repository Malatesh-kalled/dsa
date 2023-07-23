#include <stdio.h>

// Recursive function for binary search
int binarySearch(int arr[], int left, int right, int target) {
    // Base case
    if (left > right) {
        return -1;
    }

    // Calculate the middle index
    int mid = left + (right - left) / 2;

    // Check if the target element is present at the middle index
    if (arr[mid] == target) {
        return mid;
    }
    // If target is less than the middle element, search in the left half of the array
    else if (target < arr[mid]) {
        return binarySearch(arr, left, mid - 1, target);
    }
    // If target is greater than the middle element, search in the right half of the array
    else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}
