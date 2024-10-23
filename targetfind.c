//unnati dharpure    CS23147
#include <stdio.h>
int main() {
    int arr[30], i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    int element = findElement(arr,n);
    if (element != -1) {
        printf("Element found at position: %d\n", element+1);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
int findElement(int arr[],int n){
	int target,i;
	printf("Enter element you want to find: ");
    scanf("%d", &target);
	for(i = 0; i < n; i++) {
        if(target == arr[i]){
        	return i;
		}
    }
    return -1;
}
