nclude <stdio.h>
#include <limits.h>//to use INT_MAX and INT_MIN
void print_array(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);//space after each number
    }
    printf("\n"); //remember to print a new line
}
void scan_array(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
}

int Merge_CountCrossInversions(int a[], int low, int mid, int high)
{
    int n1=mid-low+1;
    int left[n1+1];
    for(int i=0; i<n1; i++)
    {
        left[i]=a[i+low];
    }
    left[n1]=INT_MAX;
    int n2=high-mid;
    int right[n2+1];
    for(int i=0; i<n2; i++)
    {
        right[i]=a[i+mid+1];
    }
    right[n2]=INT_MAX;
    int l=0;
    int r=0;
    int invcount=0;//counting inversions for each number
    int overall_invcount=0;
    for(int i=low; i<=high; i++)
    {
        if(left[l]<=right[r])
        {
            a[i]=left[l];
            overall_invcount=overall_invcount+invcount;// for each number we will get its inversion by inv_count, but for each number smaller than that number also, these inversions will be true therefore overall_invcount is used
            l++;            //sentinel will not create problems, right sentinel reached : no problem, not even inv_count will be updated, left sentinel reached : inv-count will keep on increasing but overall_incount will not be increased
        }
        else
        {
            a[i]=right[r];
            invcount=invcount+1;
            r++;
        }
    }
    return overall_invcount;
}
int MergeSort_CountInversions(int a[], int low, int high)
{
    if(low>high) return 0;
    if(low==high) return 0;
    int mid=(low+high)/2;
    int x=MergeSort_CountInversions(a,low,mid);
    int y=MergeSort_CountInversions(a,mid+1,high);
    int z=Merge_CountCrossInversions(a,low,mid,high);
    return x+y+z;
}
int main() {
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);//read the question carefully, its the standard format
        int a[n];
        scan_array(a,n);
        int ans=MergeSort_CountInversions(a,0,n-1);
        printf("%d \n",ans);
    }
    return 0;
}

