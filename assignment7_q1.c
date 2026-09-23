#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Array elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    average = sum / n;

    printf("\nSum = %.2f", sum);
    printf("\nAverage = %.2f", average);

    return 0;
}