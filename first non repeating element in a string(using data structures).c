#include <stdio.h>
#include <stdlib.h>
struct duble
{
    int count;
    int index;
};
struct duble *create_duble(int a, int b)
{
    struct duble *temp=NULL;
    temp=(struct duble *)malloc(sizeof(struct duble));
    temp->count=a;
    temp->index=b;
    return temp;
}
int main() {
	int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);//read the question carefully, its the standard format
        char str[n+1];// very important: one extra element to store the null character /0, it is necessary for many string functionalities
                      //also presence of a null character makes it different from a char array
        scanf("%s",str);
        int flag=-1;
        int min=99999;
        struct duble *arr[26];
        for(int i=0; i<26; i++)
        {
            arr[i]=create_duble(0,0);
        }
        for(int i=0; i<n; i++)
        {
            int t=str[i];
            arr[t-'a']->count++;
            arr[t-'a']->index=i;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]->count==1)
            {
                if(min>arr[i]->index) 
                {
                    min=arr[i]->index;
                    flag=1;
                }
            }

        }
        if(flag==-1) printf("%d \n",flag);// remember the flag concept
        else printf("%c \n",str[min]);
    }   
	return 0;
}//one way to find the first non repeating character is to assign every value to -1 and to update only when its -1 by the index, if we find a positive number(that is the index) then update by -2 , the ones with the value -2 will not be updated 



