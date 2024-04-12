# include <stdio.h>
int linear_search(int arr[],int n,int t)
{
  for (int i=0;i<n;i++)
    {
      if (arr[i]==t)
        return -1;
      
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
  res = linear_search(arr,n,t);
  if (res==1)
    {
      printf("Element Found");
    }
 else{
   printf("Element not found");
 }
}
