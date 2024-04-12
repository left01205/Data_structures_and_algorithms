#include <stdio.h>
int bin_search(int arr[],int l,int h,int k)
{
  int mid;
  int t=0;
  while(l<=h)
    {
      mid =(l+h)/2;
      if (arr[mid] == k)
      {
        printf("%d is present at %d ",k,mid);
        t+=1;
      }
      else if (k< arr[mid])
      {
        h=mid-1;
      }
      else
      {
        l=mid+1;
      }
    }
  if (t==0)
  {
    printf("Element not present");
  }
}

int main()
{
  int n;
  printf("Enter number of elements in array");
  scanf("%d",&n);
  int arr[n];
  printf("Enter elements : ")
  for (int i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  int t;
  printf("Enter target element = ");
  scanf("%d,&t);
  l=0;
  h=n-1;
  bin_search(arr[n],l,h,key); 
}
