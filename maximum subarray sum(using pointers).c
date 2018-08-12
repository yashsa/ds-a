#include <stdio.h>//utilise the functions properly
#include<stdlib.h>
struct tuple
{
    int sum;
    int left;
    int right;
};
void print_array(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);//space after each number
    }
    printf("\n"); //remember to print a new line
}
void print_subarray(int a[], int low, int high)
{
    for(int i=low; i<=high; i++)
    {
        printf("%d ",a[i]);//sapce after each number
    } 
    printf("\n");//remeber to print a new line
}
int subarray_sum(int a[], int low, int high)
{
    int sum=0;
    for(int i=low; i<=high; i++)//use <= not =<
    {
        sum=sum+a[i];
    }
    return sum;
}
void scan_array(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
}
struct tuple * create_tuple(int a, int b, int c)
{
   struct tuple *temp=NULL;
   temp=(struct tuple *)malloc(sizeof(struct tuple));
   temp->sum=a;
   temp->left=b;
   temp->right=c;
   return temp;
}
struct tuple *max_sum(struct tuple *a, struct tuple *b, struct tuple *c)
{
    int x=a->sum;
    int y=b->sum;
    int z=c->sum;
    if(x>=y&&x>=z) return a;
    if(y>=x&&y>=z) return b;
    else return c;
}
struct tuple *max_crosssum(int a[], int low, int mid, int high)
{
    int sum=0;
    int l=mid, r=mid+1;
    int left_sum=-99999;
    for(int i=mid; i>=low; i--)
    {
        sum=sum+a[i];//beware of making silly mistakes
        if(left_sum<sum)
        {
            left_sum=sum;
            l=i;
        }
    }
     sum=0;//don't redefine sum , rather initialise it zero
    int right_sum=-99999;
    for(int i=mid+1; i<=high; i++)//don't blindly copy code
    {
        sum=sum+a[i];
        if(right_sum<sum)
        {
            right_sum=sum;
            r=i;
        }
    }
    int s=left_sum+right_sum;
    struct tuple* crosssum=create_tuple(s, l, r);
    return crosssum;
}
struct tuple* max_contiogus_sum(int a[], int low, int high)//the function will return max max contiogus sum and also the low and high indices
{//sorry for the spelling mistake 
    if(low>high) 
    {
        struct tuple *error=NULL;
        error=create_tuple(-1,-1,-1);
        return error;
    }
    if (low==high)
    {
        struct tuple *temp=NULL;
        temp=create_tuple(a[low],low,low);
        return temp;
    }
    int mid=(low+high)/2;
    struct tuple *first=max_contiogus_sum(a,low,mid);
    struct tuple *second=max_contiogus_sum(a,mid+1,high);
    struct tuple *third=max_crosssum(a,low,mid,high);
    return max_sum(first, second, third);
}
int main() {
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);//read the question carefully, its the standard format
        int a[n];
        scan_array(a,n);
        struct tuple *head=max_contiogus_sum(a,0,n-1);
        int s=head->sum;
        int l=head->left;
        int r=head->right;
        int ss=subarray_sum(a,l,r);
        printf("%d\n",ss);
        //print_subarray(a,l,r);
    }
	return 0;
}


