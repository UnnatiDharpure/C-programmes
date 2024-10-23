//Unnati Dharpure  CS23147
#include<stdio.h>
struct employee{
	char name[30];
	int ID;
};
main(){
    int right,left=0,mid,i,n,ele,pos=-1;
    printf("enter no. of employees:");
    scanf("%d",&n);
    struct employee emp[n];
    right=n-1;
    printf("enter employee data:\n");
    for(i=0;i<n;i++){
    	printf("enter name:\n");
        scanf("%s",emp[i].name);
        printf("enter ID:\n");
        scanf("%d",&emp[i].ID);
    }
    printf("enter ID of employee you want to search:");
    scanf("%d",&ele);
    while(left<=right){
        mid=left+right/2;
        if(ele==emp[mid].ID){
            pos=mid;
            break;
        }
        if(ele>emp[mid].ID){
            left=mid+1;
        }
        if(ele<emp[mid].ID){
            right=mid-1;
        }
    }
    if(pos == -1){
        printf("employee data not present....\n ");
    }
    else{
        printf("employee data is present in database\n");
    }
}


