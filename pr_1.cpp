#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 10
struct Table
{
    long int telNO;
    string name;
};

Table data[SIZE];

int HashCode(string nm)
{
    int h=0;
    for(int i=0;nm[i]!='\0';i++)
    {
        h=h+nm[i];
    }
    return (h%SIZE);
}
void init()
{
    for(int i=0;i<SIZE;i++)
    {
        data[i].telNO=0;
        data[i].name="0";
    }
}
void insertlinear(string nam,long int tno)
{
    int t=HashCode(nam);
    
    for(int i=t;i<SIZE;i++)
    {
        if(data[i].name,"0")
        {
            data[i].telNO = tno;
            data[i].name=nam;
            cout<<"\nData inserted..";
            break;
        }
    }
}
void insertquadratic(string nam,long int tno)
{
    int t=HashCode(nam);
    int j=0,flag=0;
    for(int i=t;i<SIZE;i++)
    {
        if(data[i].name=="0")
        {
            data[i].telNO = tno;
            data[i].name=nam;
            cout<<"\nData inserted..";
            flag =1;
            break;
        }
        
        i = i + (j*j); 
        i = i%SIZE;
        j++;
    }
    if(flag==0)
    {
       cout<<"\nData cant insert.."; 
    }
}
void search(char nam[])
{
    int flag=0,t=HashCode(nam);
    for(int i=t;i<SIZE;i++)
    {
        if(data[i].name==nam)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"\n"<<nam<<" found";
    }
    else
    {
        cout<<"\n"<<nam<<" not found";
    }
}
void deletee(string nam)
{
    int flag=0,i,
    h=HashCode(nam);

    for(i=h;i<SIZE;i++)
    {
        if(data[i].name==nam)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\n"<<data[i].name<<" Element is deleted";
        data[i].telNO=0;
        data[i].name="0";
    }
    else
    {
        cout<<"\n"<<nam<<" not available in hash table";
    }
}
void update(char nam[],int tno)
{
    int flag=0,t=HashCode(nam);
    for(int i=t;i<SIZE;i++)
    {
        if(data[i].name==nam)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        data[t].telNO=tno;
        cout<<"\nMob no updated... ";
    }
    else
    {
        cout<<"\n"<<nam<<" not found";
    }
}
void display()
{
    cout<<"\n\nName   .\t\tTelephone Number No\n";
    for(int i=0;i<SIZE;i++)
    {
        cout<<"\n"<<data[i].name<<"\t\t"<<data[i].telNO;
    }
}
int main()
{
    char ch;
    int cch;
    long int mno;
    char dat[20];
    init();
    do{
        cout<<"\n\n\n1--> Insert Data Linear";
        cout<<"\n2--> Insert Data Qudrartic";
        cout<<"\n3--> Search Data";
        cout<<"\n4--> Delete Data";
        cout<<"\n5--> Display Data";
        cout<<"\n6--> Update Data";
        cout<<"\n7--> Exit";
        cout<<"\nEnter your choice: ";
        cin>>cch;
        switch(cch)
        {
            case 1:
                cout<<"\nEnter Name: ";
                cin>>dat;
                cout<<"\nEnter mobile no: ";
                cin>>mno;
                insertlinear(dat,mno); 
                break;
            case 2:
                cout<<"\nEnter Name: ";
                cin>>dat;
                cout<<"\nEnter mobile no: ";
                cin>>mno;
                insertquadratic(dat,mno); 
                break;
            case 3:
                cout<<"\n Enter data you want to search: ";
                cin>>dat;
                search(dat);
                break;
            case 4: 
                cout<<"\n Enter data you want to delete: ";
                cin>>dat;
                deletee(dat);
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"\nEnter name and number you want to update: ";
                cin>>dat>>mno;

                update(dat,mno);
                break;
            case 7:
                return 0;
            default:
                cout<<"\nPlease enter valid choice..";
        }
    }while(cch!=6);

    return 0;
}

