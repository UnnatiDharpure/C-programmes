#include<stdio.h>
main(){
	int i,j,n,flag=-1;
	char arr[20];
	printf("enter value of:");
	scanf("%d",&n);
	printf("enter string:");
	scanf("%s",arr);
	i=0,j=n-1;
	while(i<j){
		if(arr[i]==arr[j]){
			flag=0;
		}
		else{
			flag=-1;
		}
	}
	if(flag==0){
		printf("true");
	}
	else{
		printf("flase");
	}

}

