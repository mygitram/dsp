#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest =i;
    int l = (largest*2)+1;
    int r = (largest*2)+2;

    if(l<n && arr[largest]<arr[l])
    {
        largest = l;
    } 
    if(r<n && arr[largest]<arr[r])
    {
        largest = r;
    }
    if(largest!=i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
    }
}
void heapSort(int arr[],int n)
{   
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);

    }
}
void display(int arr[],int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {15,5,20,1,17,10,30};
    int n = sizeof(arr)/ sizeof(arr[0]);
    display(arr,n);
    heapSort(arr,n);
    cout<<"\nSorted array is: ";
    display(arr,n);
    return 0;
}