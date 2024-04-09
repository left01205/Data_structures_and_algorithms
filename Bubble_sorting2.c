
#include <stdio.h>
int bubble_sort(int arr[],int n )
{
    int t;
    
    for (int i=0;i<n-1;i++)
    {
        for (int j =0;j<n-1-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                
            }
        
        }
    }
    printf("Elements after being bubble sorted : ");
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    
    }

}
int main() {
    // Intitalising array 
    int n;
    printf("Enter number of elements  in array = ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elemnt of array in sequential manner : ");
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
}
