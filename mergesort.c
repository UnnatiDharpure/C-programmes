// Unnati Dharpure   CS23147
#include <stdio.h>
void printarray(int A[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    
    i = 0; 
    j = 0; 
    k = l; 
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[30], i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]); 
    }

    printf("Given array: ");
    printarray(arr, n);

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printarray(arr, n);

    return 0;
}
