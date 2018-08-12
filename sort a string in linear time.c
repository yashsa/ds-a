#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sort_a_string(char str[])
{
    int length=strlen(str);//remeber to inculde string.h
    int count['z'-'a'+1];
    for(int i='a'; i<='z'; i++)
        {
            count[i-'a']=0;
        }
    for(int i=0; i<length; i++)
        {
            int t=str[i];
            count[t-'a']=count[t-'a']+1;
        }
    int w=0;
    int j;
    for(int i=0; i<26; i++)
        {
            for(j=w; j<w+count[i]; j++)
            {
                str[j]=i+'a';
            }
            w=j;//these types of pointers are very useful
        }
}
void print_string(char str[])
{
    printf("%s\n",str);
}
int main() {
	
        char str[1000000];
        scanf("%s",str);
        sort_a_string(str);
        print_string(str);
	return 0;
}



