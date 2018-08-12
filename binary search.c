#include <stdio.h>
int binary_search(int a[],int x, int left, int right)
{
    if(left>right){return 0;}
    int mid= (left+right)/2;
    if(x==a[mid]){return 1;}
    else if(x<a[mid]){return binary_search(a,x,left,mid-1);}
    else {return binary_search(a,x,mid+1,right);}
}
int main() {
	int n;
	int x;
	scanf("%d\n%d",&n,&x);
//	scanf("%d",&x);
	int a[n];
	
	for(int i=0; i<n; i++)
	{
	    scanf("%d",&a[i]);
	}
	
	int ans=binary_search(a,x,0,n-1);
	printf("%d",ans);
	return 0;
}


