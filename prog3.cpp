#include <iostream>
using namespace std;
int compare(char,char);
int next_permutation(int,char**);
void sort(char**,int);
int main()
{
    int n=0;
    cout<<"Enter the number of string s\n";
    cin>>n;
    char arr[n][10] ;
    char* a[n];
    cout<<"Enter the strings\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        a[i]=arr[i];
    }
    int flag=1;
    while(flag==1)
    {
        cout<<flag;
        flag=next_permutation(n,a);
        cout<<flag;
        cout<<endl;
    }
    return 0;
}
int compare(const char*a,const char*b)
{
    int i=0;
    while(*(a+i)!='\0'&&*(b+i)!='\0')//till the end of a string is reached
    {
        if(*(a+i)==*(b+i))//checks whether equal
        i++;
        else
        break;
    }
    return ((int)*(a+i)-(int)*(b+i));//the difference in their ASCII values is returned
}
int next_permutation(int n,char **s)
{
    cout<<"here";
    int i=0;
    int j=0;
    int min=0;
    char* temp;
    for(i=n-1;i>0;i++)
    if(compare(*(s+i-1),*(s+i))>0)
    break;
    if(i==0)
    return 0;
    else
    {
        min=i+1;
        for(j=i+2;j<n;j++)
        {
            if(compare(*(s+j),*(s+i))>0&&compare(*(s+j),*(s+min))<0)
            min=j;
        }
        temp=*(s+min);
        *(s+min)=*(s+i);
        *(s+i)=temp;
        sort(s+i+1,n-1-i);
        for(i=0;i<n;i++)
        {
            for(j=0;*(*(s+i)+j)!='\0';j++)
            cout<<*(*(s+i)+j);
            cout<<"\t";
        }
    }
    return 1;
}
void sort(char** arr,int len)
{
    char* temp;
    for(int i=0;i<len;i++)
    for(int j=0;j<len-1-i;j++)
    {
        if(compare(*(arr+j),*(arr+j+1))>0)
        {
            temp=*(arr+j);
            *(arr+j)=*(arr+j+1);
            *(arr+j+1)=temp;
        }
    }
}