#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int n1=m-l+1;//n1 is the number of elements in the left subarray
    int left[n1+1];//creating an extra box for sentinel
    for(int i=0; i<n1;i++)
    {
        left[i]=arr[i+l];//copying the n1 elements in the left array
    }
    left[n1]=999999;//sentinel subguarding
    int n2=r-m;//n2 is the number of elements in the right subarray
    int right[n2+1];//one extra box for sentinel
    for(int i=0; i<n2;i++)
    {
        right[i]=arr[m+i+1];//copying the n2 elements in the right subarray
    }
    right[n2]=999999;//sentinel subguarding
    int left_pointer=0; int right_pointer=0;
    for(int k=l; k<=r; k++)//k starts from l and goes to r
    {
        if(left[left_pointer]<right[right_pointer])
        {
            arr[k]=left[left_pointer];
            left_pointer++;
        }
        else
        {
            arr[k]=right[right_pointer];
            right_pointer++;
        }
    }
    
}
void mergesort(int arr[], int l, int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main() {
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
	{
	    scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	for(int i=0; i<n; i++)
	{
	    printf("%d ",a[i]);
	}
	return 0;
}


