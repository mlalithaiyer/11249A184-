#include <stdio.h>
int main() {
    int n, key, i, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];  
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }

    
    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
