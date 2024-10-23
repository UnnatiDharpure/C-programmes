//unnati dharpure    CS23147
#include <stdio.h>
int findNonRepeating(int arr[], int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {  
                break;  
            }
        }
        if (j == n) {  
           printf("%d ", arr[i]); 
        }
    }
    
}
int main() {
    int arr[30], i, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]); 
    }
    int nonRepeating = findNonRepeating(arr,n);
    return 0;
}
