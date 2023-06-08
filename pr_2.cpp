#include<iostream>
#include<string>
using namespace std;
class ADT
{
    int arr[10],n;
    
    public:
    ADT()
    {
        for(int i=0;i<10;i++)
        {
            arr[i] = 0;
            n=0;
        }
    }
    void add(int e)
    {
        if(n<10)
        {
            arr[n] = e;
            n++;
        }
        else
        {
            cout<<"\nSet is full.";
        }
                        
           
    }
    void remove(int e)
    {
        int i,flag=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==e)
            {
                flag=1;
                break;
            }
        } 
        if(flag==1)
        {
            for(int j=i;j<n;j++)
            {
                arr[j] = arr[j+1];
            }
            arr[n] = 0;
            n--;
        }
        else
        {
            cout<<"\nData not found";
        }
    }
    int contains(int e)
    {
        int i,flag=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==e)
            {
                flag=1;
                break;
            }
        } 
        if(flag==1)
        {
            return 1;
        }
        else
        {
            cout<<"\nData not found";
            return 0;
        }
    }
    int size()
    {
        int i;
        for(i=0;i<10;i++)
        {
            if(arr[i]==0)
            {
                break;
            }
        }
        return i;
    }
    void unionn(ADT e)
    {
        int j=0;
        int i=0,flag=0;
        for(i=n;j<e.n;i++)
        {
            for(int k=0;k<n;k++)
            {
                if(arr[k] == e.arr[j])
                {
                    flag=1;
                }                
            }
            if(flag==0)
            {
                arr[i] = e.arr[j];
                n++;
            }
            
            j++;
            
        }
        
    }
    void intersection(ADT e)
    {
        int temp[10];int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<e.n;j++)
            {
                if(arr[i] == e.arr[j])
                {
                    temp[k] = arr[i];
                    k++;
                }
            }
        }
        int i;
        for(i=0;i<k;i++)
        {
            arr[i] = temp[i];
            if(temp[i]==0)
            {
                break;
            }
        }
        n=k;
        while(i<n)
        {
            arr[i] =0;
            i++;
        }
    }
    void display()
    {
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

};
int main()
{
    ADT a,b;
    a.add(23);
    a.add(45);
    a.add(67);
    b.add(102);
    b.add(103);
    b.add(23);
    a.display();
    b.display();
    a.unionn(b);
    // a.intersection(b);
    a.display();
    return 0;
}