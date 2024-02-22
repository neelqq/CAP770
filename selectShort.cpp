#include<iostream>
using namespace std;

void selectShort(int arr[],int n)
{
    int c;
    for(int i=0;i<n;i++){
        c=i;
        for(int j=i+1;j<n;j++){
            if(arr[c]>arr[j]){
                c=j;
            }
        }
        swap(arr[i],arr[c]);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[100],n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selectShort(arr,n);
    display(arr,n);

}