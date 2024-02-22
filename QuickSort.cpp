#include<iostream>
using namespace std;
int setPart(int arr[],int start,int end)
{
    int privot=arr[end];
    int pog=start-1;
    for(int i=start;i<=end;i++){
        if(privot>arr[i]){
            pog++;
            swap(arr[i],arr[pog]);
        }
    }
    swap(arr[pog+1],arr[end]);
    return pog+1;
}
void quickShortFun(int arr[],int start,int end)
{
    if(start<=end){
        int privotIndex=setPart(arr,start,end);
        quickShortFun(arr,start,privotIndex-1);
        quickShortFun(arr,privotIndex+1,end);
    }
}
int main(){
    int arr[100],n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    quickShortFun(arr,0,n-1);
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}