#include<iostream>
using namespace std;
int BinarySearch(int arr[],int start,int end,int findNum)
{
    int mid;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]==findNum)
        {
            return mid;
        }
        if(arr[mid]>findNum)
        {
            end=mid-1;
        }
        if(arr[mid]<findNum)
        {
            start=mid+1;
        }
    }
    return -1;
}
int main(){
     int arr[100],n,find;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    cout<<"enter the number which you find"<<endl;
    cin>>find;
    int flag=BinarySearch(arr,0,n-1,find);
    if(flag==-1)
    {
        cout<<"number is not under the array"<<endl;
    }
    else{
        cout<<"the number's index is "<<flag;
    }
}