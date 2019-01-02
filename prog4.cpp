#include<iostream>
using namespace std;
#include<cmath>
double findArea(int,int,int);
void swap(int*,int*);
void swap1(double*,double*);
int main()
{
    int n=0;
    cout<<"Enter the number of triamgles\n";
    cin>>n;
    int a[n],b[n],c[n];
    cout<<"Enter the sides of the triangle\n";
    for(int i=0;i<n;i++)
    cin>>a[i]>>b[i]>>c[i];
    double area[n];
    for(int i=0;i<n;i++)
    area[i]=findArea(a[i],b[i],c[i]);
    for(int i=0;i<n;i++)
    for(int j=0;j<n-1-i;j++)
    {
        if(area[j]>area[j+1])
        {
            swap1(&area[j],&area[j+1]);
            swap(&a[j],&a[j+1]);
            swap(&b[j],&b[j+1]);
            swap(&c[j],&c[j+1]);
        }
    }
    cout<<"In the order of areas:\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    return 0;
}
void swap(int* n1,int* n2)
{
    *n1=*n1+*n2;
    *n2=*n1-*n2;
    *n1=*n1-*n2;
}
void swap1(double* n1,double* n2)
{
    *n1=*n1+*n2;
    *n2=*n1-*n2;
    *n1=*n1-*n2;
}
double findArea(int a,int b,int c)
{
    float p=(a+b+c)/2;
    double area=sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}