#include<cstring>
#include <iostream>
using namespace std;
int numOfDistChars(char*);
int lexicographic_sort(const char*a,const char*b)
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
int lexicographic_sort_reverse(const char*a,const char*b)
{
    int i=0;
    while(*(a+i)!='\0'&&*(b+i)!='\0')//till the end of a string is reached
    {
        if(*(a+i)==*(b+i))//checks whether equal
        i++;
        else
        break;
    }
    return ((int)*(b+i)-(int)*(a+i));//the difference in their ASCII values is returned
}
int sort_by_length(const char*a,const char*b)
{
    int l1,l2=1;
    while(*(a+l1)!='\0')//till the end of the string
    l1++;//counts the number of characters
    while(*(b+l2)!='\0')//till the end of the string
    l2++;//counts the number of characters
    return (l1-l2);    
}
int sort_by_number_of_distinct_characters(const char*a,const char*b)
{
    int num1=0;
    int i,j=0;
    while(*(a+i)!='\0')
    {
        for(j=0;j<i;j++)
        if(*(a+i)==*(a+j))
        break;
        if(i==j)
        num1++;
        i++;
    }
    int num2=0;
    i=0;
    j=0;
    while(*(b+i)!='\0')
    {
        for(j=0;j<i;j++)
        if(*(b+i)==*(b+j))
        break;
        if(i==j)
        num2++;
        i++;
    }
    return num1-num2;
}
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    char* temp;
    for(int i=0;i<len;i++)
    for(int j=0;j<len-1-i;j++)
    {
        int result=cmp_func(*(arr+j),*(arr+j+1));
        if(result==0)
        {
            if(lexicographic_sort(*(arr+j),*(arr+j+1))>0)
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
        else if(result>0)
        {
            temp=*(arr+j);
            *(arr+j)=*(arr+j+1);
            *(arr+j+1)=temp;
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=0;*(*(arr+i)+j)!='\0';j++)
        cout<<*(*(arr+i)+j);
    cout<<endl;
    }
}
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
    cout<<endl;
    string_sort(a,n,&lexicographic_sort);
    cout<<endl;
    string_sort(a,n,&lexicographic_sort_reverse);
    cout<<endl;
    string_sort(a,n,&sort_by_number_of_distinct_characters);
    cout<<endl;
    string_sort(a,n,&sort_by_length);
    return 0;
}