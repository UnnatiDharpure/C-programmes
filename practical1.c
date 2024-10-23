//Name: Unnati Dharpure   USN: CS23147
#include<stdio.h>
main()
{
    int n,arr[10],i,j,flag,temp;
    printf("enter size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }  

    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<(n-1-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==0)
        {
            printf("array already sorted");
            break;
        }
    }
    printf("sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}

