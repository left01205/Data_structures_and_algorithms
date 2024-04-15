// Online C compiler to run C program online
#include <stdio.h>
int select(int arr[],int n)

{
    int i=0,j=0;
    while (i< n-1)
    {
        int min =i;
        while(j<n)
        {
            if (arr[j]<arr[min])
            {
                min =j;
            }
            j++;
        }
        int temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        i++;
    }
    printf("Here is the array after selection sorting : ");
    for (int k=0;k<n;k++)
    printf("%d",arr[k]);
    
}
int main() {
    // Intitalising array 
    int n=5;
    int arr[]={5,2,1,7,8};
    /*printf("Enter number of elements  in array = ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elemnt of array in sequential manner : ");
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }*/
    select(arr,n);
}
