#include <stdio.h>

int main()
{
    int target;
    printf("Enter the array elements:\n");
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target:\n");
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == target)
      {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Target found in array\n");
    } else {
        printf("Target not found in array\n");
    }

    return 0;
}

