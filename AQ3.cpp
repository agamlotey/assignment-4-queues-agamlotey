#include <stdio.h>

int main() {
    int n;
    printf("Enter even number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Output: ");
    for (int i = 0; i < n/2; i++) {
        printf("%d %d ", arr[i], arr[i + n/2]);
    }
    printf("\n");
    return 0;
}
