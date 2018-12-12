#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the pattern\n";
    cin>>n;
    bool halfDone1=false;
    bool halfDone2=false;
    for(int i=n;i<=n;)
    {
        halfDone2=false;
        for(int j=n;j<=n;)
        {
            if(j>=i)
            cout<<j;
            else
            cout<<i;
            if(j==1)
            halfDone2=true;
            if(halfDone2==false)
            j--;
            else
            j++;
        }
        cout<<endl;
        if(i==1)
        halfDone1=true;
        if(halfDone1==false)
        i--;
        else
        i++;
    }
    return 0;
}
