#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class Student
{
    string address;
    char div;
    int rollNO;
    public:
    string name;
    int exist;
    Student()
    {
       name="";
       rollNO=0;
       div='0';
       address="";
       exist=0;
    }
    void create()
    {
        cout<<"\nEnter name of student: ";
        cin>>name;
        cout<<"\nEnter Roll No of student: ";
        cin>>rollNO;
        cout<<"\nEnter Division: ";
        cin>>div;
        cout<<"\nEnter Address: ";
        cin>>address;
        exist = 1;
    }
    void display()
    {
        cout<<"\nName: "<<name;
        cout<<"\nRoll NO: "<<rollNO;
        cout<<"\nDivision: "<<div;
        cout<<"\nAddress: "<<address; 
    }
    
};

int main()
{
    fstream myfile,tempf;
    
    int ch,n=0,flag,t=0,tp=0;
    Student s[10],temp;
    string name,nam;
    do
    {
        cout<<"\n1->Insert\n2->Display\n3->Delete\n4->Find";
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
                    myfile.open("stud.txt",ios::app);
                    myfile.seekp(0,ios::end);
                    cout<<"\n\t\t Pointer: "<<myfile.tellp();
                    cout<<"\nEnter total No of students: ";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        s[i].create();
                        myfile.write((char*)&s[i],sizeof(s[i]));
                        
                    }
                    myfile.close();
                    break;
            case 2:
                    t=0;
                    myfile.open("stud.txt",ios::in);
                    myfile.seekg(0,ios::beg);
                    while(!myfile.eof() )
                    {
                        myfile.read((char*)&temp,sizeof(temp));
                        if(temp.exist==1)
                        {
                            temp.display();
                        }
                        t++;
                        if(t>=n)
                            break;
                        cout<<"\n\n";
                        
                    }
                    
                    myfile.close();
                    break;
            case 3:
                    myfile.open("stud.txt",ios::in);
                    
                    tempf.open("temp.txt",ios::out);
                    cout<<"\nEnter name of student you want to delete: ";
                    cin>>name;
                    myfile.seekg(0);
                    while(!myfile.eof())
                    {
                        myfile.read((char*)&temp,sizeof(temp));
                        if(name == temp.name)
                        {
                            flag =1;
                            break;
                        }
                        tempf.write((char*)&temp,sizeof(temp));
                    }
                    if(flag ==1)
                    {
                        cout<<"\n Deleted";
                        while(!myfile)
                        {
                            myfile.read((char*)&temp,sizeof(temp));
                            tempf.write((char*)&temp,sizeof(temp));
                        }
                        myfile.close();
                        tempf.close();
                        if(remove("stud.txt")==0)
                        {
                            cout<<"\nSucced";
                        }
                        if(rename("temp.txt","stud.txt")==0)
                        {
                            cout<<"\nSucced";
                        }
                        
                        // myfile.open("stud.txt",ios::out);
                        // tempf.open("temp.txt",ios::in);
                        // while (!tempf.eof())
                        // {
                        //     tempf.read((char*)&temp,sizeof(temp));
                        //     myfile.write((char*)&temp,sizeof(temp));
                        // }
                        // myfile.close();
                        // remove("temp.txt");
                        
                    }
                    else
                    {
                        cout<<"\nNot found";
                    }
                    myfile.close();
                    break;
            case 4:
                    myfile.open("stud.txt",ios::in);
                    cout<<"\nEnter name of student you want to search: ";
                    cin>>nam;
                    myfile.seekg(0);
                    while(!myfile.eof())
                    {
                        myfile.read((char*)&temp,sizeof(temp));
                        if(nam == temp.name)
                        {
                            flag =1;
                            break;
                        }
                    }
                    if(flag ==1)
                    {
                        cout<<"\nFound";
                        temp.display();
                    }
                    else
                    {
                        cout<<"\nNot found";
                    }
                    myfile.close();
                    break;
            case 5:
                    exit;
                    break;
            default:
                cout<<"\nEnter valid choice..";
        }
        cout<<"\nDo you want to continue(0/1): ";
        cin>>ch;
    }while(ch!=0);

    myfile.close();
    return 0;
}