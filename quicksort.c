//unnati dharpure CS23147
#include<stdio.h>
void printarray(int arr[],int n);
void quicksort(int arr[],int lb,int ub);
int location(int arr[],int lb,int ub);

main()
{
   int n,i,lb,ub;
   printf("Enter number of element in array:");
   scanf("%d",&n);
   int a[n];
   printf("Enter elements:\n");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   printf("\nArray before sorting:\n");
   printarray(a,n);
   lb=0;
   ub=n-1;
   quicksort(a,lb,ub);

   printf("Array after sorting:\n");
   printarray(a,n);
}
void printarray(int arr[],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d  ",arr[i]);
   }
   printf("\n");
}
void quicksort(int arr[],int lb,int ub)
{
   int loc;
   if(lb<ub)
   {
      loc=location(arr,lb,ub);
      quicksort(arr,lb,loc-1);
      quicksort(arr,loc+1,ub);
   }
}
int location(int arr[],int lb,int ub)
{
   int pivot=arr[lb];
   int start=lb;
   int end=ub;
   int temp;
   while(start<end)
   {
      while(arr[start]<=pivot)
      start++;
      while(arr[end]>pivot)
      end--;
      if(start<end)
	  {
          temp=arr[start];
          arr[start]=arr[end];
          arr[end]=temp;
      }
    }
    temp=arr[end];
    arr[end]=arr[lb];
    arr[lb]=temp;
    return end;
}
